#pragma once

#include <dolphin/os.h>
#include "../JSupport/JSUPtrList.h"
#include "JKRDisposer.h"

struct TState {
	char *used_size;
	char *check_code;
	char _padd[8];
	JKRHeap *heap;
	char *id;
};

struct JKRExpHeap;

struct JKRHeap : public JKRDisposer {
	static void (*mErrorHandler)(JKRHeap *, u32, u32);

	static char sDefaultFillFlag;

	static JKRExpHeap *sRootHeap;
	static JKRExpHeap *sSystemHeap;
	static JKRHeap *sCurrentHeap;

	static char *mCodeStart;
	static int mMemorySize;
	static char *mCodeEnd;
	static void *mUserRamStart;
	static void *mUserRamEnd;

	os::OSMutex mMutex;
	void *mpDataBegin;
	void *mpDataEnd;
	unsigned long mSize;
	JSUPtrList mChildHeap;
	JSUPtrLink mChildHeapLink;
	JSUPtrList mList;
	bool mbReportErrors;
	bool mbReportWarnings;
	char mFillFlag;
	char field1_0x6c;

	JKRHeap(void *pData, unsigned long size, JKRHeap *pParent, bool pReportErrors);
	virtual ~JKRHeap();
	static JKRHeap *findFromRoot(void *param_1);
	virtual void destroy(){};

	JKRHeap *becomeSystemHeap();
	JKRHeap *becomeCurrentHeap();
	static bool initArena(char **p1, unsigned long *p2, int p3);
	static void free(void *ptr, JKRHeap *p2);
	JKRHeap *find(void *ptr);

	static void *alloc(unsigned long size, int param_2, JKRHeap *pHeap);
	virtual void *do_alloc(unsigned long size, int param_2) = 0;
	void *alloc(unsigned long size, int param_2);

	//static void free(void *ptr, JKRHeap *r);
	virtual void do_free(void *ptr) = 0;
	void free(void *ptr);

	//static void destroy(void *ptr, JKRHeap *r);
	virtual void do_destroy() = 0;

	virtual void callAllDisposer();

	virtual void do_freeAll() = 0;
	void freeAll();

	virtual void do_freeTail() = 0;
	void freeTail();

	static int resize(void *a, unsigned long b, JKRHeap *c);
	int resize(void *param_1, unsigned long param_2);
	virtual int do_resize(void *a, unsigned long b) = 0;

	int do_changeGroupID(char param_1);
	void state_register(TState *param_1, unsigned long p2);
	void state_dump(TState *param_1);
	unsigned state_compare(TState *a, TState *b);

	static int getSize(void *p, JKRHeap *);
	int getSize(void *param_1);
	virtual int do_getSize(void *param_1) = 0;

	uint getFreeSize();
	virtual uint do_getFreeSize() = 0;

	void *getMaxFreeBlock();

	virtual void *do_getMaxFreeBlock() = 0;

	uint getTotalFreeSize();

	virtual uint do_getTotalFreeSize() = 0;

	int getCurrentGroupId();
	virtual int do_getCurrentGroupId() = 0;

	virtual int dump_sort();

	virtual void dump() = 0;

	unsigned getMaxAllocatableSize(int param_1);
	void dispose_subroutine(ulong param_1, ulong param_2);
	int dispose(void *param_1, ulong param_2);
	void dispose(void *param_1, void *param_2);
	void dispose();
	static void copyMemory(void *param_1, void *param_2, ulong param_3);
	bool setErrorFlag(bool f);
	static void *setErrorHandler(void (*param_1)(JKRHeap *, u32, u32));

	virtual uint getHeapType() = 0;
	virtual bool check() = 0;
};
