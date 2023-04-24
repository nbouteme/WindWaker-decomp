#pragma once

#include "JKRHeap.h"

struct JKRExpHeap : public JKRHeap {
	struct CMemBlock {
		short id;
		byte fill2, fill3;
		uint addrsize;
		CMemBlock *prev, *next;

		void initiate(CMemBlock *param_1, CMemBlock *param_2, ulong param_3, uchar param_4, uchar param_5);

		intptr_t allocFore(ulong param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5);

		CMemBlock *allocBack(ulong param_1, uchar param_2, uchar param_3, uchar param_4, uchar param_5);

		void free(void *__ptr);

		static CMemBlock *getHeapBlock(void *param_1);
	};

	CMemBlock *freelist, *freelistend;
	CMemBlock *head, *tail;
	char field1_0x6c, gid;
	char field3_0x6e;
	os::OSMutex mMutex;
	CMemBlock *field10_0x84;

	static void removeUsedBlock(JKRExpHeap *self, CMemBlock *param_1);
	static JKRHeap *createRoot(int param_1, bool param_2);
	static JKRExpHeap *create(ulong param_1, JKRHeap *param_2, bool param_3);

	virtual void dump();
	virtual uint getHeapType();
	virtual uint do_getFreeSize();
	virtual int do_getCurrentGroupId();
	virtual uint do_getTotalFreeSize() override;
	virtual void *do_getMaxFreeBlock() override;
	virtual void destroy() override;
	virtual void *do_alloc(ulong param_1, int param_2);
	virtual int do_resize(void *param_1, ulong param_2) override;
	virtual int do_getSize(void *param_1);
	virtual bool check();

	void recycleFreeBlock(CMemBlock *param_1);
	void joinTwoBlocks(CMemBlock *param_1);
	void setFreeBlock(CMemBlock *param_1, CMemBlock *param_2, CMemBlock *param_3);
	int getTotalUsedSize();
	void do_destroy();
	JKRExpHeap(void *param_1, ulong param_2, JKRHeap *param_3, bool param_4);
	virtual ~JKRExpHeap();
	void appendUsedList(CMemBlock *param_1);
	CMemBlock *allocFromTail(uint param_1);
	CMemBlock *allocFromTail(uint param_1, int param_2);
	CMemBlock *allocFromHead(uint param_1, int param_2);
	CMemBlock *allocFromHead(ulong param_1);
	void do_free(void *param_1);
	void do_freeAll();
	void do_freeTail();
	undefined do_changeGroupID(uchar newid);
	void removeFreeBlock(CMemBlock *param_1);
};