#pragma once

#include "../JSupport/JSUPtrList.h"
#include "JKRArchive.h"
//#include "JKRDecomp.h"

using JKRExpandSwitch = int;
using EAllocDirection = int;

struct JKRDecomp;
struct JKRDvdFile;

struct JKRDvdRipper {
	static JSUPtrList sDvdAsyncList;
	static int sSzpBufferSize;
	static byte errorRetry;

	static byte isErrorRetry();
	static void *loadToMainRAM(JKRDvdFile *param_1, uchar *param_2, JKRExpandSwitch shouldexpand, ulong param_4,
							   JKRHeap *heap, EAllocDirection direction, ulong param_7, int *outCompType);

	static JKRArchive__Header *loadToMainRAM(long param_1, uchar *param_2, JKRExpandSwitch param_3, ulong param_4, JKRHeap *param_5,
											 EAllocDirection param_6, ulong param_7, int *param_8);

	static JKRArchive__Header *loadToMainRAM(char *param_1, uchar *param_2, JKRExpandSwitch param_3, ulong param_4, JKRHeap *param_5,
											 EAllocDirection param_6, ulong param_7, int *param_8);
};
