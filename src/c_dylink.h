#pragma once

#include <JFramework/JKernel/JKRFileCache.h>
#include <machine/dolphin/dvd.h>

struct DynamicModuleControlBase {
	static DynamicModuleControlBase *mFirst;
	static DynamicModuleControlBase *mLast;

	static void dump();

	ushort mLinkCount, field1_0x2;

	DynamicModuleControlBase *next;
	DynamicModuleControlBase *prev;

	virtual char *getModuleName();
	virtual uint getModuleSize();
	virtual char *getModuleTypeString();
	virtual void dump2();
	virtual int do_load();
	virtual int do_load_async();
	virtual int do_unload();
	virtual int do_link();
	virtual int do_unlink();

	virtual ~DynamicModuleControlBase();

	DynamicModuleControlBase();
	undefined4 force_unlink();
	int link();
	int load_async();
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
	static int sAllocBytes;

	static JKRArchive *sArchive;
	static JKRFileCache *sFileCache;
	static JKRArchive *mountCallback(void *param_1);
	static int initialize(void);
	static void *callback(void*);

	DynamicModule *mModule;
	uint a, b;
	char *mpModuleName;
	DynamicModuleControl__ModuleType mModuleType;
	short mCheckSum;
	int mDecompSize;
	int c;
	void *bssPointer;
	int field3_0x18; // result of executing prologs
	int field6_0x21; // maybe keeps track of linking order?
	mDoDvdThd_callback_c *dvdcallback;

	virtual char *getModuleName();
	virtual uint getModuleSize();
	virtual char *getModuleTypeString();
	virtual void dump2();
	virtual int do_load();
	virtual int do_load_async();
	virtual int do_unload();
	virtual int do_link();
	virtual int do_unlink();

	DynamicModuleControl(char *name);
};

namespace c_dylink {
	extern mDoDvdThd_callback_c *cDyl_DVD;
	extern byte DMC_initialized;
	extern DynamicNameTableEntry DynamicNameTable[430];
	extern DynamicModuleControl *DMC[501];
	extern int cDyl_Initialized;

	undefined4 cCc_Init(void);
	void *cDyl_InitCallback(void *);
	void cDyl_InitAsync(void);
	int cDyl_Unlink(ushort param_1, char *param_2);
	int cDyl_LinkASync(ushort param_1);
}