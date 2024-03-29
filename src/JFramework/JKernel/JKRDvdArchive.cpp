#include "JKRDvdArchive.h"

#include <machine/dolphin/printf.h>

#include <cstdlib>

#include "../JSupport/JSUIosBase.h"
#include "JKRExpHeap.h"
#include "JKRHeap.h"
#include "JKernel.h"

struct Yaz0Header {
	int magic;
	int size;
	int padding[6];
};

JKRDvdArchive::~JKRDvdArchive() {
	JKRArchive__DataHeader *__ptr;
	int *__ptr_00;
	JKRDvdFile *pJVar1;
	short in_r4;
	uint uVar2;
	SDIFileEntry *pSVar3;

	// if (!this)
	//	return;
	if (mbIsMounted != 1)
		return;
	if (mpDataHeader != (JKRArchive__DataHeader *)0x0) {
		pSVar3 = mpFileEntries;
		for (uVar2 = 0; __ptr = mpDataHeader, uVar2 < (uint)__ptr->mFileEntryCount;
			 uVar2 = uVar2 + 1) {
			if (entries_data[uVar2]) {
				JKRHeap::free(entries_data[uVar2], mpHeap);
			}
			pSVar3 = pSVar3 + 1;
		}
		JKRHeap::free(__ptr, mpHeap);
		mpDataHeader = (JKRArchive__DataHeader *)0x0;
	}
	__ptr_00 = expandedSizes;
	if (__ptr_00 != (int *)0x0) {
		JKRHeap::free(__ptr_00, (JKRHeap *)0x0);
		expandedSizes = (int *)0x0;
	}
	pJVar1 = this->dvdfile;
	if ((pJVar1 != (JKRDvdFile *)0x0) && (pJVar1 != (JKRDvdFile *)0x0)) {
		delete this->dvdfile;
	}
	JKRFileLoader::sVolumeList.remove(&mVolumeLink);
	mbIsMounted = 0;
}

uint JKRDvdArchive::getExpandedResSize(void *param_1) {
	uint uVar1;
	SDIFileEntry *pSVar2;
	Yaz0Header auStack64;

	if (this->expandedSizes == (int *)0x0) {
		uVar1 = getResSize(param_1);
	} else {
		pSVar2 = findPtrResource(param_1);
		if (pSVar2 == (SDIFileEntry *)0x0) {
			uVar1 = 0xffffffff;
		} else if (((uint)pSVar2->mAttrAndNameOffs >> 0x18 & 4) == 0) {
			uVar1 = getResSize(param_1);
		} else {
			uVar1 = getExpandSize(pSVar2);
			if (uVar1 == 0) {
				JKRDvdRipper::loadToMainRAM(this->resId, (uchar *)&auStack64, 2, 0x20, (JKRHeap *)0x0, 1,
											(u64) & this->mpHeader->mSignature + pSVar2->mDataOffs, (int *)0x0);
				os::DCInvalidateRange((uchar *)&auStack64, 0x20);
				uVar1 = auStack64.size;
				setExpandSize(pSVar2, uVar1);
			}
		}
	}
	return uVar1;
}

