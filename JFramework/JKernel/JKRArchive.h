#pragma once

#include <cctype>
#include <cstring>

#include "../JSupport/JSUPtrLink.h"
#include "../JSupport/JSUPtrList.h"
#include "JKRDisposer.h"
#include "JKernel.h"

struct JKRFileFinder {
	char *name;
	uint entryNum;
	short id, attr;
	char attribute;
	byte regFile;
	virtual char findNextFile() = 0;
	virtual ~JKRFileFinder(){};
};

struct SDirEntry {
	byte attr;
	short id;
	char *data;
};

struct JKRArcFinder : public JKRFileFinder {
	int fileidx;
	JKRArchive *archive;
	int firstdiridx, lastdiridx;

	JKRArcFinder(JKRArchive *archive, int firstdiridx, int numentries) {
		attribute = '\0';
		regFile = 0;
		this->archive = archive;
		attribute =
			(byte)((byte)((uint)-numentries >> 0x18) & ~(byte)((uint)numentries >> 0x18)) >> 7;
		this->firstdiridx = firstdiridx;
		this->lastdiridx = firstdiridx + numentries + -1;
		this->fileidx = this->firstdiridx;
		findNextFile();
	}

	virtual char findNextFile() {
		char cVar1;
		SDirEntry local_18[2];

		if (attribute != '\0') {
			attribute =
				(char)(this->lastdiridx >> 0x1f) +
				(((uint)this->fileidx <= (uint)this->lastdiridx) - (char)(this->fileidx >> 0x1f));
			if (attribute != '\0') {
				cVar1 = this->archive->getDirEntry(local_18, this->fileidx);
				attribute = cVar1;
				name = local_18[0].data;
				entryNum = this->fileidx;
				id = local_18[0].id;
				attr = (ushort)(byte)local_18[0].attr;
				regFile = (byte)((ushort)attr >> 1) & 1;
				this->fileidx++;
			}
		}
		return this->attribute;
	};
	virtual ~JKRArcFinder(){};
};

struct JKRFileLoader : public JKRDisposer {
	static JSUPtrList sVolumeList;

	JSUPtrLink mVolumeLink;
	char *loaderfilename;
	uint type;
	byte mbIsMounted;
	uint refcount;

	JKRFileLoader() : mVolumeLink(this) {
	}

	virtual void unmount() {
		int iVar1;

		if (this->refcount != 0) {
			iVar1 = this->refcount + -1;
			this->refcount--;
			if ((iVar1 == 0) && (this)) {
				this->~JKRFileLoader();
			}
		}
	}

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
	virtual JKRArcFinder *getFirstFile(char *) = 0;
	// 
	//virtual uint getExpandedResSize(void *) = 0; // debatable if this belongs to file loader or archive, only archives have it, and it's not implemented by FileCache...
	//virtual void *fetchResource(SDIFileEntry *, uint *) = 0;
	//virtual void *fetchResource(void *, uint, SDIFileEntry *, uint *) = 0;
	//virtual void setExpandSize(SDIFileEntry *, uint) = 0;
	//virtual uint getExpandSize(SDIFileEntry *) = 0;

	static JKRFileLoader *sCurrentVolume;

	static char *fetchVolumeName(char *param_1, long param_2, char *param_3) {
		char cVar1;
		int iVar2;
		char *pcVar3;

		iVar2 = strcmp(param_3, "/");
		if (iVar2 == 0) {
			strcpy(param_1, JKernel::rootPath$2460);
			pcVar3 = JKernel::rootPath$2460;
		} else {
			for (pcVar3 = param_3 + 1; (cVar1 = *pcVar3, cVar1 != '\0' && (cVar1 != '/'));
				 pcVar3 = pcVar3 + 1) {
				if (1 < param_2) {
					if ((int)cVar1 == 0xffffffff) {
						cVar1 = -1;
					} else {
						//cVar1 = (&__lower_map)[(int)cVar1 & 0xff];
						cVar1 = tolower(cVar1);
					}
					*param_1 = cVar1;
					param_1 = param_1 + 1;
					param_2 = param_2 + -1;
				}
			}
			*param_1 = '\0';
			if (*pcVar3 == '\0') {
				pcVar3 = JKernel::rootPath$2460;
			}
		}
		return pcVar3;
	}

