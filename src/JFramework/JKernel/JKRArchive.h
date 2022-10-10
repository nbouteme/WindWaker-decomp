#pragma once

#include <cctype>
#include <cstring>

#include "../JSupport/JSUPtrLink.h"
#include "../JSupport/JSUPtrList.h"
#include "JKRDecomp.h"
#include "JKRDisposer.h"
#include "JKernel.h"

struct JKRFileFinder {
	char *name;
	uint entryNum;
	short id, attr;
	char attribute;
	byte regFile;
	virtual char findNextFile() = 0;
	virtual ~JKRFileFinder();
};

struct SDirEntry {
	byte attr;
	short id;
	char *data;
};

enum SDIFileEntry__AttributeType {
	File = 1,
	Directory = 2,
	Compressed = 4,
	MEM = 0x10,
	ARAM = 0x20,
	DVD = 0x40,
	YAZ0Compressed = 0x80
};

struct JKRArchive;

struct JKRArcFinder : public JKRFileFinder {
	int fileidx;
	JKRArchive *archive;
	int firstdiridx, lastdiridx;

	JKRArcFinder(JKRArchive *archive, int firstdiridx, int numentries);

	virtual char findNextFile();
	virtual ~JKRArcFinder();
};

struct JKRFileLoader : public JKRDisposer {
	static JSUPtrList sVolumeList;

	JSUPtrLink mVolumeLink;
	char *loaderfilename;
	uint type;
	byte mbIsMounted;
	uint refcount;

	static int detachResource(void *r, JKRFileLoader *);

	JKRFileLoader();

	virtual void unmount();

	struct SDIFileEntry {
		short mId, mNameHash;
		int mAttrAndNameOffs, mDataOffs, mDataSize;
		void *mpData;
	};

	// JKRFileLoader vtable has 16 entries, JKRArchive has 20
	virtual bool becomeCurrent(char *) = 0;
	virtual void *getResource(char *) = 0;
	virtual void *getResource(uint, char *) = 0;
	virtual uint readResource(void *, uint, char *) = 0;
	virtual uint readResource(void *, uint, uint, char *) = 0;
	virtual void removeResourceAll() = 0;
	virtual bool removeResource(void *) = 0;
	virtual bool detachResource(void *) = 0;
	virtual uint getResSize(void *) = 0;
	virtual ushort countFile(char *) = 0;
	virtual JKRFileFinder *getFirstFile(char *) = 0;
	//
	// virtual uint getExpandedResSize(void *) = 0; // debatable if this belongs to file loader or archive, only archives have it, and it's not implemented by FileCache...
	// virtual void *fetchResource(SDIFileEntry *, uint *) = 0;
	// virtual void *fetchResource(void *, uint, SDIFileEntry *, uint *) = 0;
	// virtual void setExpandSize(SDIFileEntry *, uint) = 0;
	// virtual uint getExpandSize(SDIFileEntry *) = 0;

	static JKRFileLoader *sCurrentVolume;

	static char *fetchVolumeName(char *param_1, long param_2, char *param_3);

	static JKRArchive *check_mount_already(long param_1);

	static JKRFileLoader *findVolume(char **param_1);

	static void *getGlbResource(char *param_1);
	static void *getGlbResource(char *param_1, JKRFileLoader *param_2);

	virtual ~JKRFileLoader();
};

using EMountDirection = int;

struct JKRArchive__DataHeader {
	int mNodeCount, mNodeOffs, mFileEntryCount, mFileEntryOffs, mStrTableSize, mStrTableOffs;
};

struct JKRArchive__Node {
	char type[4];
	uint stroffset;
	ushort strhash;
	ushort dirnum;
	uint firstdiridx;
};

struct JKRArchive__Header {
	int mSignature,
		mFileSize,
		mHeaderSize,
		mFileDataOffs,
		mFileDataTotalSize,
		mSizeOfMemPart,
		mSizeOfAramPart,
		unused;
};

enum EMountMode {
	None = 0x0,
	Mem = 0x1,
	Aram = 0x2,
	Dvd = 0x3,
	Comp = 0x4,
};

struct JKRDvdArchive;

struct JKRArchive : public JKRFileLoader {
	static int sCurrentDirID;

	byte mBisMounted;
	JKRHeap *mpHeap;
	EMountMode mMountMode;
	JKRDvdArchive *unused;
	JKRArchive__DataHeader *mpDataHeader;
	JKRArchive__Node *mpNodes;
	SDIFileEntry *mpFileEntries;
	int unused2;
	char *mpStrData;
	uint unused3;
	JKRDecomp__CompressionType mCompressionType;
	EMountDirection mMountDirection;
	JKRArchive__Header *mpHeader;
	int *expandedSizes;
	int initMode;
	int resId;

