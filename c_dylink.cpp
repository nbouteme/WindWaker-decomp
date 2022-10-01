#include "c_dylink.h"

#include <stdio.h>

DynamicModuleControlBase *DynamicModuleControlBase::mFirst;
DynamicModuleControlBase *DynamicModuleControlBase::mLast;

void DynamicModuleControlBase::dump() {
}

char *DynamicModuleControlBase::getModuleName() { return nullptr; }
uint DynamicModuleControlBase::getModuleSize() { return 0; }
char *DynamicModuleControlBase::getModuleTypeString() { return "Base"; }
void DynamicModuleControlBase::dump2() {}
int DynamicModuleControlBase::do_load() { return 1; }

DynamicModuleControlBase::DynamicModuleControlBase() {
	this->mLinkCount = 0;
	this->field1_0x2 = 0;
	this->prev = nullptr;
	if (DynamicModuleControlBase::mFirst == nullptr) {
		DynamicModuleControlBase::mFirst = this;
	}
	this->next = DynamicModuleControlBase::mLast;
	if (this->next) {
		this->next->prev = this;
	}
	DynamicModuleControlBase::mLast = this;
}

undefined4 DynamicModuleControlBase::force_unlink() {
	if (this->mLinkCount != 0) {
		this->mLinkCount = 0;
		do_unlink();
	}
	return 1;
}

int DynamicModuleControlBase::load_async() {
	undefined4 uVar1;

	if (this->mLinkCount == 0) {
		return this->do_load_async();
	}
	return 1;
}

int DynamicModuleControlBase::do_load_async() {
	if (this->mLinkCount == 0) {
		return this->do_load_async();
	} else {
		return 1;
	}
}
int DynamicModuleControlBase::do_unload() { return 1; }
int DynamicModuleControlBase::do_link() { return 1; }
int DynamicModuleControlBase::do_unlink() { return 1; }

DynamicModuleControlBase::~DynamicModuleControlBase() {
	force_unlink();
	if (this->next) {
		this->next->prev = this->prev;
	}
	if (this->prev) {
		this->prev->next = this->next;
	}
	if (mFirst == this) {
		mFirst = this->prev;
	}
	if (mLast == this) {
		mLast = this->next;
	}
	this->prev = nullptr;
	this->next = nullptr;
}

int DynamicModuleControlBase::link() {
	os::OSThread *pOVar1;
	int iVar2;
	ulong uVar3;

	pOVar1 = os::OSGetCurrentThread();
	if (pOVar1 != &m_Do_main::mainThread) {
		m_Do_printf::OSReport_Error("DynamicModuleControlBase::link not mainthread %08x\n");
	}
	if (this->mLinkCount == 0) {
		do_load();
		iVar2 = do_link();
		if (iVar2 == 0) {
			return 0;
		}
		if (this->field1_0x2 != 0xffff) {
			this->field1_0x2 = this->field1_0x2 + 1;
		}
	}
	if (this->mLinkCount == 0xffff) {
		JUTAssertion::getSDevice()->showAssert("DynamicLink.cpp", 100, "mLinkCount < 65535");
		m_Do_printf::OSPanic("DynamicLink.cpp", 100, "Halt");
	}
	if (this->mLinkCount != 0xffff) {
		this->mLinkCount = this->mLinkCount + 1;
	}
	return 1;
}

int DynamicModuleControlBase::unlink() {
	os::OSThread *pOVar1;

	pOVar1 = os::OSGetCurrentThread();
	if (pOVar1 != &m_Do_main::mainThread) {
		m_Do_printf::OSReport_Error("DynamicModuleControlBase::unlink not mainthread %08x\n");
	}
	if (this->mLinkCount == 0) {
		m_Do_printf::OSReport_Warning("%08x DynamicModuleControlBase::unlink() mLinkCount id already zero.\n", this);
	} else {
		this->mLinkCount = this->mLinkCount - 1;
		if (this->mLinkCount == 0) {
			do_unlink();
			do_unload();
		}
	}
	return 1;
}

