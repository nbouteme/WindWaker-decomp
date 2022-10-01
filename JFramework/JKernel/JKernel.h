#pragma once

#include <doltypes.h>

#include <dolphin/os.h>

#include <cstring>

struct JKRDvdFile;
struct JKRHeap;

namespace JKernel {
	extern char rootPath$2460[];
	extern void JKRDefaultMemoryErrorRoutine(JKRHeap *param_1, u32 param_2, u32 param_3);
	extern int DBfoundSize, DBfoundOffset;
	extern void *DBfoundBlock, *DBnewFreeBlock, *DBnewUsedBlock;
	extern os::OSThread *preEnd;
	extern byte isInitMutex;
	extern void *szpBuf;
	extern void *szpEnd;
	extern byte *refBuf, *refEnd;
	extern byte *refCurrent;
	extern os::OSMutex decompMutex;
	extern uint transLeft;
	extern uint readCount;
	extern uint srcOffset;
	extern uint fileOffset;
	extern uint maxDest;
	extern void *srcLimit;
	extern JKRDvdFile *srcFile;
	extern byte *dmaCurrent, *dmaBuf, *dmaEnd;

	void *firstSrcData();
	byte *nextSrcData(byte *param_1);
	uint dmaBufferFlush(ulong param_1);
	undefined4 decompSZS_subroutine(char *param_1, uint param_2);
	int decompSZS_subroutine(char *param_1, byte *param_2);
	int JKRDecompressFromDVD(JKRDvdFile *param_1, void *param_2, uint param_3, uint param_4, uint param_5, uint param_6);
	void JKRDecompressFromDVDToAram(JKRDvdFile *srcFile, undefined4 blksize, int totalsize, undefined4 maxDest, undefined4 fileOffset, int srcOffset);
}

void *operator new(ulong size);
void *operator new(ulong size, int param_2);
void *operator new(ulong size, void *an) {
	return an;
}
void *operator new(ulong size, JKRHeap *heap, int align);
void *operator new[](unsigned long param_1);
void *operator new[](unsigned long param_1, int param_2);
void *operator new[](unsigned long param_1, JKRHeap *param_2, int param_3);

void operator delete(void *ptr);
void operator delete[](void *param_1);