	JKRArchive() = default;

	static JKRArchive *mount(long param_1, EMountMode mountMode, JKRHeap *param_3, EMountDirection param_4);
	static JKRArchive *mount(char *param_1, int param_2, JKRHeap *param_3, int param_4);
	static void *getGlbResource(uint, char *param_1, JKRArchive *);

	virtual void *fetchResource(SDIFileEntry *, uint *) = 0;
	virtual void *fetchResource(void *, uint, SDIFileEntry *, uint *) = 0;

	virtual void setExpandSize(SDIFileEntry *param_1, uint expandSize);
	virtual uint getExpandSize(SDIFileEntry *param_1);
	virtual bool becomeCurrent(char *param_1) override;
	virtual uint getExpandedResSize(void *param_1);
	virtual uint readResource(void *param_1, uint param_2, char *param_3) override;
	virtual uint readResource(void *param_1, uint param_2, uint param_3, char *param_4) override;
	virtual uint getResSize(void *param_1) override;
	virtual ushort countFile(char *param_1) override;
	virtual JKRArcFinder *getFirstFile(char *param_1) override;
	virtual void *getResource(uint param_1, char *param_2) override;
	virtual void *getResource(char *param_1) override;
	virtual void removeResourceAll() override;
	virtual bool removeResource(void *param_1) override;
	virtual bool detachResource(void *param_1);
	virtual ~JKRArchive();

	struct CArcName {
		short mHash, mSize;
		char mName[256];
		void store(char *param_1);

		char *store(char *param_1, char param_2);
	};

	uint isSameName(CArcName *param_1, ulong param_2, ushort param_3);

	JKRArchive__Node *findDirectory(char *param_1, ulong param_2);
	JKRArchive(long param_1, EMountMode param_2);
	void *findIdxResource(ulong param_1);

	// 802b8878 NON VIRTUAL
	uint readResource(void *param_1, ulong param_2, ushort param_3);
	SDIFileEntry *findIdResource(ushort param_1);
	bool getDirEntry(SDirEntry *param_1, uint param_2);
	SDIFileEntry *findPtrResource(void *dataPtr);
	SDIFileEntry *findFsResource(char *param_1, ulong param_2);
	SDIFileEntry *findNameResource(char *param_1);
	JKRArchive__Node *findResType(ulong param_1);
	SDIFileEntry *findTypeResource(ulong param_1, char *param_2);

	int countResource(ulong param_1) {
		int iVar1;
		JKRArchive__Node *pJVar2;
		int iVar3;
		uint uVar4;
		uint uVar5;
		int iVar6;

		pJVar2 = findResType(param_1);
		if (pJVar2 == (JKRArchive__Node *)0x0) {
			iVar6 = 0;
		} else {
			iVar6 = 0;
			uVar5 = pJVar2->firstdiridx;
			uVar4 = uVar5 + pJVar2->dirnum;
			iVar3 = uVar5 * 0x14;
			iVar1 = uVar4 - uVar5;
			if (uVar5 < uVar4) {
				do {
					if ((*(uint *)((int)&this->mpFileEntries->mAttrAndNameOffs + iVar3) >> 0x18 & 1) != 0) {
						iVar6 = iVar6 + 1;
					}
					iVar3 = iVar3 + 0x14;
					iVar1 = iVar1 + -1;
				} while (iVar1 != 0);
			}
		}
		return iVar6;
	}

	uint getFileAttribute(ulong param_1) {
		undefined2 *puVar1;
		uint uVar2;

		puVar1 = (undefined2 *)findIdxResource(param_1);
		if (puVar1 == (undefined2 *)0x0) {
			uVar2 = 0;
		} else {
			uVar2 = *(uint *)(puVar1 + 2) >> 0x18;
		}
		return uVar2;
	}

	JKRArcFinder *getFirstResource(ulong param_1) {
		JKRArchive__Node *iVar1;
		uint uVar1;
		JKRArcFinder *this_00;
		long numentries;

		iVar1 = findResType(param_1);
		if ((iVar1 == (JKRArchive__Node *)0x0) ||
			(uVar1 = getFileAttribute(iVar1->firstdiridx), (uVar1 & 1) == 0)) {
			return new (JKRHeap::sSystemHeap, 0) JKRArcFinder(this, 0, 0);
		} else {
			return new (JKRHeap::sSystemHeap, 0) JKRArcFinder(this, iVar1->firstdiridx, countResource(param_1));
		}
		return this_00;
	}
};