DynamicModuleControl::DynamicModuleControl(char *name) : DynamicModuleControlBase() {
	this->mModule = nullptr;
	this->mpModuleName = name;
	this->mModuleType = Invalid;
	this->mCheckSum = 0;
	this->mDecompSize = 0;
	this->bssPointer = 0;
	this->field3_0x18 = 0;
	this->field6_0x21 = 0;
	this->dvdcallback = 0;
}

char *DynamicModuleControl::getModuleName() { return mpModuleName; }
uint DynamicModuleControl::getModuleSize() {
	int iVar1;

	if (this->mModule == nullptr) {
		iVar1 = 0;
	} else {
		iVar1 = JKRHeap::getSize(this->mModule, nullptr);
		if ((void *)this->bssPointer) {
			JKRHeap::getSize((void *)this->bssPointer, nullptr);
		}
		iVar1 = iVar1 + this->mModule->mBssSize;
	}
	return iVar1;
}
char *DynamicModuleControl::getModuleTypeString() {
	return (char *[]){"????", "MEM", "ARAM", "DVD"}[mModuleType & 3];
}

void DynamicModuleControl::dump2() { /*dont care*/
}
//int DynamicModuleControl::do_load()

namespace DynamicLink {
	int calcSum2(ushort *data, ulong size) {
		int iVar1;

		iVar1 = 0;
		for (; size != 0; size = size - 2) {
			iVar1 = iVar1 + (uint)*data;
			data = data + 1;
		}
		return iVar1;
	}
}

int DynamicModuleControl::do_load() {
	bool bVar1;
	byte bVar2;
	undefined4 uVar3;
	DynamicModule *pDVar4;
	int decompSize;
	short sVar5;
	int iVar6;
	char acStack88[76];

	if (!this->mModule)
		return 1;
	iVar6 = 0;
	do {
		while (true) {
			if (this->mModule) {
				JKRHeap::free(this->mModule, nullptr);
				this->mModule = nullptr;
			}
			snprintf(acStack88, 0x40, "%s.rel", this->mpModuleName);
			if ((this->mModule == nullptr) &&
				(DynamicModuleControl::sArchive)) {	 // MMEM
				this->mModule = (DynamicModule *)JKRArchive::getGlbResource(0x4d4d454d, acStack88, DynamicModuleControl::sArchive);
				if (this->mModule) {
					this->mModuleType = LoadToMainRAM;
				}
				if (this->mModule == nullptr) {	 // AMEM
					this->mModule = (DynamicModule *)JKRArchive::getGlbResource(0x414d454d, acStack88, DynamicModuleControl::sArchive);
					this->mModule = pDVar4;
					if (this->mModule) {
						this->mModuleType = LoadToARAM;
					}
				}
				if (this->mModule == nullptr) {	 // DMEM
					this->mModule = (DynamicModule *)JKRArchive::getGlbResource(0x444d454d, acStack88, DynamicModuleControl::sArchive);
					if (this->mModule) {
						this->mModuleType = LoadToDVDRAM;
					}
				}
			}
			bVar1 = this->mModule == nullptr;
			if (bVar1) {
				if (bVar1) {
					snprintf(acStack88, 0x40, "/rels/%s.rel", this->mpModuleName);
					this->mModule = (DynamicModule *)JKRDvdRipper::loadToMainRAM(acStack88, nullptr, 1, 0, m_Do_ext::archiveHeap, 1, 0, nullptr);
					if (this->mModule) {
						this->mDecompSize = 0;
						this->mModuleType = LoadFromDisk;
					}
				}
				if ((this->mModule == nullptr) && (DynamicModuleControl::sFileCache != 0)) {
					this->mModule = (DynamicModule *)sFileCache->getResource(0x72656c73, acStack88);
					if (this->mModule) {
						this->mDecompSize = 0;
						this->mModuleType = LoadFromCache;
						JKRFileLoader::detachResource(this->mModule, nullptr);
					}
				}
			} else {
				decompSize = sArchive->getExpandedResSize(this->mModule);
				this->mDecompSize = decompSize;
				JKRFileLoader::detachResource(this->mModule, nullptr);
			}
			if (this->mModule == nullptr) {
				m_Do_printf::OSReport_Error("DynamicModuleControl::do_load() リソース読み込み失敗 [%s]\n",
											this->mpModuleName);
				return 0;
			}
			if (this->mDecompSize < 1) {
				if (this->field6_0x21 != 0xff) {
					this->field6_0x21 = this->field6_0x21 + 1;
				}
				return 1;
			}
			sVar5 = DynamicLink::calcSum2((ushort *)this->mModule, this->mDecompSize);
			bVar2 = this->field6_0x21;
			if (bVar2 != 0)
				break;
			this->mCheckSum = sVar5;
			this->field6_0x21 = this->field6_0x21 + 1;
		}
		if (sVar5 == this->mCheckSum) {
			if (bVar2 == 0xff) {
				return 1;
			}
			this->field6_0x21 = bVar2 + 1;
			return 1;
		}
		m_Do_printf::OSReport_Error("DynamicModuleControl::do_load() チェックサムエラー %04x %04x[%s]\n", sVar5, this->mCheckSum, this->mpModuleName);
		this->field6_0x21 = 0;
		iVar6 = iVar6 + 1;
	} while (iVar6 < 3);
	uVar3 = 0;
	return uVar3;
}