ulong JKRDvdArchive::fetchResource_subroutine(long param_1, ulong param_2, ulong size, uchar *param_4, ulong param_5, int param_6,
											  int isSZP) {
	uint uVar1;
	uint uVar2;
	uint uVar3;
	Yaz0Header auStack64;

	uVar2 = size + 0x1f & 0xffffffe0;
	uVar1 = param_5 & 0xffffffe0;
	if (isSZP == 1) {
		m_Do_printf::OSPanic("JKRDvdArchive.cpp", 0x25b, "Sorry, not prepared for SZP archive.\n");
		return 0;
	}
	if (isSZP < 1) {
		if (-1 < isSZP) {
			if (param_6 == 0) {
				if (uVar1 < uVar2) {
					uVar2 = uVar1;
				}
				JKRDvdRipper::loadToMainRAM(param_1, param_4, 0, uVar2, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
				return uVar2;
			}
			if ((-1 < param_6) && (param_6 < 3)) {
				JKRDvdRipper::loadToMainRAM(param_1, (uchar *)&auStack64, 2, 0x20, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
				os::DCInvalidateRange((uchar *)&auStack64, 0x20);
				uVar3 = auStack64.size;
				uVar2 = uVar3 + 0x1f & 0xffffffe0;
				if (uVar1 < uVar2) {
					uVar2 = uVar1;
				}
				JKRDvdRipper::loadToMainRAM(param_1, param_4, 1, uVar2, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
				return uVar3;
			}
		LAB_802bb3f0:
			if (uVar1 < size) {
				size = uVar1;
			}
			JKRDvdRipper::loadToMainRAM(param_1, param_4, 1, size, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
			return size;
		}
	} else if (isSZP < 3)
		goto LAB_802bb3f0;
	m_Do_printf::OSPanic("JKRDvdArchive.cpp", 0x261, ":::??? bad sequence\n");
	return 0;
}

void *JKRDvdArchive::fetchResource(void *param_1, uint param_2, SDIFileEntry *fileEntry, uint *param_4) {
	uint uVar1;
	uint pvVar2;
	uint size;
	int iVar4;

	if (this->mbIsMounted == 0) {
		// uVar1 = JUTAssertion::getSDevice();
		// JUTAssertion::showAssert(uVar1, "JKRDvdArchive.cpp", 0x1e9, "isMounted()");
		m_Do_printf::OSPanic("JKRDvdArchive.cpp", 0x1e9, "Halt");
	}
	size = fileEntry->mDataSize;
	if (((uint)fileEntry->mAttrAndNameOffs >> 0x18 & 4) == 0) {
		iVar4 = 0;
	} else if (((uint)fileEntry->mAttrAndNameOffs >> 0x18 & 0x80) == 0) {
		iVar4 = 1;
	} else {
		iVar4 = 2;
	}

#ifndef PTR64
	auto &d = fileEntry->mpData;
#else
	int idx = fileEntry - mpFileEntries;
	ASSERT(idx >= 0 && idx < mpDataHeader->mFileEntryCount);
	auto &d = entries_data[idx];
#endif

	if (d) {
		size = fetchResource_subroutine(this->resId, (u64) & this->mpHeader->mSignature + fileEntry->mDataOffs,
										size, (uchar *)param_1, param_2 & 0xffffffe0, iVar4,
										this->mCompressionType);
	} else {
		if ((iVar4 == 2) &&
			(pvVar2 = getExpandSize(fileEntry), pvVar2)) {
			size = pvVar2;
		}
		if (param_2 < size) {
			size = param_2;
		}
		JKRHeap::copyMemory(param_1, d, size);
	}
	if (param_4) {
		*param_4 = size;
	}
	return param_1;
}

uint JKRDvdArchive::fetchResource_subroutine(long param_1, ulong param_2, ulong param_3, JKRHeap *param_4, int param_5, int param_6,
											 uchar **param_7) {
	uchar *puVar1;
	ulong uVar2;
	uint uVar3;
	Yaz0Header auStack96;

	uVar3 = param_3 + 0x1f & 0xffffffe0;
	if (param_6 == 1) {
		m_Do_printf::OSPanic("JKRDvdArchive.cpp", 0x2ab, "Sorry, not prepared for SZP archive.\n");
		return 0;
	}
	if (param_6 < 1) {
		if (-1 < param_6) {
			if (param_5 == 0) {
				puVar1 = (uchar *)JKRHeap::alloc(uVar3, 0x20, param_4);
				if (puVar1 == (uchar *)0x0) {
					// uVar2 = JUTAssertion::getSDevice();
					// JUTAssertion::showAssert(uVar2, "JKRDvdArchive.cpp", 0x277, "buffer != 0");
					m_Do_printf::OSPanic("JKRDvdArchive.cpp", 0x277, "Halt");
				}
				JKRDvdRipper::loadToMainRAM(param_1, puVar1, 0, uVar3, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
				*param_7 = puVar1;
				return uVar3;
			}
			if ((-1 < param_5) && (param_5 < 3)) {
				JKRDvdRipper::loadToMainRAM(param_1, (uchar *)&auStack96, 2, 0x20, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
				os::DCInvalidateRange((uchar *)&auStack96, 0x20);
				uVar3 = auStack96.size;
				puVar1 = (uchar *)JKRHeap::alloc(uVar3, 0x20, param_4);
				if (puVar1 == (uchar *)0x0) {
					// uVar2 = JUTAssertion::getSDevice();
					// JUTAssertion::showAssert(uVar2, "JKRDvdArchive.cpp", 0x294, "buffer");
					m_Do_printf::OSPanic("JKRDvdArchive.cpp", 0x294, "Halt");
				}
				JKRDvdRipper::loadToMainRAM(param_1, puVar1, 1, uVar3, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
				*param_7 = puVar1;
				return uVar3;
			}
		LAB_802bb62c:
			puVar1 = (uchar *)JKRHeap::alloc(uVar3, 0x20, param_4);
			if (puVar1 == (uchar *)0x0) {
				// uVar2 = JUTAssertion::getSDevice();
				// JUTAssertion::showAssert(uVar2, "JKRDvdArchive.cpp", 0x2a0, "buffer");
				m_Do_printf::OSPanic("JKRDvdArchive.cpp", 0x2a0, "Halt");
			}
			JKRDvdRipper::loadToMainRAM(param_1, puVar1, 1, param_3, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
			*param_7 = puVar1;
			return uVar3;
		}
	} else if (param_6 < 3)
		goto LAB_802bb62c;
	m_Do_printf::OSPanic("JKRDvdArchive.cpp", 0x2b0, ":::??? bad sequence\n");
	return 0;
}

void *JKRDvdArchive::fetchResource(SDIFileEntry *fileEntry, uint *param_2) {
	ulong uVar1;
	uint uVar2;
	int iVar3;
	uchar *local_18;
	uint local_14;

	if (this->mbIsMounted == 0) {
		// uVar1 = JUTAssertion::getSDevice();
		// JUTAssertion::showAssert(uVar1, "JKRDvdArchive.cpp", 0x19d, "isMounted()");
		m_Do_printf::OSPanic("JKRDvdArchive.cpp", 0x19d, "Halt");
	}
	if (param_2 == (uint *)0x0) {
		param_2 = &local_14;
	}
	if (((uint)fileEntry->mAttrAndNameOffs >> 0x18 & 4) == 0) {
		iVar3 = 0;
	} else if (((uint)fileEntry->mAttrAndNameOffs >> 0x18 & 0x80) == 0) {
		iVar3 = 1;
	} else {
		iVar3 = 2;
	}
#ifndef PTR64
	auto &d = fileEntry->mpData;
#else
	int idx = fileEntry - mpFileEntries;
	ASSERT(idx >= 0 && idx < mpDataHeader->mFileEntryCount);
	auto &d = entries_data[idx];
#endif
	if (d == (void *)0x0) {
		uVar2 = JKRDvdArchive::fetchResource_subroutine(this->resId, (u64) & this->mpHeader->mSignature + fileEntry->mDataOffs,
														fileEntry->mDataSize, this->mpHeap, iVar3, this->mCompressionType, &local_18);
		*param_2 = uVar2;
		if (uVar2 == 0) {
			return (void *)0x0;
		}
		d = local_18;
		if (iVar3 == 2) {
			setExpandSize(fileEntry, *param_2);
		}
	} else if (iVar3 == 2) {
		uVar2 = getExpandSize(fileEntry);
		*param_2 = uVar2;
	} else {
		*param_2 = fileEntry->mDataSize;
	}
	return d;
}

int JKRDvdArchive::open(uint __file) {
	int iVar1;
	JKRDvdFile *pJVar2;
	SDIFileEntry *__ptr;
	JKRArchive__DataHeader *pJVar3;
	int *piVar4;
	int iVar5;
	uint uVar6;
	SDIFileEntry *pSVar7;

	mpDataHeader = nullptr;
	mpHeader = nullptr;
	mpNodes = nullptr;
	mpFileEntries = nullptr;
	mpStrData = nullptr;
	pJVar2 = new (JKRHeap::sSystemHeap, 0) JKRDvdFile(__file);
	this->dvdfile = pJVar2;
	if (!this->dvdfile) {
		mMountMode = None;
		return 0;
	}
	// is __ptr a SDIFileEntry? or JKRArchive__DataHeader?
	__ptr = (SDIFileEntry *)JKRHeap::sSystemHeap->alloc(0x20, 0x20);
	if (!__ptr) {
		mMountMode = None;
	} else {
		JKRDvdRipper::loadToMainRAM(__file, (uchar *)__ptr, 1, 0x20, (JKRHeap *)0x0, 1, 0, (int *)&mCompressionType);
		iVar5 = -0x20;
		if (mMountDirection == 1) {
			iVar5 = 0x20;
		}
		pJVar3 = (JKRArchive__DataHeader *)
			JKRHeap::alloc(__ptr->mDataSize, iVar5, mpHeap);
		mpDataHeader = pJVar3;
		pJVar3 = mpDataHeader;
		if (pJVar3 == (JKRArchive__DataHeader *)0x0) {
			mMountMode = None;
		} else {
			JKRDvdRipper::loadToMainRAM(__file, (uchar *)pJVar3, 1, __ptr->mDataSize, (JKRHeap *)0x0, 1, 0x20, (int *)0x0);
			pJVar3 = mpDataHeader;
			mpNodes = (JKRArchive__Node *)((u64)&pJVar3->mNodeCount + pJVar3->mNodeOffs);
			pJVar3 = mpDataHeader;
			mpFileEntries = (SDIFileEntry *)((u64)&pJVar3->mNodeCount + pJVar3->mFileEntryOffs);
			pJVar3 = mpDataHeader;
			mpStrData = (char *)((u64)&pJVar3->mNodeCount + pJVar3->mStrTableOffs);
			expandedSizes = (int *)0x0;
#ifdef PTR64
			entries_data = (void **)calloc(sizeof(void *), mpDataHeader->mFileEntryCount);
#endif
			uVar6 = 0;
			pSVar7 = mpFileEntries;
			for (iVar1 = (mpDataHeader)->mFileEntryCount; iVar1 != 0; iVar1 = iVar1 + -1) {
				if (((uint)pSVar7->mAttrAndNameOffs >> 0x18 & 1) != 0) {
					uVar6 = uVar6 | (uint)pSVar7->mAttrAndNameOffs >> 0x18 & 4;
				}
				pSVar7 = pSVar7 + 1;
			}
			if (uVar6 != 0) {
				iVar5 = abs(iVar5);
				piVar4 = (int *)JKRHeap::alloc((mpDataHeader)->mFileEntryCount * sizeof(void *), iVar5, mpHeap);
				expandedSizes = piVar4;
				piVar4 = expandedSizes;
				if (piVar4 == (int *)0x0) {
					JKRHeap::sSystemHeap->free(mpDataHeader);
					mMountMode = None;
					goto LAB_802bafa4;
				}
				// FUN_800033a8((int)piVar4, 0, (mpDataHeader)->mFileEntryCount  * sizeof(void*));
				memset(piVar4, 0, (mpDataHeader)->mFileEntryCount * sizeof(void *));
			}
			// this looks weird but I couldn't get the game to reach this part
			// mpHeader = (JKRArchive__Header *)(__ptr->mDataOffs + __ptr->mDataSize);
			mpHeader = nullptr;
		}
	}
LAB_802bafa4:
	if (!__ptr) {
		JKRHeap::sSystemHeap->free(__ptr);
	}
	if (mMountMode == None) {
		m_Do_printf::OSReport(":::Cannot alloc memory [%s][%d]\n", "JKRDvdArchive.cpp", 0x17e);
		pJVar2 = this->dvdfile;
		if ((pJVar2 != (JKRDvdFile *)0x0) && (pJVar2 != (JKRDvdFile *)0x0)) {
			pJVar2->~JKRDvdFile();
		}
		iVar5 = 0;
	} else {
		iVar5 = 1;
	}
	return iVar5;
}

JKRDvdArchive::JKRDvdArchive(long param_1, EMountDirection param_2) : JKRArchive(param_1, Dvd) {
	uint uVar1;
	int __oflag;

	mMountDirection = param_2;
	uVar1 = open(param_1);
	if ((uVar1 & 0xff) != 0) {
		type = 0x52415243;
		abort();
		loaderfilename = mpStrData + mpNodes->stroffset;
		JKRFileLoader::sVolumeList.prepend(&mVolumeLink);
		mbIsMounted = 1;
	}
}
