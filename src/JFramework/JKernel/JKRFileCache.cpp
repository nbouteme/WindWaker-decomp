#include "JKRFileCache.h"

#include <machine/dolphin/printf.h>

#include "../JSupport/JSUIosBase.h"
#include "../JUtility/JUTAssert.h"
#include "JKRExpHeap.h"

JKRFileCache::CCacheBlock::CCacheBlock(ulong start, ulong len, void *buffer) : linklist(this) {
	one = 1;
	start = start;
	length = len;
	buffer = buffer;
	return;
}

void JKRFileCache::convStrLower(char *param_1) {
	int iVar1;

	while (true) {
		if (*param_1 == '\0')
			break;
		iVar1 = tolower((int)*param_1);
		*param_1 = (char)iVar1;
		param_1 = param_1 + 1;
	}
	return;
}

JKRFileCache::JKRFileCache(char *param_1, char *param_2) {
	JKRHeap *pJVar1;
	uint sVar2;
	char *pcVar3;

	this->cacheblocklist.initiate();
	pJVar1 = JKRHeap::findFromRoot(this);
	this->heap = pJVar1;
	refcount = 1;
	type = 0x43415348;
	sVar2 = strlen(param_1);
	pcVar3 = (char *)JKRHeap::alloc(sVar2 + 1, 1, this->heap);
	this->pathcopy = pcVar3;
	pcVar3 = (char *)JKRHeap::sSystemHeap->alloc(sVar2 + 2, 1);
	this->convertedpath = pcVar3;
	strcpy(this->pathcopy, param_1);
	strcpy(this->convertedpath, param_1);
	if (param_1[1] == '\0') {
		if (param_2 == (char *)0x0) {
			param_2 = "dvd";
		}
		sVar2 = strlen(param_2);
		pcVar3 = (char *)JKRHeap::sSystemHeap->alloc(sVar2 + 1, 0);
		this->filenamecopy = pcVar3;
		strcpy(this->filenamecopy, param_2);
		convStrLower(this->filenamecopy);
		loaderfilename = this->filenamecopy;
	} else {
		convStrLower(this->pathcopy);
		convStrLower(this->convertedpath);
		strcat(this->convertedpath, "/");
		if (param_2 == (char *)0x0) {
			pcVar3 = strrchr(this->pathcopy, 0x2f);
			param_2 = pcVar3 + 1;
		}
		sVar2 = strlen(param_2);
		pcVar3 = (char *)JKRHeap::sSystemHeap->alloc(sVar2 + 1, 0);
		this->filenamecopy = pcVar3;
		strcpy(this->filenamecopy, param_2);
		convStrLower(this->filenamecopy);
		loaderfilename = this->filenamecopy;
	}
	JKRFileLoader::sVolumeList.prepend(&mVolumeLink);
	mbIsMounted = 1;
	return;
}

JKRFileCache::CCacheBlock *JKRFileCache::findCacheBlock(void *param_1) {
	JSUPtrLink *pJVar1;

	pJVar1 = (this->cacheblocklist).mpHead;
	while (true) {
		if (pJVar1 == nullptr) {
			return nullptr;
		}
		if (((CCacheBlock *)pJVar1->mpData)->buffer == param_1)
			break;
		pJVar1 = pJVar1->mpNext;
	}
	return (CCacheBlock *)pJVar1->mpData;
}

JKRFileCache::CCacheBlock *JKRFileCache::findCacheBlock(ulong param_1) {
	JSUPtrLink *pJVar1;

	pJVar1 = (this->cacheblocklist).mpHead;
	while (true) {
		if (pJVar1 == nullptr) {
			return nullptr;
		}
		if (((CCacheBlock *)pJVar1->mpData)->start == param_1)
			pJVar1 = pJVar1->mpNext;
	}
	return (CCacheBlock *)pJVar1->mpData;
}

void *JKRFileCache::getFsResource(char *param_1) {
	return this->getResource(param_1);
}

void *JKRFileCache::getNameResource(ulong param_1, char *param_2) {
	return getResource(param_1, param_2);
}

uint JKRFileCache::readFsResource(void *param_1, ulong param_2, char *param_3) {
	return readResource(param_1, param_2, param_3);
}

uint JKRFileCache::readNameResource(void *param_1, ulong param_2, ulong param_3, char *param_4) {
	return readResource(param_1, param_2, param_3, param_4);
}

