#pragma once

#include <JFramework/JKernel/JKRFileCache.h>
#include <machine/dolphin/dvd.h>

struct DynamicModuleControlBase {
	static DynamicModuleControlBase *mFirst;
	static DynamicModuleControlBase *mLast;

	ushort mLinkCount, field1_0x2;

	DynamicModuleControlBase *next;
	DynamicModuleControlBase *prev;

	virtual char *getModuleName() { return nullptr; }
	virtual uint getModuleSize() { return 0; }
	virtual char *getModuleTypeString() { return "Base"; }
	virtual void dump() {}
	virtual void dump2() {}
	virtual int do_load() { return 1; }

	static void dump() {
	}

	DynamicModuleControlBase() {
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

	undefined4 force_unlink() {
		if (this->mLinkCount != 0) {
			this->mLinkCount = 0;
			do_unlink();
		}
		return 1;
	}

	virtual int do_load_async() {
		if (this->mLinkCount == 0) {
			return this->do_load_async();
		} else {
			return 1;
		}
	}
	virtual int do_unload() { return 1; }
	virtual int do_link() { return 1; }
	virtual int do_unlink() { return 1; }

	virtual ~DynamicModuleControlBase() {
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

	int link() {
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

	int unlink() {
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
};

struct DynamicNameTableEntry {
	short mPname;
	char *mRelFilename;
};

struct DynamicModule__SectionInfo {
	uint mSectionOffsetAndFlag;
	uint mSectionSize;
};

struct DynamicModule__ImpEntry {
	int mModuleIDToRelocateAgainst;
	int mpRelocations;
};

struct DynamicModule {
	int mModuleID;
	DynamicModule *mpNextModule;
	DynamicModule *mpPrevModule;
	int mNumSections;
	DynamicModule__SectionInfo *mpSectionInfoOffset;
	void *mpName;
	uint mNameSize;
	uint mRELFormatVersion;
	int mBssSize;
	void *mpRelocationTable;
	DynamicModule__ImpEntry *mpImpTable;
	uint mImpSize;
	byte mPrologSectionIdx;
	byte mEpilogSectionIdx;
	byte mUnresolvedSectionIdx;
	byte mBssSectionIdx;
	void *mpProlog;
	void *mpEpilog;
	void *mpUnresolved;
	uint mAlignment;
	uint mBssAlignment;
	int mFixSize;
};

enum DynamicModuleControl__ModuleType {
	Invalid = 0x0,
	LoadToMainRAM = 0x1,
	LoadToARAM = 0x2,
	LoadToDVDRAM = 0x3,
	LoadFromDisk = 0x7,
	LoadFromCache = 0xb,
};

struct DynamicModuleControl : public DynamicModuleControlBase {
	DynamicModule *mModule;
	uint a, b;
	char *mpModuleName;
	DynamicModuleControl__ModuleType mModuleType;
	short mCheckSum;
	int mDecompSize;
	int c;

	int field2_0x14;
	int field3_0x18;
	int field6_0x21;
	int field9_0x28;

	DynamicModuleControl(char *name) : DynamicModuleControlBase() {
		this->mModule = nullptr;
		this->mpModuleName = name;
		this->mModuleType = Invalid;
		this->mCheckSum = 0;
		this->mDecompSize = 0;
		this->field2_0x14 = 0;
		this->field3_0x18 = 0;
		this->field6_0x21 = 0;
		this->field9_0x28 = 0;
	}

	static int sFileCache,
		sAllocBytes;

	static JKRArchive *sArchive;

	static JKRArchive *mountCallback(void *param_1) {
		JKRExpHeap *heap;

		heap = m_Do_ext::mDoExt_getArchiveHeap();
		sFileCache = JKRFileCache::mount("/rels", heap, (char *)0x0);
		sArchive = (JKRArchive *)JKRArchive::mount("RELS.arc", 4, heap, 1);
		if (sArchive) {
			m_Do_printf::OSReport_Error("マウント失敗ですが単にアーカイブを作ってないだけなら遅いだけです %s\n", "RELS.arc");
		}
		return sArchive;
	}

	static int initialize(void) {
		sFileCache = 0;
		sAllocBytes = 0;
		sArchive = (JKRArchive *)0x0;
		mountCallback(nullptr);
		return 1;
	}
};

namespace c_dylink {
	mDoDvdThd_callback_c *cDyl_DVD;
	byte DMC_initialized;
	DynamicNameTableEntry DynamicNameTable[430];
	DynamicModuleControl *DMC[501];

	undefined4 c_dylink::cCc_Init(void) {
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

		if (c_dylink::DMC_initialized != '\0') {
			JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x2a, "!DMC_initialized");
			m_Do_printf::OSPanic("c_dylink.cpp", 0x2a, "Halt");
		}
		pParent = m_Do_ext::mDoExt_getArchiveHeap();
		solidheap = JKRSolidHeap::create(0x5648, pParent, false);
		regheap = solidheap->becomeCurrentHeap();
		//FUN_800033a8((int)c_dylink::DMC, 0, 0x7d8);
		memset(c_dylink::DMC, 0, 0x7d8);
		uVar7 = 0;
		iVar5 = 0;
		do {
			puVar6 = &c_dylink::DynamicNameTable[iVar5];
			if (puVar6->mRelFilename) {
				if (0x1f5 < puVar6->mPname) {
					JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x39, "d.mKey < (sizeof(DMC) / sizeof(DMC[0]))");
					m_Do_printf::OSPanic("c_dylink.cpp", 0x39, "Halt");
				}
				if (c_dylink::DMC[puVar6->mPname]) {
					JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x3a, "DMC[d.mKey] == 0");
					m_Do_printf::OSPanic("c_dylink.cpp", 0x3a, "Halt");
				}
				uVar3 = 0;
				iVar4 = 0;
				do {
					if (c_dylink::DMC[uVar3]) {
						iVar2 = strcmp(puVar6->mRelFilename, c_dylink::DMC[uVar3]->getModuleName());
						if (iVar2 == 0) {
							c_dylink::DMC[puVar6->mPname] = c_dylink::DMC[uVar3];
							break;
						}
					}
					uVar3 = uVar3 + 1;
					iVar4 = iVar4 + 4;
				} while (uVar3 < 0x1f6);
				if (c_dylink::DMC[puVar6->mPname] == (DynamicModuleControl *)0x0) {
					dmc = new DynamicModuleControl(c_dylink::DynamicNameTable[iVar5].mRelFilename);
					c_dylink::DMC[puVar6->mPname] = dmc;
				}
			}
			uVar7 = uVar7 + 1;
			iVar5 = iVar5 + 8;
			if (0x1ad < uVar7) {
				solidheap->adjustSize();
				regheap->becomeCurrentHeap();
				c_dylink::DMC_initialized = 1;
				return 1;
			}
		} while (true);
	}

	int cDyl_Initialized;

	void *c_dylink::cDyl_InitCallback(void *) {
		ulong uVar1;
		JKRExpHeap *heap;
		JKRFileLoader *fileloader;
		void *pvVar2;

		if (c_dylink::cDyl_Initialized != 0) {
			JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x12f, "!cDyl_Initialized");
			m_Do_printf::OSPanic("c_dylink.cpp", 0x12f, "Halt");
		}
		heap = m_Do_ext::mDoExt_getArchiveHeap();
		fileloader = (JKRFileLoader *)JKRFileCache::mount("/", heap, (char *)0x0);
		DynamicModuleControl::initialize();
		pvVar2 = (void *)JKRFileLoader::getGlbResource("/dvd/framework.str");
		//JKRFileLoader::detachResource(pvVar2, fileloader);
		fileloader->detachResource(pvVar2);
		fileloader->unmount();
		os::OSSetStringTable(pvVar2);
		DynamicModuleControl DStack56("f_pc_profile_lst");
		DStack56.link();
		c_dylink::cDyl_Initialized = 1;
		return (void *)1;
	}

