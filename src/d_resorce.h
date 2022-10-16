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

template <typename T>
struct big_endian {
	T internal;

	constexpr operator T() const noexcept {
		if constexpr (sizeof(T) == 2)
			return __builtin_bswap16(internal);
		else if constexpr (sizeof(T) == 4)
			return __builtin_bswap32(internal);
		else if constexpr (sizeof(T) == 8)
			return __builtin_bswap64(internal);
	}
};

struct ResNTABEntry {
	big_endian<ushort> hash, stroffset;
};

struct ResNTAB {
	big_endian<short> mCount;
	ResNTABEntry mEntries[1];  // Flexible Array Meme
};

struct JUTNameTab {
	ResNTAB *mpRes;
	byte *mpStrData;
	short mCount;

	short calcKeyCode(char *param_1) {
		short sVar1;

		sVar1 = 0;
		while (*param_1) {
			sVar1 = *param_1 + sVar1 * 3;
			param_1++;
		}
		return sVar1;
	}

	int getIndex(char *param_1) {
		ulong uVar1;
		short sVar4;
		int iVar3;
		ushort uVar5;

		if (!this->mpRes) {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "JUTNameTab.cpp", 0x65, "mNameTable != 0");
			m_Do_printf::OSPanic("JUTNameTab.cpp", 0x65, "Halt");
		}
		sVar4 = calcKeyCode(param_1);
		uVar5 = 0;
		while (true) {
			auto pRVar2 = &mpRes->mEntries[uVar5];
			if ((ushort)this->mCount <= uVar5) {
				return -1;
			}
			if ((pRVar2->hash == sVar4) &&
				(!strcmp(((char *)mpRes) + pRVar2->stroffset, param_1)))
				break;
			uVar5++;
		}
		return (uint)uVar5;
	}
};

struct J3DTexture;
struct J3DTevBlock;

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
		if ((pJVar10 != (J3DTexture *)0x0) &&
			(nametab = (pModel->mMaterialTable).mpTexNameTab, nametab != (JUTNameTab *)0x0)) {
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
				if (pJVar11 != (J3DTevBlock *)0x0) {
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
						gd::__GDCurrentDL = (undefined1 *)0x0;
					}
				}
			}
		}*/
	}
}

template <typename T>
struct TVec3 {
	T x, y, z;
};

struct J3DTransformInfo {
	TVec3<float> mScale;
	TVec3<short> mRot;
	TVec3<float> mTranslation;
};

struct J3DAnmBase {
	byte mLoopMode;
	short mDuration;
	float mCurrentTime;
	virtual ~J3DAnmBase() {}
};

struct J3DAnmTransform : J3DAnmBase {
	virtual ~J3DAnmTransform() {}
};

struct J3DAnmTransformKey : J3DAnmTransform {
	virtual void calcTransform(float param_1, ushort param_2, J3DTransformInfo *param_3) {
	}

	virtual void getTransform(ushort p1, J3DTransformInfo *p2) {
		calcTransform(mCurrentTime, p1, p2);
	}
	virtual ~J3DAnmTransformKey() {}
};

// TODO: looks unused in regular gameplay, so stub it for now
struct J3DClusterLoader_v15;

namespace J3DClusterLoaderDataBase {
	J3DClusterLoader_v15 *load(void *param_1) {
		// TODO: looks unused in regular gameplay, so stub it for now
		return 0;
	}
}

namespace J3DModelLoaderDataBase {
	J3DModelData *load(void *param_1, uint param_2) {
		return 0;
	}

	J3DModelData *loadBinaryDisplayList(void *, uint) {
	}
}

struct dRes_info_c {
	char mName[14];
	short mRefCount;
	mDoDvdThd_mountArchive_c *mpDvdThdCommand;
	JKRArchive *mpArchive;
	JKRHeap *mpParentHeap, *mpDataHeap;
	void *mpRes;

