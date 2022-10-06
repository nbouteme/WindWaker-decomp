#pragma once

#include <cmath>

#include "JKRArchive.h"
#include "JKRDvdRipper.h"
#include "JKRHeap.h"
#include "JKernel.h"

struct JKRDvdArchive : public JKRArchive {
	JKRDvdFile *dvdfile;

	virtual ~JKRDvdArchive();
	virtual uint getExpandedResSize(void *param_1) override;

	virtual void *fetchResource(void *param_1, uint param_2, SDIFileEntry *fileEntry, uint *param_4) override;
	virtual void *fetchResource(SDIFileEntry *fileEntry, uint *param_2) override;

	static ulong fetchResource_subroutine(long param_1, ulong param_2, ulong size, uchar *param_4, ulong param_5, int param_6, int isSZP);
	static uint fetchResource_subroutine(long param_1, ulong param_2, ulong param_3, JKRHeap *param_4, int param_5, int param_6, uchar **param_7);

	int open(uint __file);
	JKRDvdArchive(long param_1, EMountDirection param_2);
};