	void cDyl_InitAsync(void) {
		ulong uVar1;

		c_dylink::cCc_Init();
		if (c_dylink::cDyl_DVD != 0) {
			JUTAssertion::getSDevice()->showAssert("c_dylink.cpp", 0x145, "cDyl_DVD == 0");
			m_Do_printf::OSPanic("c_dylink.cpp", 0x145, "Halt");
		}
		c_dylink::cDyl_DVD = mDoDvdThd_callback_c::create(c_dylink::cDyl_InitCallback, (void *)0x0);
		return;
	}

	int c_dylink::cDyl_Unlink(ushort param_1, char *param_2) {
		ulong uVar1;
		int iVar2;

		if (c_dylink::cDyl_Initialized == 0) {
			// uVar1 = JUTAssertion::getSDevice();
			// JUTAssertion::showAssert(uVar1, "c_dylink.cpp", 0xc5, "cDyl_Initialized");
			m_Do_printf::OSPanic("c_dylink.cpp", 0xc5, "Halt");
		}
		if (0x1f5 < param_1) {
			// uVar1 = JUTAssertion::getSDevice();
			// JUTAssertion::showAssert(uVar1, "c_dylink.cpp", 0xc6, "i_ProfName < (sizeof(DMC) / sizeof(DMC[0]))");
			m_Do_printf::OSPanic("c_dylink.cpp", 0xc6, "Halt");
		}
		if (c_dylink::DMC[(short)param_1] == (DynamicModuleControl *)0x0) {
			iVar2 = 0;
		} else {
			iVar2 = DMC[(short)param_1]->unlink();
		}
		return iVar2;
	}
}