uint JKRFileCache::getResSize(void *param_1) {
	CCacheBlock *iVar1;
	undefined4 uVar2;

	iVar1 = findCacheBlock(param_1);
	if (iVar1 == 0) {
		uVar2 = 0xffffffff;
	} else {
		uVar2 = iVar1->length;
	}
	return uVar2;
}

char *JKRFileCache::getDvdPathName(char *param_1) {
	size_t sVar1;
	size_t sVar2;
	char *__dest;

	if (*param_1 == '/') {
		sVar1 = strlen(param_1);
		sVar2 = strlen(this->pathcopy);
		__dest = (char *)JKRHeap::sSystemHeap->alloc(sVar2 + sVar1 + 2, 1);
		strcpy(__dest, this->pathcopy);
		if (param_1[1] != '\0') {
			if (this->pathcopy[1] == '\0') {
				strcat(__dest, param_1 + 1);
			} else {
				strcat(__dest, param_1);
			}
		}
	} else {
		sVar1 = strlen(param_1);
		sVar2 = strlen(this->convertedpath);
		__dest = (char *)JKRHeap::sSystemHeap->alloc(sVar2 + sVar1 + 2, 1);
		strcpy(__dest, this->convertedpath);
		strcat(__dest, param_1);
	}
	convStrLower(__dest);
	return __dest;
}

ushort JKRFileCache::countFile(char *param_1) {
	char *__ptr;
	bool bVar2;
	int iVar1;
	int iVar3;
	dvd::DVDDirEntry DStack40;
	dvd::DVDDir DStack28;

	iVar3 = 0;
	__ptr = (char *)getDvdPathName(param_1);
	bVar2 = dvd::DVDOpenDir(__ptr, &DStack28);
	if (bVar2) {
		while (iVar1 = dvd::DVDReadDir(&DStack28, &DStack40), iVar1 != 0) {
			iVar3 = iVar3 + 1;
		}
		dvd::DVDCloseDir(&DStack28);
	}
	JKRHeap::sSystemHeap->free(__ptr);
	return iVar3;
}

bool JKRFileCache::becomeCurrent(char *param_1) {
	char *__ptr;
	int iVar1;

	__ptr = (char *)getDvdPathName(param_1);
	iVar1 = dvd::DVDChangeDir(__ptr);
	if (iVar1 != 0) {
		JKRFileLoader::sCurrentVolume = (JKRFileLoader *)this;
		JKRHeap::sSystemHeap->free(this->convertedpath);
		this->convertedpath = __ptr;
		if (this->convertedpath[1] != '\0') {
			strcat(this->convertedpath, "/");
		}
	} else {
		JKRHeap::sSystemHeap->free(__ptr);
	}
	return iVar1 != 0;
}

JKRDvdFinder *JKRFileCache::getFirstFile(char *param_1) {
	char *__ptr;
	JKRDvdFinder *this_00;

	__ptr = (char *)getDvdPathName(param_1);
	this_00 = new (JKRHeap::sSystemHeap, 0) JKRDvdFinder(__ptr);
	JKRHeap::sSystemHeap->free(__ptr);
	if (this_00->attribute != '\x01') {
		delete this_00;
		this_00 = nullptr;
	}
	return this_00;
}

bool JKRFileCache::detachResource(void *param_1) {
	ulong uVar1;
	CCacheBlock *this_00;
	undefined4 uVar2;

	if (this->mbIsMounted == 0) {
		JUTAssertion::getSDevice()->showAssert("JKRFileCache.cpp", 0x1ea, "isMounted()");
		m_Do_printf::OSPanic("JKRFileCache.cpp", 0x1ea, "Halt");
	}
	this_00 = findCacheBlock(param_1);
	if (this_00 == nullptr) {
		uVar2 = 0;
	} else {
		this->cacheblocklist.remove(&this_00->linklist);
		delete this_00;
		uVar2 = 1;
	}
	return uVar2;
}

void *JKRFileCache::getResource(uint param_1, char *param_2) {
	ulong uVar1;
	size_t sVar2;
	char cVar4;
	void *uVar3;
	char acStack280[268];

	if (this->mbIsMounted == 0) {
		JUTAssertion::getSDevice()->showAssert("JKRFileCache.cpp", 0x12f, "isMounted()");
		m_Do_printf::OSPanic("JKRFileCache.cpp", 0x12f, "Halt");
	}
	sVar2 = strlen(this->pathcopy);
	strcpy(acStack280, this->pathcopy);
	cVar4 = findFile(acStack280, param_2);
	if (cVar4 == '\0') {
		uVar3 = 0;
	} else {
		uVar3 = getResource(acStack280 + sVar2);
	}
	return uVar3;
}

