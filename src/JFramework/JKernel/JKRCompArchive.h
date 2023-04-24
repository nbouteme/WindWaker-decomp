#include <machine/dolphin/printf.h>

#include <cmath>

#include "../JSupport/JSUIosBase.h"
#include "../JUtility/JUTAssert.h"
#include "JKRAramHeap.h"
#include "JKRArchive.h"
#include "JKRDvdAramRipper.h"
#include "JKRDvdArchive.h"
#include "JKRDvdRipper.h"
#include "JKRExpHeap.h"
#include "JKRHeap.h"
#include "JKRMemArchive.h"
#include "JKernel.h"

struct JKRCompArchive : public JKRArchive {
	JKRAramHeap *aramheapptr;
	int archiveData;  // offset?
	JKRDvdFile *dvdfile;
	int mSizeOfMemPart;
	int mSizeOfAramPart;

	virtual bool removeResource(void *param_1) override;

	virtual void removeResourceAll() override;

	int open(int entry);

	JKRCompArchive(long param_1, EMountDirection param_2);

	virtual ~JKRCompArchive();
	virtual uint getExpandedResSize(void *dataPtr) override;
	virtual void *fetchResource(void *param_1, uint param_2, SDIFileEntry *param_3, uint *param_4) override;
	virtual void *fetchResource(SDIFileEntry *param_1, uint *param_2) override;
};