	int loadResource() {
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

		if (this->mpRes != (undefined *)0x0) {
			JUTAssertion::getSDevice()->showAssert("d_resorce.cpp", 0x25f, "mRes == 0");
			m_Do_printf::OSPanic("d_resorce.cpp", 0x25f, "Halt");
		}
		return -1;
		/*
		iVar11 = this->mpArchive->mpDataHeader->mFileEntryCount;
		puVar3 = (undefined *)new byte[iVar11 << 2];
		this->mpRes = puVar3;
		if (this->mpRes == (undefined *)0x0) {
			m_Do_printf::OSReport_Error("<%s.arc> setRes: res pointer buffer nothing !!\n", this->mName);
			iVar11 = -1;
		} else {
			iVar4 = 0;
			// clear out the allocated mem
			if (0 < iVar11) {
				do {
					*(undefined4 *)(this->mpRes + iVar4) = 0;
					iVar4 = iVar4 + 4;
					iVar11 = iVar11 + -1;
				} while (iVar11 != 0);
			}
			//

			pcVar1 = d_resorce::l_readResType$4166;
			uVar13 = 0;
			do {
				// loads every ressource in l_readResType in that order
				
				pJVar5 = this->mpArchive->getFirstResource(*(uint *)pcVar1);
				while (pJVar5->attribute != '\0') {
					pRes = (void *)JKRArchive::getGlbResource(*(uint *)pcVar1, pJVar5->name, this->mpArchive);
					if (!pRes) {
						m_Do_printf::OSReport_Error("<%s> res == NULL !!\n", pJVar5->name);
					} else {
						uVar2 = *(uint *)pcVar1;
						// - 0x424d0000
						pWhich = uVar2 + 0xbdb30000;  // basically checks if signatures starts with BM
						if (pWhich == 0x4420) {		  // "BMD "
							pRes = (void *)J3DModelLoaderDataBase::load(pRes, 0x51240020);
							if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
								return -1;
							}
							d_resorce::setToonTex((J3DModelData *)pRes);
						} else if (pWhich == 0x444d) {
							J3DModelData *pRes2 = J3DModelLoaderDataBase::load(pRes, 0x51240020);
							if (!pRes2) {
								return -1;
							}
							for (uVar10 = 0; uVar10 < pRes2->mMaterialTable.mMaterialCount;
								 uVar10 = uVar10 + 1) {
								pJVar12 = (pRes2->mMaterialTable).mpMaterials[uVar10];
								pJVar12->change();
								pJVar6 = new J3DMaterialAnm();
								pJVar6->initialize();
								pJVar12->mpMaterialAnm = pJVar6;
							}
							d_resorce::setToonTex(pRes2);
						} else if (pWhich == 0x4443) {
							auto pRes2 = J3DModelLoaderDataBase::load(pRes, 0x51240020);
							if (!pRes) {
								return -1;
							}
							for (uVar10 = 0; uVar10 < pRes2->mMaterialTable.mMaterialCount;
								 uVar10 = uVar10 + 1) {
								pRes2->mMaterialTable[uVar10]->change();
							}
							d_resorce::setToonTex(pRes2);
						} else if (pWhich == 0x4453) {
							auto pRes2 = J3DModelLoaderDataBase::load(pRes, 0x220020);
							if (!pRes) {
								return -1;
							}
							for (uVar10 = 0; uVar10 < pRes2->mMaterialTable.mMaterialCount;
								 uVar10 = uVar10 + 1) {
								pJVar12 = pRes2->mMaterialTable->mMaterials[uVar10];
								pJVar12->change();

								pJVar6 = new J3DMaterialAnm;
								if (!pJVar6) {
									return -1;
								}
								pJVar6->initialize();
								pJVar12->mpMaterialAnm = pJVar6;
							}
							d_resorce::setToonTex(pRes2);
						} else if (uVar2 == 0x42534d44) {
							auto pRes2 = J3DModelLoaderDataBase::load(pRes, 0x1020020);
							if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
								return -1;
							}
							for (uVar10 = 0; uVar10 < pRes2->mMaterialTable.mMaterialCount;
								 uVar10 = uVar10 + 1) {
								pJVar12 = pRes2->mMaterialTable->mMaterials[uVar10];
								pJVar12->change();

								pJVar6 = new J3DMaterialAnm;
								if (!pJVar6) {
									return -1;
								}
								pJVar6->initialize();
								pJVar12->mpMaterialAnm = pJVar6;
							}
							d_resorce::setToonTex(pRes2);
						} else if (uVar2 == 0x42444c20) {
							auto pRes2 = J3DModelLoaderDataBase::loadBinaryDisplayList(pRes, 0x2020);
							if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
								return -1;
							}
							d_resorce::setToonTex(pRes2);
						} else if (uVar2 == 0x42444c4c) {
							auto pRes2 = J3DModelLoaderDataBase::loadBinaryDisplayList(pRes, 0x1020);
							if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
								return -1;
							}
						} else if (uVar2 == 0x42444c4d) {
							auto pRes2 = J3DModelLoaderDataBase::loadBinaryDisplayList(pRes, 0x2020);
							if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
								return -1;
							}
							for (uVar10 = 0; uVar10 < pRes2->mMaterialTable.mMaterialCount;
								 uVar10 = uVar10 + 1) {
								pJVar12 = pRes2->mMaterialTable->mMaterials[uVar10];
								// pJVar12->change(); // forgot to call change here?

								pJVar6 = new J3DMaterialAnm;
								if (!pJVar6) {
									return -1;
								}
								pJVar6->initialize();
								pJVar12->mpMaterialAnm = pJVar6;
							}
							d_resorce::setToonTex(pRes2);
						} else if (uVar2 == 0x42444c49) {
							auto pRes2 = J3DModelLoaderDataBase::loadBinaryDisplayList(pRes, 0x1002020);
							if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
								return -1;
							}
							for (uVar10 = 0; uVar10 < pRes2->mMaterialTable.mMaterialCount;
								 uVar10 = uVar10 + 1) {
								pJVar12 = pRes2->mMaterialTable->mMaterials[uVar10];
								// pJVar12->change(); // forgot to call change here?

								pJVar6 = new J3DMaterialAnm;
								if (!pJVar6) {
									return -1;
								}
								pJVar6->initialize();
								pJVar12->mpMaterialAnm = pJVar6;
							}
							d_resorce::setToonTex(pRes2);
						} else if (uVar2 == 0x42444c43) {
							pRes = (void *)J3DModelLoaderDataBase::loadBinaryDisplayList(pRes, 0x2020);
							if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
								return -1;
							}
							d_resorce::setToonTex((J3DModelData *)pRes);
						} else {
							pvVar8 = (void *)(uVar2 + 0xbdb40000);
							if (pvVar8 == (void *)0x5320) {
								pRes = J3DClusterLoaderDataBase::load(pRes);
								if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
									return -1;
								}
							} else if ((uVar2 == 0x42434b53) || (uVar2 == 0x42434b20)) {
								int pcVar7 = *(int *)((char *)pRes + 0x1c);
								if (pcVar7 == -1) {
									puVar3 = (undefined *)0x0;
								} else {
									puVar3 = (undefined *)((int)(undefined **)pRes + (int)pcVar7);
								}
								pAnm = new mDoExt_transAnmBas(puVar3);
								pAnm->field17_0x2c = puVar3;
								J3DAnmLoaderDataBase::setResource(pAnm, pRes);
								pRes = pAnm;
							} else if ((((uVar2 == 0x42545020) || (uVar2 == 0x42544b20)) || (uVar2 == 0x42504b20)) ||
									   (((uVar2 == 0x42524b20 || (pvVar8 == (void *)0x4b20)) || (uVar2 == 0x42564120)))) {
								pRes = (void *)J3DAnmLoaderDataBase::load(pRes);
								if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
									return -1;
								}
							} else if (pWhich == 0x5420) {
								auto pRes = J3DModelLoaderDataBase::loadMaterialTable(pRes);
								if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
									return -1;
								}
								for (uVar10 = 0; uVar10 < pRes->mMaterialCount; uVar10 = uVar10 + 1) {
									pRes->mMaterials[uVar10]->change();
								}
								d_resorce::setToonTex(pRes);
							} else if (pWhich == 0x544d) {
								auto pRes = J3DModelLoaderDataBase::loadMaterialTable(pRes);
								if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
									return -1;
								}
								for (uVar10 = 0; uVar10 < pRes->mMaterialCount; uVar10 = uVar10 + 1) {
									piVar9 = pRes->mMaterials[uVar10];
									piVar9->change();
									pJVar6 = new J3DMaterialAnm;
									pJVar6->initialize();
									piVar9->mpMaterialAnm = pJVar6;
								}
								d_resorce::setToonTex((J3DMaterialTable *)pRes);
							} else if (uVar2 == 0x445a4220) {
								pRes = cBgS::ConvDzb((cBgD_t *)pRes);
							}
						}
					}
					*(void **)(this->mpRes + pJVar5->entryNum * 4) = pRes;
					pJVar5->findNextFile();
				}
				delete pJVar5;
				uVar13 = uVar13 + 1;
				pcVar1 = (char *)((int)pcVar1 + 4);
			} while (uVar13 < (sizeof(d_resorce::l_readResType$4166) / 4));
			iVar11 = 0;
		}
		return iVar11;
				*/
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

	static int deleteRes(char *pName, dRes_info_c *pResInfoList, int count) {
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

	static uint syncRes(char *param_1, dRes_info_c *param_2, int param_3) {
		dRes_info_c *pInf;
		undefined4 uVar1;

		pInf = dRes_control_c::getResInfo(param_1, param_2, param_3);
		if (pInf == (dRes_info_c *)0x0) {
			m_Do_printf::OSReport_Error("<%s.arc> syncRes: リソース未登録!!\n", param_1);
			uVar1 = 1;
		} else {
			uVar1 = pInf->setRes();
		}
		return uVar1;
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