#include "JKRMemArchive.h"
#include "JKernel.h"
#include <machine/dolphin/printf.h>
#include "../JUtility/JUTAssert.h"

JKRMemArchive::JKRMemArchive(long param_1, EMountDirection param_2) : JKRArchive(param_1, Mem) {
	uint uVar1;

	mbIsMounted = 0;
	mMountDirection = param_2;
	//uVar1 = open(param_1, mMountDirection);
	if ((uVar1 & 0xff) != 0) {
		type = 0x52415243;
		loaderfilename = mpStrData + mpNodes->stroffset;
		JKRFileLoader::sVolumeList.prepend(&mVolumeLink);
		mbIsMounted = 1;
	}
}

JKRMemArchive::~JKRMemArchive() {
	if (mbIsMounted == 1) {
		if (this->mbInitialized) {
			auto __ptr = mpHeader;
			if (__ptr) {
				JKRHeap::free(__ptr, mpHeap);
			}
		}
		JKRFileLoader::sVolumeList.remove(&mVolumeLink);
		mbIsMounted = 0;
	}
}

uchar *JKRMemArchive::fetchResource_subroutine(uchar *param_1, ulong param_2, uchar *param_3, ulong param_4, int param_5) {
	if (param_5 == 0) {
		if (param_4 < param_2) {
			param_2 = param_4;
		}
		//copy_bytes(param_3, param_1, param_2);
		memcpy(param_3, param_1, param_2);
	} else if ((param_5 < 0) || (2 < param_5)) {
		m_Do_printf::OSPanic("JKRMemArchive.cpp", 0x2bf, ":::??? bad sequence\n");
		param_2 = 0;
	} else {
		param_2 = (uint)param_1[7] |
				  (uint)param_1[6] << 8 | (uint)param_1[4] << 0x18 | (uint)param_1[5] << 0x10;
		if (param_4 < param_2) {
			param_2 = param_4;
		}
		JKRDecomp::orderSync(param_1, param_3, param_2, 0);
	}
	return (uchar *)param_2;
}

void *JKRMemArchive::fetchResource(SDIFileEntry *param_1, uint *param_2) {
	uint uVar1;

	if (mbIsMounted == 0) {
		JUTAssertion::getSDevice()->showAssert("JKRMemArchive.cpp", 0x217, "isMounted()");
		m_Do_printf::OSPanic("JKRMemArchive.cpp", 0x217, "Halt");
	}
	if (param_1->mpData == (void *)0x0) {
		param_1->mpData = (void *)(this->mpFileData + param_1->mDataOffs);
	}
	if (param_2) {
		*param_2 = param_1->mDataSize;
	}
	return param_1->mpData;
}

void *JKRMemArchive::fetchResource(void *param_1, uint param_2, SDIFileEntry *param_3, uint *param_4) {
	uint uVar1;
	uint length;
	int iVar2;

	if (!mbIsMounted == 0) {
		JUTAssertion::getSDevice()->showAssert("JKRMemArchive.cpp", 0x23f, "isMounted()");
		m_Do_printf::OSPanic("JKRMemArchive.cpp", 0x23f, "Halt");
	}
	length = param_3->mDataSize;
	if (param_2 < param_3->mDataSize) {
		length = param_2;
	}
	if ((byte *)param_3->mpData == (byte *)0x0) {
		if (((uint)param_3->mAttrAndNameOffs >> 0x18 & 4) == 0) {
			iVar2 = 0;
		} else if (((uint)param_3->mAttrAndNameOffs >> 0x18 & 0x80) == 0) {
			iVar2 = 1;
		} else {
			iVar2 = 2;
		}
		return JKRMemArchive::fetchResource_subroutine((uchar *)(this->mpFileData + param_3->mDataOffs), length,
													   (uchar *)param_1, param_2, iVar2);
	} else {
		//copy_bytes((byte *)param_1, (byte *)param_3->mpData, (int)length);
		memcpy((byte *)param_1, (byte *)param_3->mpData, (int)length);
	}
	if (param_4) {
		*param_4 = length;
	}
	return param_1;
}