JKRFileCache::~JKRFileCache() {
	removeResourceAll();
	if (this->pathcopy) {
		JKRHeap::free(this->pathcopy, this->heap);
	}
	if (this->convertedpath) {
		JKRHeap::sSystemHeap->free(this->convertedpath);
	}
	if (this->filenamecopy) {
		JKRHeap::sSystemHeap->free(this->filenamecopy);
	}
	JKRFileLoader::sVolumeList.remove(&this->mVolumeLink);
}

void JKRFileCache::removeResourceAll() {
	ulong uVar1;
	JSUPtrLink *pJVar2;
	JSUPtrLink *pJVar3;
	JSUPtrLink *this_00;

	if (this->mbIsMounted == 0) {
		JUTAssertion::getSDevice()->showAssert("JKRFileCache.cpp", 0x1b9, "isMounted()");
		m_Do_printf::OSPanic("JKRFileCache.cpp", 0x1b9, "Halt");
	}
	pJVar3 = (this->cacheblocklist).mpHead;
	while (pJVar3) {
		auto ptr = (CCacheBlock *)pJVar3->mpData;
		JKRHeap::free(ptr->buffer, this->heap);
		this->cacheblocklist.remove(&ptr->linklist);
		pJVar2 = pJVar3->mpNext;
		this_00 = (JSUPtrLink *)pJVar3->mpData;
		pJVar3 = pJVar2;
		delete this_00;
	}
}

uint JKRFileCache::readResource(void *param_1, uint param_2, uint param_3, char *param_4) {
	ulong uVar1;
	size_t sVar2;
	char cVar4;
	undefined4 uVar3;
	char acStack280[260];

	if (this->mbIsMounted == 0) {
		JUTAssertion::getSDevice()->showAssert("JKRFileCache.cpp", 0x19c, "isMounted()");
		m_Do_printf::OSPanic("JKRFileCache.cpp", 0x19c, "Halt");
	}
	sVar2 = strlen(this->pathcopy);
	strcpy(acStack280, this->pathcopy);
	cVar4 = findFile(acStack280, param_4);
	if (cVar4 == '\0') {
		uVar3 = 0;
	} else {
		uVar3 = readResource(param_1, param_2, acStack280 + sVar2);
	}
	return uVar3;
}

bool JKRFileCache::removeResource(void *param_1) {
	uint uVar1;
	ulong uVar2;
	CCacheBlock *this_00;
	undefined4 uVar3;

	if (this->mbIsMounted == 0) {
		//uVar2 = JUTAssertion::getSDevice();
		//JUTAssertion::showAssert(uVar2, "JKRFileCache.cpp", 0x1cf, "isMounted()");
		m_Do_printf::OSPanic("JKRFileCache.cpp", 0x1cf, "Halt");
	}
	this_00 = findCacheBlock(param_1);
	if (this_00 == (CCacheBlock *)0x0) {
		uVar3 = 0;
	} else {
		uVar1 = this_00->one - 1;
		this_00->one = uVar1;
		if (uVar1 == 0) {
			JKRHeap::free(param_1, this->heap);
			this->cacheblocklist.remove(&this_00->linklist);
			delete this_00;
		}
		uVar3 = 1;
	}
	return uVar3;
}

JKRFileCache *JKRFileCache::mount(char *filename, JKRHeap *heap, char *param_3) {
	JKRFileCache *filecache;
	size_t sVar1;
	JSUPtrLink *__s1;
	int iVar2;
	JKRFileCache *puVar3;
	JSUPtrLink *pJVar3;

	if ((filename == (char *)0x0) || (*filename != '/')) {
		filecache = (JKRFileCache *)0x0;
	} else {
		sVar1 = strlen(filename);
		pJVar3 = JKRFileLoader::sVolumeList.mpHead;
		if ((sVar1 == 1) || (filename[sVar1 - 1] != '/')) {
			for (; pJVar3 != (JSUPtrLink *)0x0; pJVar3 = pJVar3->mpNext) {
				puVar3 = (JKRFileCache *)pJVar3->mpData;
				if (((puVar3->type == 0x43415348) && (puVar3->pathcopy != (char *)0x0)) &&
					(iVar2 = strcmp(puVar3->pathcopy, filename), iVar2 == 0)) {
					puVar3->refcount = puVar3->refcount + 1;
					return puVar3;
				}
			}
			filecache = new (heap, 0) JKRFileCache(filename, param_3);
		} else {
			filecache = (JKRFileCache *)0x0;
		}
	}
	return filecache;
}