void *DynamicModuleControl::callback(void *s) {
	((DynamicModuleControl *)s)->do_load();
	return 0;
}

int DynamicModuleControl::do_load_async() {
	mDoDvdThd_callback_c *pmVar1;
	undefined4 uVar2;

	if (this->dvdcallback == nullptr) {
		if (this->mModule) {
			return 1;
		}
		this->dvdcallback = (mDoDvdThd_callback_c *)
			mDoDvdThd_callback_c::create(DynamicModuleControl::callback, this);
		if (this->dvdcallback == nullptr) {
			m_Do_printf::OSReport_Error("DynamicModuleControl::do_load_async() 非同期読み込みコールバック登録失敗 [%s]\n", this->mpModuleName);
		}
	}
	pmVar1 = this->dvdcallback;
	if ((pmVar1 == nullptr) || (pmVar1->mStatus == 0)) {
		uVar2 = 0;
	} else {
		delete pmVar1;
		this->dvdcallback = nullptr;
		uVar2 = 1;
	}
	return uVar2;
}

int DynamicModuleControl::do_unload() {
	if (this->mModule) {
		JKRHeap::free(this->mModule, nullptr);
		this->mModule = nullptr;
	}
	return 1;
}

int DynamicModuleControl::do_link() {
	ulong uVar1;
	ulong uVar2;
	DynamicModule *rel;
	uint uVar3;
	void *iVar4;
	int iVar5;
	undefined4 uVar6;
	ulong uVar7;
	DynamicModule *rel_00;
	os::OSTime lVar8;

	lVar8 = os::OSGetTime();
	if (this->mModule == nullptr) {
		do_load();
	}
	if (this->mModule != nullptr) {
		if ((DynamicModule__SectionInfo *)0x7fffffff < this->mModule->mpSectionInfoOffset) {
			JUTAssertion::getSDevice()->showAssert("DynamicLink.cpp", 0x265, "mModule->info.sectionInfoOffset < 0x80000000");
			m_Do_printf::OSPanic("DynamicLink.cpp", 0x265, "Halt");
		}
		if (0x81ffffff < (uint)((int)&this->mModule->mModuleID + this->mModule->mFixSize)) {
			JUTAssertion::getSDevice()->showAssert("DynamicLink.cpp", 0x267, "(u32)mModule + mModule->fixSize < 0x82000000");
			m_Do_printf::OSPanic("DynamicLink.cpp", 0x267, "Halt");
		}
		os::OSGetTime();
		os::OSGetTime();
		rel = this->mModule;
		if (rel->mRELFormatVersion < 3) {
			JUTAssertion::getSDevice()->showAssert("DynamicLink.cpp", 0x2d4, "0");
			m_Do_printf::OSPanic("DynamicLink.cpp", 0x2d4, "Halt");
		LAB_80240eb0:
			lVar8 = os::OSGetTime();
			auto iVar4 = getModuleSize();
			DynamicModuleControl::sAllocBytes = DynamicModuleControl::sAllocBytes + iVar4;
			lVar8 = os::OSGetTime();
			this->field3_0x18 = ((int (*)(DynamicModule *))this->mModule->mpProlog)(this->mModule);
			os::OSGetTime();
			return 1;
		}
		uVar2 = rel->mFixSize;
		uVar1 = uVar2 + 0x1f & 0xffffffe0;
		iVar4 = (void *)(&rel->mModuleID + uVar1);
		uVar3 = JKRHeap::getSize(rel, nullptr);
		if ((int)uVar3 < 0) {
			iVar4 = JKRHeap::alloc(this->mModule->mBssSize, 0x20, nullptr);
			if (iVar4 == 0) {
				m_Do_printf::OSReport_Error("BSSメモリ確保失敗\n");
			} else {
				this->bssPointer = iVar4;
				auto iVar4 = os::OSLink((os::OSModuleInfo *)&this->mModule, this->bssPointer);
				if (iVar4 != 0)
					goto LAB_80240eb0;
				m_Do_printf::OSReport_Error("リンク失敗\n");
			}
		} else {
			rel_00 = this->mModule;
			uVar7 = uVar1 + rel_00->mBssSize;
			if (uVar7 < uVar3) {
				auto r = os::OSLinkFixed((os::OSModuleInfo *)rel_00, iVar4);
				if (r != 0) {
					r = JKRHeap::resize(this->mModule, uVar1 + this->mModule->mBssSize, nullptr);
					if (r < 0) {
						m_Do_printf::OSReport_Error("モジュールリサイズ(縮小)失敗\n");
					}
					goto LAB_80240eb0;
				}
				m_Do_printf::OSReport_Error("リンク失敗\n");
			} else {
				iVar5 = JKRHeap::resize(rel_00, uVar7, nullptr);
				if (iVar5 < 1) {
					iVar4 = JKRHeap::alloc(this->mModule->mBssSize, 0x20, nullptr);
					if (iVar4 == 0) {
						m_Do_printf::OSReport_Error("BSSメモリ確保失敗 [%x]\n", this->mModule->mBssSize);
					} else {
						auto iVar4 = os::OSLinkFixed((os::OSModuleInfo *)&this->mModule, this->bssPointer);
						if (iVar4 != 0) {
							iVar4 = JKRHeap::resize(this->mModule, uVar2, nullptr);
							if (iVar4 < 0) {
								m_Do_printf::OSReport_Error("モジュールリサイズ(縮小)失敗\n");
							}
							goto LAB_80240eb0;
						}
						m_Do_printf::OSReport_Error("リンク失敗\n");
					}
				} else {
					auto r = os::OSLinkFixed((os::OSModuleInfo *)&this->mModule, iVar4);
					if (r != 0)
						goto LAB_80240eb0;
					m_Do_printf::OSReport_Error("リンク失敗\n");
				}
			}
		}
	}
	this->field6_0x21 = 0;
	if ((void *)this->bssPointer != nullptr) {
		JKRHeap::free((void *)this->bssPointer, nullptr);
		this->bssPointer = 0;
	}
	if (this->mModule != nullptr) {
		JKRHeap::free(this->mModule, nullptr);
		this->mModule = nullptr;
	}
	return 0;
}