	static JKRArchive *check_mount_already(long param_1)

	{
		JSUPtrLink *pJVar1;
		JKRArchive *puVar2;

		pJVar1 = JKRFileLoader::sVolumeList.mpHead;
		while (true) {
			if (pJVar1 == (JSUPtrLink *)0x0) {
				return (JKRArchive *)0x0;
			}
			puVar2 = (JKRArchive *)pJVar1->mpData;
			if ((puVar2->type == 0x52415243) && (puVar2->resId == param_1))
				break;
			pJVar1 = pJVar1->mpNext;
		}
		puVar2->refcount++;
		return puVar2;
	}

	static JKRFileLoader *findVolume(char **param_1) {
		char *pcVar1;
		int iVar2;
		JKRFileLoader *pJVar3;
		JSUPtrLink *pJVar4;
		char acStack280[276];

		pJVar3 = JKRFileLoader::sCurrentVolume;
		if (**param_1 == '/') {
			pcVar1 = JKRFileLoader::fetchVolumeName(acStack280, 0x101, *param_1);
			*param_1 = pcVar1;
			for (pJVar4 = JKRFileLoader::sVolumeList.mpHead; pJVar4 != (JSUPtrLink *)0x0;
				 pJVar4 = pJVar4->mpNext) {
				iVar2 = strcmp(acStack280, *(char **)(pJVar4->mpData + 0x28));
				if (iVar2 == 0) {
					return (JKRFileLoader *)pJVar4->mpData;
				}
			}
			pJVar3 = (JKRFileLoader *)0x0;
		}
		return (JKRFileLoader *)pJVar3;
	}

	static void *getGlbResource(char *param_1) {
		void *uVar1;
		char *local_8[2];

		local_8[0] = param_1;
		auto piVar1 = findVolume(local_8);
		if (!piVar1) {
			uVar1 = nullptr;
		} else {
			uVar1 = piVar1->getResource(param_1);
		}
		return uVar1;
	}

	virtual ~JKRFileLoader() {}
};

using EMountDirection = int;
using EMountMode = int;

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
	int mSignature, mFileSize, mHeaderSize, mFileDataOffs, mFileDataTotalSize, mSizeOfMemPart, mSizeOfAramPart, unused;
};

enum EMountMode {
	None = 0x0,
	Mem = 0x1,
	ARAM = 0x2,
	DVD = 0x3,
	Comp = 0x4,
};

struct JKRDvdArchive;

struct JKRArchive : public JKRFileLoader {
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

	JKRArchive() = default;

	static int sCurrentDirID;
	int initMode;
	int resId;

	virtual uint getExpandedResSize(void *) = 0; // debatable if this belongs to file loader or archive, only archives have it, and it's not implemented by FileCache...
	virtual void *fetchResource(SDIFileEntry *, uint *) = 0;
	virtual void *fetchResource(void *, uint, SDIFileEntry *, uint *) = 0;
	virtual void setExpandSize(SDIFileEntry *, uint) = 0;
	virtual uint getExpandSize(SDIFileEntry *) = 0;

	static JKRArchive *mount(long param_1, EMountMode mountMode, JKRHeap *param_3, EMountDirection param_4);

	static JKRArchive *mount(char *param_1, int param_2, JKRHeap *param_3, int param_4) {
		int iVar1;

		iVar1 = dvd::DVDConvertPathToEntrynum(param_1);
		if (iVar1 >= 0) {
			return mount(iVar1, (EMountMode)param_2, param_3, param_4);
		}
		return nullptr;
	}
	struct CArcName {
		short mHash, mSize;
		char mName[256];
		void store(char *param_1) {
			int iVar1;
			int iVar2;

			this->mHash = 0;
			iVar2 = 0;
			for (; *param_1 != '\0'; param_1 = param_1 + 1) {
				iVar1 = tolower((int)*param_1);
				this->mHash = (short)iVar1 + this->mHash * 3;
				if (iVar2 < 0x100) {
					this->mName[iVar2] = (char)iVar1;
					iVar2 = iVar2 + 1;
				}
			}
			this->mSize = (short)iVar2;
			this->mName[iVar2] = '\0';
		}

