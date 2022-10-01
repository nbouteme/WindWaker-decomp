#include "JKRDvdArchive.h"
#include "JKernel.h"
#include "JKRHeap.h"
#include "JKRExpHeap.h"
#include "../JSupport/JSUIosBase.h"
#include <machine/dolphin/printf.h>

JKRDvdArchive::~JKRDvdArchive() {
	JKRArchive__DataHeader *__ptr;
	int *__ptr_00;
	JKRDvdFile *pJVar1;
	short in_r4;
	uint uVar2;
	SDIFileEntry *pSVar3;

	if (!this)
		return;
	if (mbIsMounted != 1)
		return;
	if (mpDataHeader != (JKRArchive__DataHeader *)0x0) {
		pSVar3 = mpFileEntries;
		for (uVar2 = 0; __ptr = mpDataHeader, uVar2 < (uint)__ptr->mFileEntryCount;
			 uVar2 = uVar2 + 1) {
			if (pSVar3->mpData != (void *)0x0) {
				JKRHeap::free(pSVar3->mpData, mpHeap);
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
	uchar auStack64[4];
	byte bStack60;
	byte bStack59;
	byte bStack58;
	byte bStack57;

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
				JKRDvdRipper::loadToMainRAM(this->resId, auStack64, 2, 0x20, (JKRHeap *)0x0, 1,
											(int)&this->mpHeader->mSignature + pSVar2->mDataOffs, (int *)0x0);
				os::DCInvalidateRange(auStack64, 0x20);
				uVar1 = (uint)bStack57 |
						(uint)bStack58 << 8 | (uint)bStack60 << 0x18 | (uint)bStack59 << 0x10;
				setExpandSize(pSVar2, uVar1);
			}
		}
	}
	return uVar1;
}

ulong JKRDvdArchive::fetchResource_subroutine(long param_1, ulong param_2, ulong size, uchar *param_4, ulong param_5, int param_6,
											  int isSZP)

