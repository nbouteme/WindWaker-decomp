#pragma once

#include <JFramework/JKernel/JKRFileCache.h>
#include <machine/dolphin/dvd.h>

struct DynamicModuleControlBase {
	static DynamicModuleControlBase *mFirst;
	static DynamicModuleControlBase *mLast;

	static void dump() {
	}

	ushort mLinkCount, field1_0x2;

	DynamicModuleControlBase *next;
	DynamicModuleControlBase *prev;

	virtual char *getModuleName() { return nullptr; }
	virtual uint getModuleSize() { return 0; }
	virtual char *getModuleTypeString() { return "Base"; }
	//virtual void dump() {}
	virtual void dump2() {}
	virtual int do_load();

	DynamicModuleControlBase();

	undefined4 force_unlink();

	virtual int do_load_async();
	virtual int do_unload();
	virtual int do_link();
	virtual int do_unlink();

	virtual ~DynamicModuleControlBase();

	int link();

	int unlink();
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
	static int sFileCache, sAllocBytes;

	static JKRArchive *sArchive;
	static JKRArchive *mountCallback(void *param_1);
	static int initialize(void);

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

	DynamicModuleControl(char *name);
};

namespace c_dylink {
	mDoDvdThd_callback_c *cDyl_DVD;
	byte DMC_initialized;
	DynamicNameTableEntry DynamicNameTable[430];
	DynamicModuleControl *DMC[501];
	int cDyl_Initialized;

	undefined4 cCc_Init(void);
	void *cDyl_InitCallback(void *);
	void cDyl_InitAsync(void);
	int cDyl_Unlink(ushort param_1, char *param_2);
}