		char *store(char *param_1, char param_2) {
			char cVar1;
			int iVar2;
			char *pcVar3;
			int iVar4;

			this->mHash = 0;
			iVar4 = 0;
			while (true) {
				cVar1 = *param_1;
				if ((cVar1 == '\0') || (cVar1 == param_2))
					break;
				iVar2 = tolower((int)cVar1);
				this->mHash = (short)iVar2 + this->mHash * 3;
				if (iVar4 < 0x100) {
					this->mName[iVar4] = (char)iVar2;
					iVar4 = iVar4 + 1;
				}
				param_1 = param_1 + 1;
			}
			this->mSize = (short)iVar4;
			this->mName[iVar4] = '\0';
			if (*param_1 == '\0') {
				pcVar3 = (char *)0x0;
			} else {
				pcVar3 = param_1 + 1;
			}
			return pcVar3;
		}
	};

	uint
	JKRArchive::isSameName(CArcName *param_1, ulong param_2, ushort param_3) {
		uint uVar1;
		int iVar2;

		if (param_1->mHash == param_3) {
			iVar2 = strcmp(this->mpStrData + param_2, param_1->mName);
			return iVar2 == 0;
		} else {
			uVar1 = 0;
		}
		return uVar1;
	}

	int *expandedSizes;

	virtual void setExpandSize(SDIFileEntry *param_1, uint expandSize) {
		uint uVar1;

		uVar1 = ((int)param_1 - (int)this->mpFileEntries) / 0x14;
		if (this->expandedSizes == (int *)0x0) {
			return;
		}
		if ((uint)this->mpDataHeader->mFileEntryCount <= uVar1) {
			return;
		}
		this->expandedSizes[uVar1] = expandSize;
		return;
	}

	virtual uint JKRArchive::getExpandSize(SDIFileEntry *param_1)  {
		uint uVar1 = param_1 - this->mpFileEntries;
		if ((this->expandedSizes != (int *)0x0) && (uVar1 < (uint)this->mpDataHeader->mFileEntryCount)) {
			return this->expandedSizes[uVar1];
		}
		return 0;
	}

	JKRArchive__Node *findDirectory(char *param_1, ulong param_2) {
		char *pcVar1;
		JKRArchive__Node *pJVar2;
		char cVar3;
		int iVar4;
		SDIFileEntry *pSVar5;
		CArcName CStack296;

		if (param_1 == (char *)0x0) {
			pJVar2 = this->mpNodes + param_2;
		} else {
			pcVar1 = (char *)CStack296.store(param_1, '/');
			pJVar2 = this->mpNodes;
			pSVar5 = this->mpFileEntries + pJVar2[param_2].firstdiridx;
			for (iVar4 = 0; iVar4 < (int)(uint)pJVar2[param_2].dirnum; iVar4 = iVar4 + 1) {
				cVar3 = JKRArchive::isSameName(&CStack296, pSVar5->mAttrAndNameOffs & 0xffffff, pSVar5->mNameHash);
				if (cVar3 != '\0') {
					if (((uint)pSVar5->mAttrAndNameOffs >> 0x18 & 2) != 0) {
						pJVar2 = (JKRArchive__Node *)findDirectory(pcVar1, pSVar5->mDataOffs);
						return pJVar2;
					}
					break;
				}
				pSVar5 = pSVar5 + 1;
			}
			pJVar2 = (JKRArchive__Node *)0x0;
		}
		return pJVar2;
	}

