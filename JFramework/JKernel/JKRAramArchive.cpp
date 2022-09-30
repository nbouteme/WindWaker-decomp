#include "JKRAramArchive.h"

int JKRAramArchive::open(long __file) {
	int iVar1;
	//JKRDvdFile *this_00;
	uchar *__ptr;
	JKRArchive__DataHeader *pJVar2;
	JKRArchive__Header *pJVar3;
	int *piVar4;
	int iVar5;
	uint uVar6;
	undefined4 align;
	SDIFileEntry *pSVar7;
	ulong uVar8;

	mpDataHeader = (JKRArchive__DataHeader *)0x0;
	mpNodes = (JKRArchive__Node *)0x0;
	mpFileEntries = (SDIFileEntry *)0x0;
	mpStrData = (char *)0x0;
	mpHeader = (JKRArchive__Header *)0x0;
	align = 0xfffffffc;
	if (mMountDirection == 1) {
		align = 4;
	}
	this->dvdfile = new (JKRHeap::sSystemHeap, align) JKRDvdFile(__file);
	if (!this->dvdfile) {
		mMountMode = None;
		return 0;
	}
	__ptr = (uchar *)JKRHeap::sSystemHeap->alloc(0x20, -0x20);
	if (__ptr == (uchar *)0x0) {
		mMountMode = None;
	} else {
		JKRDvdRipper::loadToMainRAM(__file, __ptr, 1, 0x20, (JKRHeap *)0x0, 1, 0, (int *)&mCompressionType);
		iVar5 = -0x20;
		if (mMountDirection == 1) {
			iVar5 = 0x20;
		}
		uVar6 = *(int *)(__ptr + 0xc) + 0x1fU & 0xffffffe0;
		pJVar2 = (JKRArchive__DataHeader *)JKRHeap::alloc(uVar6, iVar5, mpHeap);
		mpDataHeader = pJVar2;
		pJVar2 = mpDataHeader;
		if (pJVar2 == (JKRArchive__DataHeader *)0x0) {
			mMountMode = None;
		} else {
			uVar8 = 1;
			JKRDvdRipper::loadToMainRAM(__file, (uchar *)pJVar2, 1, uVar6, (JKRHeap *)0x0, 1, 0x20, (int *)0x0);
			pJVar2 = mpDataHeader;
			mpNodes = (JKRArchive__Node *)((int)&pJVar2->mNodeCount + pJVar2->mNodeOffs);
			pJVar2 = mpDataHeader;
			mpFileEntries =
				(SDIFileEntry *)((int)&pJVar2->mNodeCount + pJVar2->mFileEntryOffs);
			pJVar2 = mpDataHeader;
			mpStrData = (char *)((int)&pJVar2->mNodeCount + pJVar2->mStrTableOffs);
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
				piVar4 = (int *)JKRHeap::alloc((mpDataHeader)->mFileEntryCount << 2, iVar5,
											   mpHeap);
				expandedSizes = piVar4;
				piVar4 = expandedSizes;
				if (piVar4 == (int *)0x0) {
					JKRHeap::free(mpDataHeader, (JKRHeap *)0x0);
					mMountMode = None;
					goto LAB_802ba46c;
				}
				//FUN_800033a8((int)piVar4, 0, (mpDataHeader)->mFileEntryCount << 2);
				memset(piVar4, 0, (mpDataHeader)->mFileEntryCount << 2);
			}
			iVar5 = -mMountDirection;
			iVar1 = iVar5 + 1;
			pJVar3 = (JKRArchive__Header *)
						 JKRAram::sAramObject->mpHeap->alloc(*(int *)(__ptr + 0x10) + 0x1fU & 0xffffffe0,
															 iVar1 - ((uint)(iVar1 == 0) + iVar5));
			mpHeader = pJVar3;
			pJVar3 = mpHeader;
			if (pJVar3 == (JKRArchive__Header *)0x0) {
				pJVar2 = mpDataHeader;
				if (pJVar2 != (JKRArchive__DataHeader *)0x0) {
					JKRHeap::free(pJVar2, (JKRHeap *)0x0);
				}
				piVar4 = expandedSizes;
				if (piVar4 != (int *)0x0) {
					JKRHeap::free(piVar4, (JKRHeap *)0x0);
				}
				mMountMode = None;
			} else {
				JKRDvdAramRipper::loadToAram(__file, pJVar3->mSizeOfMemPart, 1,
											 *(int *)(__ptr + 8) + *(int *)(__ptr + 0xc), 0);
			}
		}
	}
LAB_802ba46c:
	if (__ptr != (uchar *)0x0) {
		JKRHeap::sSystemHeap->free(__ptr);
	}
	if (mMountMode == None) {
		m_Do_printf::OSReport(":::[%s: %d] Cannot alloc memory\n", "JKRAramArchive.cpp", 400);
		delete this->dvdfile;
		iVar5 = 0;
	} else {
		iVar5 = 1;
	}
	return iVar5;
}

JKRAramArchive::JKRAramArchive(long param_1, EMountDirection param_2) : JKRArchive(param_1, ARAM) {
	uint uVar1;

	mMountDirection = param_2;
	uVar1 = open(param_1);
	if ((uVar1 & 0xff) != 0) {
		type = 0x52415243;
		loaderfilename = mpStrData + mpNodes->stroffset;
		JKRFileLoader::sVolumeList.prepend(&mVolumeLink);
		mbIsMounted = 1;
	}
}