uint JKRFileCache::findFile(char *param_1, char *param_2) {
	uint uVar1;
	size_t sVar2;
	bool bVar4;
	int iVar3;
	uint uVar5;
	char *pcVar6;
	dvd::DVDDirEntry auStack56;
	dvd::DVDDir DStack44;

	uVar5 = 0;
	sVar2 = strlen(param_1);
	bVar4 = dvd::DVDOpenDir(param_1, &DStack44);
	if (bVar4) {
		pcVar6 = param_1 + sVar2;
		do {
			while (true) {
				iVar3 = dvd::DVDReadDir(&DStack44, &auStack56);
				if (iVar3 == 0)
					goto LAB_802b7d34;
				if (auStack56.isDir == 0)
					break;
				*pcVar6 = '/';
				strcpy(pcVar6 + 1, auStack56.name);
				uVar5 = findFile(param_1, param_2);
				if ((uVar5 & 0xff) != 0)
					goto LAB_802b7d34;
				*pcVar6 = '\0';
			}
			iVar3 = strcmp(param_2, auStack56.name);
			uVar1 = __builtin_clz(iVar3);
			uVar5 = uVar1 >> 5;
		} while ((uVar1 >> 5 & 0xff) == 0);
		strcat(param_1, "/");
		strcat(param_1, param_2);
	LAB_802b7d34:
		dvd::DVDCloseDir(&DStack44);
	}
	return uVar5;
}

uint JKRFileCache::readResource(void *param_1, uint param_2, char *param_3) {
	ulong uVar1;
	char *__ptr;
	int iVar2;
	uint len;

	if (this->mbIsMounted == 0) {
		JUTAssertion::getSDevice()->showAssert("JKRFileCache.cpp", 0x158, "isMounted()");
		m_Do_printf::OSPanic("JKRFileCache.cpp", 0x158, "Halt");
	}
	__ptr = getDvdPathName(param_3);
	JKRDvdFile JStack280(__ptr);
	len = 0;
	while (JStack280.mStatus != 0) {
		len = JStack280.fileinfo.length + 0x1f & 0xffffffe0;
		param_2 = param_2 & 0xffffffe0;
		if (param_2 < len) {
			len = param_2;
		}
		auto iVar2 = findCacheBlock(JStack280.fileinfo.startAddr);
		if (iVar2 == 0) {
			JStack280.readData(param_1, len, 0);
		} else {
			//copy_bytes((byte *)param_1, *(byte **)(iVar2 + 0x1c), len);
			memcpy((byte *)param_1, iVar2->buffer, len);
		}
	}
	JKRHeap::sSystemHeap->free(__ptr);
	return len;
}

void *JKRFileCache::getResource(char *param_1) {
	uint size;
	ulong uVar1;
	char *__ptr;
	int iVar2;
	CCacheBlock *this_00;
	void *buff;

	if (this->mbIsMounted == 0) {
		JUTAssertion::getSDevice()->showAssert("JKRFileCache.cpp", 0xed, "isMounted()");
		m_Do_printf::OSPanic("JKRFileCache.cpp", 0xed, "Halt");
	}
	buff = (void *)0x0;
	__ptr = getDvdPathName(param_1);
	JKRDvdFile JStack264(__ptr);
	if (JStack264.mStatus != 0) {
		auto iVar2 = findCacheBlock(JStack264.fileinfo.startAddr);
		if (iVar2 == 0) {
			size = JStack264.fileinfo.length + 0x1f & 0xffffffe0;
			buff = (void *)JKRHeap::alloc(size, 0x20, this->heap);
			if (buff) {
				JStack264.readData(buff, size, 0);
				this_00 = new (JKRHeap::sSystemHeap, 0) CCacheBlock(JStack264.fileinfo.startAddr, JStack264.fileinfo.length, buff);
				this->cacheblocklist.append(&this_00->linklist);
			}
		} else {
			iVar2->one++;
			buff = iVar2->buffer;
		}
	}
	JKRHeap::sSystemHeap->free(__ptr);
	return buff;
}