	virtual bool becomeCurrent(char *param_1) override {
		uint uVar1;
		JKRArchive__Node *iVar2;
		char *pcVar3;

		if (*param_1 == '/') {
			pcVar3 = param_1 + 1;
			if (*pcVar3 == '\0') {
				pcVar3 = (char *)0x0;
			}
			iVar2 = findDirectory(pcVar3, 0);
		} else {
			iVar2 = findDirectory(param_1, JKRArchive::sCurrentDirID);
		}
		if (iVar2 != 0) {
			uVar1 = iVar2 - this->mpNodes;
			// index of iVar2 rela
			//JKRArchive::sCurrentDirID = ((int)uVar1 >> 4) + (uint)((int)uVar1 < 0 && (uVar1 & 0xf) != 0);
			JKRArchive::sCurrentDirID = uVar1;
			JKRFileLoader::sCurrentVolume = this;
		}
		return iVar2 != 0;
	}

	JKRArchive(long param_1, EMountMode param_2) {
		JKRHeap *pJVar1;

		mbIsMounted = 0;
		this->mMountMode = param_2;
		refcount = 1;
		initMode = 1;
		pJVar1 = JKRHeap::findFromRoot(this);
		this->mpHeap = pJVar1;
		if (this->mpHeap == (JKRHeap *)0x0) {
			this->mpHeap = JKRHeap::sCurrentHeap;
		}
		this->resId = param_1;
		if (JKRFileLoader::sCurrentVolume == (JKRFileLoader *)0x0) {
			sCurrentDirID = 0;
			JKRFileLoader::sCurrentVolume = this;
		}
		return;
	}

	void *findIdxResource(ulong param_1) {
		if (param_1 < (uint)this->mpDataHeader->mFileEntryCount) {
			return this->mpFileEntries + param_1;
		}
		return nullptr;
	}

	// that's... not how it works
	virtual uint getExpandedResSize(void *param_1)  {
		return getExpandedResSize(param_1);
	}

	// 802b8878 NON VIRTUAL
	uint readResource(void *param_1, ulong param_2, ushort param_3)

	{
		uint uVar1 = 0;
		SDIFileEntry *pSVar2;
		void *local_18;

		if (mbIsMounted == 0) {
			JUTAssertion::getSDevice()->showAssert("JKRArchivePub.cpp", 0x273, "isMounted()");
			m_Do_printf::OSPanic("JKRArchivePub.cpp", 0x273, "Halt");
		}
		pSVar2 = findIdResource(param_3);
		if (pSVar2 == (SDIFileEntry *)0x0) {
			local_18 = 0;
		} else {
			local_18 = fetchResource(param_1, param_2, pSVar2, &uVar1);
		}
		return uVar1;
	}

	virtual uint readResource(void *param_1, uint param_2, char *param_3) override {
		uint uVar1 = 0;
		SDIFileEntry *pSVar2;
		void *local_18;

		if (mbIsMounted == 0) {
			//uVar1 = JUTAssertion::getSDevice();
			//JUTAssertion::showAssert(uVar1, "JKRArchivePub.cpp", 0x219, "isMounted()");
			m_Do_printf::OSPanic("JKRArchivePub.cpp", 0x219, "Halt");
		}
		if (*param_3 == '/') {
			pSVar2 = findFsResource(param_3 + 1, 0);
		} else {
			pSVar2 = findFsResource(param_3, JKRArchive::sCurrentDirID);
		}
		if (pSVar2 == (SDIFileEntry *)0x0) {
			local_18 = 0;
		} else {
			local_18 = fetchResource(param_1, param_2, pSVar2, &uVar1);
		}
		return uVar1;
	}

	SDIFileEntry *findIdResource(ushort param_1) {
		uint uVar1;
		int iVar2;
		SDIFileEntry *pSVar3;
		SDIFileEntry *pSVar4;

		uVar1 = (uint)param_1;
		if (uVar1 != 0xffff) {
			pSVar3 = this->mpFileEntries;
			pSVar4 = pSVar3 + uVar1;
			if (((ushort)pSVar4->mId == uVar1) && (((uint)pSVar4->mAttrAndNameOffs >> 0x18 & 1) != 0)) {
				return pSVar4;
			}
			for (iVar2 = this->mpDataHeader->mFileEntryCount; iVar2 != 0; iVar2 = iVar2 + -1) {
				if ((pSVar3->mId == param_1) && (((uint)pSVar3->mAttrAndNameOffs >> 0x18 & 1) != 0)) {
					return pSVar3;
				}
				pSVar3 = pSVar3 + 1;
			}
		}
		return (SDIFileEntry *)0x0;
	}