int DynamicModuleControl::do_unlink() {
	int iVar1;
	undefined4 uVar2;
	os::OSTime lVar3;

	lVar3 = os::OSGetTime();
	((void (*)(DynamicModule *))this->mModule->mpEpilog)(this->mModule);
	lVar3 = os::OSGetTime();
	iVar1 = os::OSUnlink(&((os::OSModuleHeader *)this->mModule)->info);
	lVar3 = os::OSGetTime();
	if (iVar1 == 0) {
		m_Do_printf::OSReport_Error("アンリンク失敗 mModule=%08x mBss=%08x\n", this->mModule, this->bssPointer);
		uVar2 = 0;
	} else {
		iVar1 = getModuleSize();
		DynamicModuleControl::sAllocBytes = DynamicModuleControl::sAllocBytes - iVar1;
		if (this->bssPointer) {
			JKRHeap::free(this->bssPointer, nullptr);
			this->bssPointer = 0;
		}
		do_unload();
		uVar2 = 1;
	}
	return uVar2;
}

JKRFileCache *DynamicModuleControl::sFileCache;
int DynamicModuleControl::sAllocBytes;

JKRArchive *DynamicModuleControl::sArchive;

JKRArchive *DynamicModuleControl::mountCallback(void *param_1) {
	JKRExpHeap *heap;

	heap = m_Do_ext::mDoExt_getArchiveHeap();
	sFileCache = JKRFileCache::mount("/rels", heap, nullptr);
	sArchive = (JKRArchive *)JKRArchive::mount("RELS.arc", 4, heap, 1);
	if (sArchive) {
		m_Do_printf::OSReport_Error("マウント失敗ですが単にアーカイブを作ってないだけなら遅いだけです %s\n", "RELS.arc");
	}
	return sArchive;
}

