#pragma once

#include <cctype>
#include <cstring>

#include "../JSupport/JSUPtrList.h"
#include "JKRArchive.h"
#include "JKRDvdFinder.h"
#include "JKRHeap.h"

struct JKRFileCache : public JKRFileLoader {
	JKRHeap *heap;
	JSUPtrList cacheblocklist;
	char *pathcopy, *convertedpath, *filenamecopy;

	struct CCacheBlock {
		JSUPtrLink linklist;
		uint one;
		uint start;
		uint length;
		void *buffer;

		CCacheBlock(ulong start, ulong len, void *buffer);
	};

	static int mount(char *filename, JKRHeap *heap, char *param_3);

	JKRFileCache(char *param_1, char *param_2);

	void convStrLower(char *param_1);
	CCacheBlock *findCacheBlock(void *param_1);
	CCacheBlock *findCacheBlock(ulong param_1);
	void *getFsResource(char *param_1);
	void *getNameResource(ulong param_1, char *param_2);
	uint readFsResource(void *param_1, ulong param_2, char *param_3);
	uint readNameResource(void *param_1, ulong param_2, ulong param_3, char *param_4);
	char *getDvdPathName(char *param_1);

	virtual uint getResSize(void *param_1) override;
	virtual ushort countFile(char *param_1) override;
	virtual bool becomeCurrent(char *param_1) override;
	virtual JKRDvdFinder *getFirstFile(char *param_1) override;
	virtual bool detachResource(void *param_1) override;
	virtual void *getResource(uint param_1, char *param_2) override;
	virtual void removeResourceAll() override;
	virtual uint readResource(void *param_1, uint param_2, uint param_3, char *param_4) override;
	virtual bool removeResource(void *param_1) override;
	virtual uint readResource(void *param_1, uint param_2, char *param_3) override;
	virtual ~JKRFileCache() override;

	uint findFile(char *param_1, char *param_2);
	void *getResource(char *param_1);
};