	virtual uint readResource(void *param_1, uint param_2, uint param_3, char *param_4) override {
		ulong uVar1;
		SDIFileEntry *pSVar2;
		uint local_28[5];

		if (mbIsMounted == 0) {
			//uVar1 = JUTAssertion::getSDevice();
			//JUTAssertion::showAssert(uVar1, "JKRArchivePub.cpp", 0x1eb, "isMounted()");
			m_Do_printf::OSPanic("JKRArchivePub.cpp", 0x1eb, "Halt");
		}
		if ((param_3 == 0) || (param_3 == 0x3f3f3f3f)) {
			pSVar2 = findNameResource(param_4);
		} else {
			pSVar2 = findTypeResource(param_3, param_4);
		}
		if (pSVar2 == (SDIFileEntry *)0x0) {
			local_28[0] = 0;
		} else {
			fetchResource(param_1, param_2, pSVar2, local_28);
		}
		return local_28[0];
	}

	bool getDirEntry(SDirEntry *param_1, uint param_2) {
		undefined *resource;

		resource = (undefined *)findIdxResource(param_2);
		if (resource) {
			param_1->attr = (char)((uint) * (undefined4 *)(resource + 4) >> 0x18);	 // first byte?, dependant on endianness
			param_1->id = *(undefined2 *)resource;									 // first two bytes
			param_1->data = this->mpStrData + (*(uint *)(resource + 4) & 0xffffff);	 // hard limit of 16MB on resources
		}
		return !!resource;
	}

	SDIFileEntry *findPtrResource(void *dataPtr) {
		int iVar1;
		SDIFileEntry *pSVar2;

		pSVar2 = this->mpFileEntries;
		iVar1 = this->mpDataHeader->mFileEntryCount;
		while (true) {
			if (iVar1 == 0) {
				return (SDIFileEntry *)0x0;
			}
			if (pSVar2->mpData == dataPtr)
				break;
			pSVar2 = pSVar2 + 1;
			iVar1 = iVar1 + -1;
		}
		return pSVar2;
	}

	virtual uint getResSize(void *param_1) override {
		ulong uVar1;
		SDIFileEntry *pSVar2;
		int iVar3;

		if (param_1 == (void *)0x0) {
			JUTAssertion::getSDevice()->showAssert("JKRArchivePub.cpp", 0x2ea, "resource != 0");
			m_Do_printf::OSPanic("JKRArchivePub.cpp", 0x2ea, "Halt");
		}
		pSVar2 = findPtrResource(param_1);
		if (pSVar2 == (SDIFileEntry *)0x0) {
			iVar3 = -1;
		} else {
			iVar3 = pSVar2->mDataSize;
		}
		return iVar3;
	}

	virtual ushort countFile(char *param_1) override {
		JKRArchive__Node *iVar1;
		ushort uVar1;
		char *pcVar2;

		if (*param_1 == '/') {
			pcVar2 = param_1 + 1;
			if (*pcVar2 == '\0') {
				pcVar2 = (char *)0x0;
			}
			iVar1 = findDirectory(pcVar2, 0);
		} else {
			iVar1 = findDirectory(param_1, JKRArchive::sCurrentDirID);
		}
		if (iVar1 == (JKRArchive__Node *)0x0) {
			uVar1 = 0;
		} else {
			uVar1 = iVar1->dirnum;
		}
		return uVar1;
	}

