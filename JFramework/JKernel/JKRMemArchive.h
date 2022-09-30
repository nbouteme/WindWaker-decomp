#pragma once

#include <cstring>

#include "JKRArchive.h"

struct JKRMemArchive : public JKRArchive {
	JKRMemArchive() = default;

	char *mpFileData;
	byte mbInitialized;

	static uchar *fetchResource_subroutine(uchar *param_1, ulong param_2, uchar *param_3, ulong param_4, int param_5);

	virtual ~JKRMemArchive();
	virtual void *fetchResource(SDIFileEntry *param_1, uint *param_2) override;
	virtual void *fetchResource(void *param_1, uint param_2, SDIFileEntry *param_3, uint *param_4) override;

	JKRMemArchive(long param_1, EMountDirection param_2);
};