int DynamicModuleControl::initialize(void) {
	sFileCache = 0;
	sAllocBytes = 0;
	sArchive = nullptr;
	mountCallback(nullptr);
	return 1;
}

namespace c_dylink {
	mDoDvdThd_callback_c *cDyl_DVD;
	byte DMC_initialized;
	DynamicNameTableEntry DynamicNameTable[430];
	DynamicModuleControl *DMC[501];

	undefined4 cCc_Init(void) {
		ulong uVar1;
		JKRExpHeap *pParent;
		JKRSolidHeap *solidheap;
		JKRHeap *regheap;
		char *__s2;
		int iVar2;
		DynamicModuleControl *dmc;
		uint uVar3;
		int iVar4;
		int iVar5;
		DynamicNameTableEntry *puVar6;
		uint uVar7;

		if (DMC_initialized != '\0') {
			JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x2a, "!DMC_initialized");
			m_Do_printf::OSPanic("c_dylink.cpp", 0x2a, "Halt");
		}
		pParent = m_Do_ext::mDoExt_getArchiveHeap();
		solidheap = JKRSolidHeap::create(0x5648, pParent, false);
		regheap = solidheap->becomeCurrentHeap();
		//FUN_800033a8((int)DMC, 0, 0x7d8);
		memset(DMC, 0, 0x7d8);
		uVar7 = 0;
		iVar5 = 0;
		do {
			puVar6 = &DynamicNameTable[iVar5];
			if (puVar6->mRelFilename) {
				if (0x1f5 < puVar6->mPname) {
					JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x39, "d.mKey < (sizeof(DMC) / sizeof(DMC[0]))");
					m_Do_printf::OSPanic("c_dylink.cpp", 0x39, "Halt");
				}
				if (DMC[puVar6->mPname]) {
					JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x3a, "DMC[d.mKey] == 0");
					m_Do_printf::OSPanic("c_dylink.cpp", 0x3a, "Halt");
				}
				uVar3 = 0;
				iVar4 = 0;
				do {
					if (DMC[uVar3]) {
						iVar2 = strcmp(puVar6->mRelFilename, DMC[uVar3]->getModuleName());
						if (iVar2 == 0) {
							DMC[puVar6->mPname] = DMC[uVar3];
							break;
						}
					}
					uVar3 = uVar3 + 1;
					iVar4 = iVar4 + 4;
				} while (uVar3 < 0x1f6);
				if (DMC[puVar6->mPname] == nullptr) {
					dmc = new DynamicModuleControl(DynamicNameTable[iVar5].mRelFilename);
					DMC[puVar6->mPname] = dmc;
				}
			}
			uVar7 = uVar7 + 1;
			iVar5 = iVar5 + 8;
			if (0x1ad < uVar7) {
				solidheap->adjustSize();
				regheap->becomeCurrentHeap();
				DMC_initialized = 1;
				return 1;
			}
		} while (true);
	}

	int cDyl_Initialized;

	void *cDyl_InitCallback(void *) {
		ulong uVar1;
		JKRExpHeap *heap;
		JKRFileLoader *fileloader;
		void *pvVar2;

		if (cDyl_Initialized != 0) {
			JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x12f, "!cDyl_Initialized");
			m_Do_printf::OSPanic("c_dylink.cpp", 0x12f, "Halt");
		}
		heap = m_Do_ext::mDoExt_getArchiveHeap();
		fileloader = (JKRFileLoader *)JKRFileCache::mount("/", heap, nullptr);
		DynamicModuleControl::initialize();
		pvVar2 = (void *)JKRFileLoader::getGlbResource("/dvd/framework.str");
		//JKRFileLoader::detachResource(pvVar2, fileloader);
		fileloader->detachResource(pvVar2);
		fileloader->unmount();
		os::OSSetStringTable(pvVar2);
		DynamicModuleControl DStack56("f_pc_profile_lst");
		DStack56.link();
		cDyl_Initialized = 1;
		return (void *)1;
	}

	void cDyl_InitAsync(void) {
		ulong uVar1;

		cCc_Init();
		if (cDyl_DVD != 0) {
			JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x145, "cDyl_DVD == 0");
			m_Do_printf::OSPanic("c_dylink.cpp", 0x145, "Halt");
		}
		cDyl_DVD = mDoDvdThd_callback_c::create(cDyl_InitCallback, nullptr);
		return;
	}

	int cDyl_Unlink(ushort param_1, char *param_2) {
		ulong uVar1;
		int iVar2;

		if (cDyl_Initialized == 0) {
			// uVar1 = JUTAssertion::getSDevice();
			// JUTAssertion::showAssert(uVar1, "c_dylink.cpp", 0xc5, "cDyl_Initialized");
			m_Do_printf::OSPanic("c_dylink.cpp", 0xc5, "Halt");
		}
		if (0x1f5 < param_1) {
			// uVar1 = JUTAssertion::getSDevice();
			// JUTAssertion::showAssert(uVar1, "c_dylink.cpp", 0xc6, "i_ProfName < (sizeof(DMC) / sizeof(DMC[0]))");
			m_Do_printf::OSPanic("c_dylink.cpp", 0xc6, "Halt");
		}
		if (DMC[(short)param_1] == nullptr) {
			iVar2 = 0;
		} else {
			iVar2 = DMC[(short)param_1]->unlink();
		}
		return iVar2;
	}

	int cDyl_LinkASync(ushort param_1) {
		ulong uVar1;
		undefined4 uVar2;
		int iVar3;
		DynamicModuleControl *dmc;

		if (c_dylink::DMC_initialized == '\0') {
			JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x101, "DMC_initialized");
			m_Do_printf::OSPanic("c_dylink.cpp", 0x101, "Halt");
		}
		if (c_dylink::cDyl_Initialized == 0) {
			uVar2 = 0;
		} else if (param_1 < 0x1f6) {
			if (param_1 >= 0x1f6) {
				JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x111, "i_ProfName < (sizeof(DMC) / sizeof(DMC[0]))");
				m_Do_printf::OSPanic("c_dylink.cpp", 0x111, "Halt");
			}
			dmc = c_dylink::DMC[(short)param_1];
			if (dmc == nullptr) {
				uVar2 = 4;
			} else {
				if (c_dylink::cDyl_Initialized == 0) {
					JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x115, "cDyl_Initialized");
					m_Do_printf::OSPanic("c_dylink.cpp", 0x115, "Halt");
				}
				iVar3 = dmc->load_async();
				if (iVar3 == 0) {
					uVar2 = 0;
				} else {
					iVar3 = dmc->link();
					if (iVar3 == 0) {
						m_Do_printf::OSReport_Error("cDyl_LinkASync: リンクに失敗しました。諦めます\n");
						uVar2 = 5;
					} else {
						uVar2 = 4;
					}
				}
			}
		} else {
			m_Do_printf::OSReport_Error("cDyl_Link i_ProfName=%d\n");
			uVar2 = 5;
		}
		return uVar2;
	}
}