	SDIFileEntry *findFsResource(char *param_1, ulong param_2) {
		char *pcVar1;
		JKRArchive__Node *pJVar2;
		char cVar4;
		SDIFileEntry *pSVar3;
		int iVar5;
		CArcName CStack296;

		if (param_1 != (char *)0x0) {
			pcVar1 = (char *)CStack296.store(param_1, '/');
			pJVar2 = this->mpNodes;
			pSVar3 = this->mpFileEntries + pJVar2[param_2].firstdiridx;
			for (iVar5 = 0; iVar5 < (int)(uint)pJVar2[param_2].dirnum; iVar5 = iVar5 + 1) {
				cVar4 = isSameName(&CStack296, pSVar3->mAttrAndNameOffs & 0xffffff, pSVar3->mNameHash);
				if (cVar4 != '\0') {
					if (((uint)pSVar3->mAttrAndNameOffs >> 0x18 & 2) != 0) {
						pSVar3 = (SDIFileEntry *)findFsResource(pcVar1, pSVar3->mDataOffs);
						return pSVar3;
					}
					if (pcVar1 == (char *)0x0) {
						return pSVar3;
					}
					return (SDIFileEntry *)0x0;
				}
				pSVar3 = pSVar3 + 1;
			}
		}
		return (SDIFileEntry *)0x0;
	}

	virtual JKRArcFinder *getFirstFile(char *param_1) override {
		JKRArchive__Node *iVar1;
		JKRArcFinder *this_00;
		char *pcVar1;

		if (*param_1 == '/') {
			pcVar1 = param_1 + 1;
			if (*pcVar1 == '\0') {
				pcVar1 = (char *)0x0;
			}
			iVar1 = findDirectory(pcVar1, 0);
		} else {
			iVar1 = findDirectory(param_1, JKRArchive::sCurrentDirID);
		}
		if (iVar1 == (JKRArchive__Node *)0x0) {
			this_00 = (JKRArcFinder *)0x0;
		} else {
			this_00 = new (JKRHeap::sSystemHeap, 0) JKRArcFinder(this, iVar1->firstdiridx, (uint)iVar1->dirnum);
		}
		return this_00;
	}

	SDIFileEntry *findNameResource(char *param_1) {
		char cVar1;
		uint uVar2;
		SDIFileEntry *pSVar3;
		CArcName CStack280;

		pSVar3 = this->mpFileEntries;
		CStack280.store(param_1);
		uVar2 = 0;
		while (true) {
			if ((uint)this->mpDataHeader->mFileEntryCount <= uVar2) {
				return (SDIFileEntry *)0x0;
			}
			cVar1 = JKRArchive::isSameName(&CStack280, pSVar3->mAttrAndNameOffs & 0xffffff, pSVar3->mNameHash);
			if (cVar1 != '\0')
				break;
			pSVar3 = pSVar3 + 1;
			uVar2 = uVar2 + 1;
		}
		return pSVar3;
	}

	JKRArchive__Node *findResType(ulong param_1) {
		int iVar1;
		JKRArchive__Node *pJVar2;

		pJVar2 = this->mpNodes;
		iVar1 = this->mpDataHeader->mNodeCount;
		while (true) {
			if (iVar1 == 0) {
				return (JKRArchive__Node *)0x0;
			}
			if (*(ulong *)pJVar2->type == param_1)
				break;
			pJVar2 = pJVar2 + 1;
			iVar1 = iVar1 + -1;
		}
		return pJVar2;
	}

	SDIFileEntry *findTypeResource(ulong param_1, char *param_2) {
		JKRArchive__Node *iVar1;
		char cVar1;
		int iVar2;
		SDIFileEntry *pSVar3;
		CArcName CStack280;

		if (param_1 != 0) {
			CStack280.store(param_2);
			iVar1 = (JKRArchive__Node *)findResType(param_1);
			if (iVar1 != (JKRArchive__Node *)0x0) {
				pSVar3 = this->mpFileEntries + iVar1->firstdiridx;
				for (iVar2 = 0; iVar2 < (int)(uint)iVar1->dirnum; iVar2 = iVar2 + 1) {
					cVar1 = isSameName(&CStack280, pSVar3->mAttrAndNameOffs & 0xffffff, pSVar3->mNameHash);
					if (cVar1 != '\0') {
						return pSVar3;
					}
					pSVar3 = pSVar3 + 1;
				}
			}
		}
		return (SDIFileEntry *)0x0;
	}