{
	uint uVar1;
	uint uVar2;
	uint uVar3;
	uchar auStack64[4];
	byte bStack60;
	byte bStack59;
	byte bStack58;
	byte bStack57;

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
				JKRDvdRipper::loadToMainRAM(param_1, auStack64, 2, 0x20, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
				os::DCInvalidateRange(auStack64, 0x20);
				uVar3 = (uint)bStack57 |
						(uint)bStack58 << 8 | (uint)bStack60 << 0x18 | (uint)bStack59 << 0x10;
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
		//uVar1 = JUTAssertion::getSDevice();
		//JUTAssertion::showAssert(uVar1, "JKRDvdArchive.cpp", 0x1e9, "isMounted()");
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
	if (fileEntry->mpData == (void *)0x0) {
		size = fetchResource_subroutine(this->resId, (int)&this->mpHeader->mSignature + fileEntry->mDataOffs,
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
		JKRHeap::copyMemory(param_1, fileEntry->mpData, size);
	}
	if (param_4) {
		*param_4 = size;
	}
	return param_1;
}

uint JKRDvdArchive::fetchResource_subroutine(long param_1, ulong param_2, ulong param_3, JKRHeap *param_4, int param_5, int param_6,
											 uchar **param_7)

{
	uchar *puVar1;
	ulong uVar2;
	uint uVar3;
	uchar auStack96[4];
	byte bStack92;
	byte bStack91;
	byte bStack90;
	byte bStack89;

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
					//uVar2 = JUTAssertion::getSDevice();
					//JUTAssertion::showAssert(uVar2, "JKRDvdArchive.cpp", 0x277, "buffer != 0");
					m_Do_printf::OSPanic("JKRDvdArchive.cpp", 0x277, "Halt");
				}
				JKRDvdRipper::loadToMainRAM(param_1, puVar1, 0, uVar3, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
				*param_7 = puVar1;
				return uVar3;
			}
			if ((-1 < param_5) && (param_5 < 3)) {
				JKRDvdRipper::loadToMainRAM(param_1, auStack96, 2, 0x20, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
				os::DCInvalidateRange(auStack96, 0x20);
				uVar3 = (uint)bStack89 |
						(uint)bStack90 << 8 | (uint)bStack92 << 0x18 | (uint)bStack91 << 0x10;
				puVar1 = (uchar *)JKRHeap::alloc(uVar3, 0x20, param_4);
				if (puVar1 == (uchar *)0x0) {
					//uVar2 = JUTAssertion::getSDevice();
					//JUTAssertion::showAssert(uVar2, "JKRDvdArchive.cpp", 0x294, "buffer");
					m_Do_printf::OSPanic("JKRDvdArchive.cpp", 0x294, "Halt");
				}
				JKRDvdRipper::loadToMainRAM(param_1, puVar1, 1, uVar3, (JKRHeap *)0x0, 1, param_2, (int *)0x0);
				*param_7 = puVar1;
				return uVar3;
			}
		LAB_802bb62c:
			puVar1 = (uchar *)JKRHeap::alloc(uVar3, 0x20, param_4);
			if (puVar1 == (uchar *)0x0) {
				//uVar2 = JUTAssertion::getSDevice();
				//JUTAssertion::showAssert(uVar2, "JKRDvdArchive.cpp", 0x2a0, "buffer");
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
		//uVar1 = JUTAssertion::getSDevice();
		//JUTAssertion::showAssert(uVar1, "JKRDvdArchive.cpp", 0x19d, "isMounted()");
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
	if (fileEntry->mpData == (void *)0x0) {
		uVar2 = JKRDvdArchive::fetchResource_subroutine(this->resId, (int)&this->mpHeader->mSignature + fileEntry->mDataOffs,
														fileEntry->mDataSize, this->mpHeap, iVar3, this->mCompressionType, &local_18);
		*param_2 = uVar2;
		if (uVar2 == 0) {
			return (void *)0x0;
		}
		fileEntry->mpData = local_18;
		if (iVar3 == 2) {
			setExpandSize(fileEntry, *param_2);
		}
	} else if (iVar3 == 2) {
		uVar2 = getExpandSize(fileEntry);
		*param_2 = uVar2;
	} else {
		*param_2 = fileEntry->mDataSize;
	}
	return fileEntry->mpData;
}

int JKRDvdArchive::open(uint __file) {
	int iVar1;
	JKRDvdFile *pJVar2;
	uchar *__ptr;
	JKRArchive__DataHeader *pJVar3;
	int *piVar4;
	int iVar5;
	uint uVar6;
	SDIFileEntry *pSVar7;

	mpDataHeader = (JKRArchive__DataHeader *)0x0;
	mpHeader = (JKRArchive__Header *)0x0;
	mpNodes = (JKRArchive__Node *)0x0;
	mpFileEntries = (SDIFileEntry *)0x0;
	mpStrData = (char *)0x0;
	pJVar2 = new (JKRHeap::sSystemHeap, 0) JKRDvdFile(__file);
	this->dvdfile = pJVar2;
	if (this->dvdfile == (JKRDvdFile *)0x0) {
		mMountMode = None;
		return 0;
	}
	// is __ptr a SDIFileEntry? or JKRArchive__DataHeader?
	__ptr = (uchar *)JKRHeap::sSystemHeap->alloc(0x20, 0x20);
	if (__ptr == (uchar *)0x0) {
		mMountMode = None;
	} else {
		JKRDvdRipper::loadToMainRAM(__file, __ptr, 1, 0x20, (JKRHeap *)0x0, 1, 0, (int *)&mCompressionType);
		iVar5 = -0x20;
		if (mMountDirection == 1) {
			iVar5 = 0x20;
		}
		pJVar3 = (JKRArchive__DataHeader *)
			JKRHeap::alloc(*(uint *)(__ptr + 0xc), iVar5, mpHeap);
		mpDataHeader = pJVar3;
		pJVar3 = mpDataHeader;
		if (pJVar3 == (JKRArchive__DataHeader *)0x0) {
			mMountMode = None;
		} else {
			JKRDvdRipper::loadToMainRAM(__file, (uchar *)pJVar3, 1, *(ulong *)(__ptr + 0xc), (JKRHeap *)0x0, 1, 0x20, (int *)0x0);
			pJVar3 = mpDataHeader;
			mpNodes = (JKRArchive__Node *)((int)&pJVar3->mNodeCount + pJVar3->mNodeOffs);
			pJVar3 = mpDataHeader;
			mpFileEntries = (SDIFileEntry *)((int)&pJVar3->mNodeCount + pJVar3->mFileEntryOffs);
			pJVar3 = mpDataHeader;
			mpStrData = (char *)((int)&pJVar3->mNodeCount + pJVar3->mStrTableOffs);
			expandedSizes = (int *)0x0;
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
				piVar4 = (int *)JKRHeap::alloc((mpDataHeader)->mFileEntryCount << 2, iVar5, mpHeap);
				expandedSizes = piVar4;
				piVar4 = expandedSizes;
				if (piVar4 == (int *)0x0) {
					JKRHeap::sSystemHeap->free(mpDataHeader);
					mMountMode = None;
					goto LAB_802bafa4;
				}
				//FUN_800033a8((int)piVar4, 0, (mpDataHeader)->mFileEntryCount << 2);
				memset(piVar4, 0, (mpDataHeader)->mFileEntryCount << 2);
			}
			mpHeader = (JKRArchive__Header *)(*(int *)(__ptr + 8) + *(int *)(__ptr + 0xc));
		}
	}
LAB_802bafa4:
	if (__ptr != (uchar *)0x0) {
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

JKRDvdArchive::JKRDvdArchive(long param_1, EMountDirection param_2) : JKRArchive(param_1, DVD) {
	uint uVar1;
	int __oflag;

	mMountDirection = param_2;
	uVar1 = open(param_1);
	if ((uVar1 & 0xff) != 0) {
		type = 0x52415243;
		loaderfilename = mpStrData + mpNodes->stroffset;
		JKRFileLoader::sVolumeList.prepend(&mVolumeLink);
		mbIsMounted = 1;
	}
}
