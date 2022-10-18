#include "JKRMemArchive.h"

#include <machine/dolphin/printf.h>

#include <JFramework/JKernel/JKRDvdRipper.h>

#include <cstdlib>

#include "../JUtility/JUTAssert.h"
#include "JKernel.h"

JKRMemArchive::JKRMemArchive(long param_1, EMountDirection param_2) : JKRArchive(param_1, Mem) {
	uint uVar1;

	mbIsMounted = 0;
	mMountDirection = param_2;
	uVar1 = open(param_1, mMountDirection);
	if ((uVar1 & 0xff) != 0) {
		type = 0x52415243;
		loaderfilename = mpStrData + mpNodes->stroffset;
		JKRFileLoader::sVolumeList.prepend(&mVolumeLink);
		mbIsMounted = 1;
	}
}

int JKRMemArchive::open(long param_1, EMountDirection param_2) {
	JKRArchive__Header *pHeader;
	ulong uVar1;
	JKRArchive__DataHeader *pJVar2;

	mpHeader = NULL;
	mpDataHeader = NULL;
	this->mpFileData = 0;
	mpNodes = NULL;
	mpFileEntries = NULL;
	mpStrData = NULL;
	this->mbInitialized = 0;
	mMountDirection = param_2;
	if (mMountDirection == 1) {
		pHeader = JKRDvdRipper::loadToMainRAM(param_1, NULL, 1, 0, mpHeap, 1, 0, (int*)&mCompressionType);
		mpHeader = pHeader;
	} else {
		pHeader = JKRDvdRipper::loadToMainRAM(param_1, NULL, 1, 0, mpHeap, 2, 0, (int*)&mCompressionType);
		mpHeader = pHeader;
	}
	pHeader = mpHeader;
	if (pHeader == NULL) {
		mMountMode = None;
	} else {
		if (pHeader->mSignature != 0x52415243) {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "JKRMemArchive.cpp", 0x1a2, "mArcHeader->signature ==\'RARC\'");
			m_Do_printf::OSPanic("JKRMemArchive.cpp", 0x1a2, "Halt");
		}
		pHeader = mpHeader;
		mpDataHeader = (JKRArchive__DataHeader *)((char *)&pHeader->mSignature + pHeader->mHeaderSize);
		pJVar2 = mpDataHeader;
		mpNodes = (JKRArchive__Node *)((char *)&pJVar2->mNodeCount + pJVar2->mNodeOffs);
		pJVar2 = mpDataHeader;
		mpFileEntries = (SDIFileEntry *)((char *)&pJVar2->mNodeCount + pJVar2->mFileEntryOffs);
		pJVar2 = mpDataHeader;
		mpStrData = ((char *)&pJVar2->mNodeCount + pJVar2->mStrTableOffs);
		pHeader = mpHeader;
		this->mpFileData = ((char *)&pHeader->mSignature + pHeader->mHeaderSize + pHeader->mFileDataOffs);
		this->mbInitialized = 1;
	}
	if (mMountMode == None) {
		m_Do_printf::OSReport(":::Cannot alloc memory [%s][%d]\n", "JKRMemArchive.cpp", 0x1b8);
	}
	return mMountMode != None;
}

int JKRMemArchive::open(JKRArchive__Header *param_1, uint param_2, uint breakflag) {
	uint uVar1;
	ulong uVar2;
	JKRArchive__Header *pJVar3;
	JKRArchive__DataHeader *pJVar4;
	JKRHeap *pJVar5;

	mpHeader = param_1;
	if ((mpHeader)->mSignature != 0x52415243) {
		auto uVar2 = JUTAssertion::getSDevice();
		JUTAssertion::showAssert(uVar2, "JKRMemArchive.cpp", 0x1d7, "mArcHeader->signature ==\'RARC\'");
		m_Do_printf::OSPanic("JKRMemArchive.cpp", 0x1d7, "Halt");
	}
	pJVar3 = mpHeader;
	mpDataHeader = (JKRArchive__DataHeader *)((char *)&pJVar3->mSignature + pJVar3->mHeaderSize);
	pJVar4 = mpDataHeader;
	mpNodes = (JKRArchive__Node *)((char *)&pJVar4->mNodeCount + pJVar4->mNodeOffs);
	pJVar4 = mpDataHeader;
	mpFileEntries = (SDIFileEntry *)(char *)(&pJVar4->mNodeCount + pJVar4->mFileEntryOffs);
	pJVar4 = mpDataHeader;
	mpStrData = ((char *)&pJVar4->mNodeCount + pJVar4->mStrTableOffs);
	pJVar3 = mpHeader;
	this->mpFileData = ((char *)&pJVar3->mSignature + pJVar3->mHeaderSize + pJVar3->mFileDataOffs);
	this->mbInitialized = breakflag;
	pJVar5 = JKRHeap::findFromRoot(param_1);
	mpHeap = pJVar5;
	mCompressionType = NotCompressed;
	return 1;
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

ulong JKRMemArchive::fetchResource_subroutine(uchar *param_1, ulong param_2, uchar *param_3, ulong param_4, int param_5) {
	if (param_5 == 0) {
		if (param_4 < param_2) {
			param_2 = param_4;
		}
		// copy_bytes(param_3, param_1, param_2);
		memcpy(param_3, param_1, param_2);
	} else if ((param_5 < 0) || (2 < param_5)) {
		m_Do_printf::OSPanic("JKRMemArchive.cpp", 0x2bf, ":::??? bad sequence\n");
		param_2 = 0;
	} else {
		param_2 = (uint)param_1[7] | (uint)param_1[6] << 8 | (uint)param_1[4] << 0x18 | (uint)param_1[5] << 0x10;
		if (param_4 < param_2) {
			param_2 = param_4;
		}
		JKRDecomp::orderSync(param_1, param_3, param_2, 0);
	}
	return param_2;
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
	if (param_3->mpData) {
		if (((uint)param_3->mAttrAndNameOffs >> 0x18 & 4) == 0) {
			iVar2 = 0;
		} else if (((uint)param_3->mAttrAndNameOffs >> 0x18 & 0x80) == 0) {
			iVar2 = 1;
		} else {
			iVar2 = 2;
		}
		length = JKRMemArchive::fetchResource_subroutine((uchar *)(this->mpFileData + param_3->mDataOffs), length,
														 (uchar *)param_1, param_2, iVar2);
	} else {
		// copy_bytes((byte *)param_1, (byte *)param_3->mpData, (int)length);
		memcpy((byte *)param_1, param_3->mpData, (int)length);
	}
	if (param_4) {
		*param_4 = length;
	}
	return param_1;
}