	virtual void *getResource(uint param_1, char *param_2) override {
		ulong uVar1;
		SDIFileEntry *iVar2;
		void *uVar3;

		if (mbIsMounted == 0) {
			//uVar1 = JUTAssertion::getSDevice();
			//JUTAssertion::showAssert(uVar1, "JKRArchivePub.cpp", 0x14c, "isMounted()");
			m_Do_printf::OSPanic("JKRArchivePub.cpp", 0x14c, "Halt");
		}

		if ((param_1 == 0) || (param_1 == 0x3f3f3f3f)) {
			iVar2 = findNameResource(param_2);
		} else {
			iVar2 = findTypeResource(param_1, param_2);
		}
		if (iVar2 == 0) {
			uVar3 = 0;
		} else {
			uVar3 = fetchResource(iVar2, (uint *)nullptr);
		}
		return uVar3;
	}

	virtual void *getResource(char *param_1) override {
		ulong uVar1;
		SDIFileEntry *iVar2;
		void *uVar3;

		if (mbIsMounted == 0) {
			JUTAssertion::getSDevice()->showAssert("JKRArchivePub.cpp", 0x11d, "isMounted()");
			m_Do_printf::OSPanic("JKRArchivePub.cpp", 0x11d, "Halt");
		}
		if (*param_1 == '/') {
			iVar2 = findFsResource(param_1 + 1, 0);
		} else {
			iVar2 = findFsResource(param_1, JKRArchive::sCurrentDirID);
		}
		if (iVar2 == 0) {
			uVar3 = 0;
		} else {
			uVar3 = fetchResource(iVar2, (uint *)nullptr);
		}
		return uVar3;
	}

	virtual void removeResourceAll() override {
		uint uVar1;
		SDIFileEntry *pSVar2;

		if ((this->mpDataHeader != (JKRArchive__DataHeader *)0x0) && (this->mMountMode != Mem)) {
			pSVar2 = this->mpFileEntries;
			for (uVar1 = 0; uVar1 < (uint)this->mpDataHeader->mFileEntryCount; uVar1 = uVar1 + 1) {
				if (pSVar2->mpData != (void *)0x0) {
					JKRHeap::free(pSVar2->mpData, this->mpHeap);
					pSVar2->mpData = (void *)0x0;
				}
				pSVar2 = pSVar2 + 1;
			}
		}
	}

	virtual bool JKRArchive::removeResource(void *param_1) override {
		ulong uVar1;
		SDIFileEntry *pSVar2;

		if (param_1 == (void *)0x0) {
			//uVar1 = JUTAssertion::getSDevice();
			//JUTAssertion::showAssert(uVar1, "JKRArchivePub.cpp", 0x2af, "resource != 0");
			m_Do_printf::OSPanic("JKRArchivePub.cpp", 0x2af, "Halt");
		}
		pSVar2 = findPtrResource(param_1);
		if (pSVar2 != (SDIFileEntry *)0x0) {
			pSVar2->mpData = (void *)0x0;
			JKRHeap::free(param_1, this->mpHeap);
		}
		return pSVar2 != (SDIFileEntry *)0x0;
	}

	virtual bool detachResource(void *param_1) {
		ulong uVar1;
		SDIFileEntry *pSVar2;

		if (param_1 == (void *)0x0) {
			//uVar1 = JUTAssertion::getSDevice();
			//JUTAssertion::showAssert(uVar1,"JKRArchivePub.cpp",0x2cf,"resource != 0");
			m_Do_printf::OSPanic("JKRArchivePub.cpp", 0x2cf, "Halt");
		}
		pSVar2 = findPtrResource(param_1);
		if (pSVar2 != (SDIFileEntry *)0x0) {
			pSVar2->mpData = (void *)0x0;
		}
		return pSVar2 != (SDIFileEntry *)0x0;
	}

	virtual ~JKRArchive() {}
};
