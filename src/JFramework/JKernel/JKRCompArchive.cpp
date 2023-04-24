#include "JKRCompArchive.h"

bool JKRCompArchive::removeResource(void *param_1) {
	SDIFileEntry *pSVar1;
	undefined4 uVar2;

	pSVar1 = findPtrResource(param_1);
	if (pSVar1 == nullptr) {
		uVar2 = 0;
	} else {
		if (((uint)pSVar1->mAttrAndNameOffs >> 0x18 & 0x10) == 0) {
			JKRHeap::free(param_1, mpHeap);
		}
#ifndef PTR64
		pSVar1->mpData = nullptr;
#else
		entries_data[pSVar1 - mpFileEntries] = 0;
#endif

		uVar2 = 1;
	}
	return uVar2;
}

// They forgot to increment the resource pointer in the loop
void JKRCompArchive::removeResourceAll() {
	uint uVar1;
	SDIFileEntry *pSVar2;

	if ((mpDataHeader != nullptr) &&
		(mMountMode != Mem)) {
		pSVar2 = mpFileEntries;
		for (uVar1 = 0; uVar1 < (uint)(mpDataHeader)->mFileEntryCount; uVar1 = uVar1 + 1) {
#ifndef PTR64
			if (pSVar2->mpData != nullptr) {
				if (((uint)pSVar2->mAttrAndNameOffs >> 0x18 & 0x10) == 0) {
					JKRHeap::free(pSVar2->mpData, mpHeap);
				}
				pSVar2->mpData = nullptr;
			}
#else

			if (entries_data[0]) {	// replace [0] by [uVar1] to fix the bug
				if (((uint)pSVar2->mAttrAndNameOffs >> 0x18 & 0x10) == 0) {
					JKRHeap::free(entries_data[0], mpHeap);
				}
				entries_data[0] = nullptr;
			}
#endif
		}
	}
}

int JKRCompArchive::open(int entry) {
	uint uVar1;
	JKRDecomp__CompressionType archiveCompType;
	JKRDvdFile *dvdfile;
	ulong uVar2;
	JKRArchive__DataHeader *pJVar3;
	JKRAramHeap *pJVar4;
	uchar *__ptr;
	JKRArchive__Header *pJVar5;
	int *piVar6;
	int iVar7;
	uint uVar8;
	SDIFileEntry *pSVar9;
	int unaff_r29;
	JKRArchive__Header *header;

	mpDataHeader = nullptr;
	mpHeader = nullptr;
	this->aramheapptr = nullptr;
	this->archiveData = 0;
	this->mSizeOfMemPart = 0;
	this->mSizeOfAramPart = 0;
	// unused
	// this->field6_0x7c = 0;
	mpNodes = nullptr;
	mpFileEntries = nullptr;
	mpStrData = nullptr;
	dvdfile = this->dvdfile = new (JKRHeap::sSystemHeap, 0) JKRDvdFile(entry);
	if (this->dvdfile == nullptr) {
		mMountMode = None;
		return 0;
	}
	header = (JKRArchive__Header *)JKRHeap::sSystemHeap->alloc(0x20, -0x20);
	if (header == nullptr) {
		mMountMode = None;
		goto LAB_802bbf5c;
	}
	JKRDvdRipper::loadToMainRAM(entry, (uchar *)header, 1, 0x20, nullptr, 1, 0, (int *)&mCompressionType);
	this->mSizeOfMemPart = (header->mSizeOfMemPart);
	this->mSizeOfAramPart = (header->mSizeOfAramPart);
	if ((this->mSizeOfMemPart & 0x1fU) != 0) {
		JUTAssertion::getSDevice()->showAssert("JKRCompArchive.cpp", 0x15a, "( mSizeOfMemPart & 0x1f ) == 0");
		m_Do_printf::OSPanic("JKRCompArchive.cpp", 0x15a, "Halt");
	}
	if ((this->mSizeOfAramPart & 0x1fU) != 0) {
		JUTAssertion::getSDevice()->showAssert("JKRCompArchive.cpp", 0x15b, "( mSizeOfAramPart & 0x1f ) == 0");
		m_Do_printf::OSPanic("JKRCompArchive.cpp", 0x15b, "Halt");
	}
	archiveCompType = mCompressionType;
	if (archiveCompType == Yay0Compressed) {
		iVar7 = this->dvdfile->getFileSize();
		uVar8 = iVar7 + 0x1fU & 0xffffffe0;
		unaff_r29 = -0x20;
		if (mMountDirection == 1) {
			unaff_r29 = 0x20;
		}
		__ptr = (uchar *)JKRHeap::sSystemHeap->alloc(uVar8, -unaff_r29);
		if (__ptr == nullptr) {
			mMountMode = None;
			pJVar5 = header;
		} else {
			JKRDvdRipper::loadToMainRAM(entry, __ptr, 2, uVar8, nullptr, 1, 0, nullptr);
			uVar8 = ((uint)__ptr[7] |
					 (uint)__ptr[6] << 8 | (uint)__ptr[4] << 0x18 | (uint)__ptr[5] << 0x10) +
						0x1f &
					0xffffffe0;
			pJVar5 = (JKRArchive__Header *)JKRHeap::alloc(uVar8, -unaff_r29, mpHeap);
			if (pJVar5 == nullptr) {
				mMountMode = None;
				pJVar5 = header;
			} else {
				JKRDecomp::orderSync(__ptr, (uchar *)pJVar5, uVar8, 0);
				JKRHeap::sSystemHeap->free(__ptr);
				pJVar3 = (JKRArchive__DataHeader *)
					JKRHeap::alloc((pJVar5->mFileDataOffs) + this->mSizeOfMemPart, unaff_r29,
								   mpHeap);
				mpDataHeader = pJVar3;
				pJVar3 = mpDataHeader;
				if (pJVar3 == nullptr) {
					mMountMode = None;
				} else {
					JKRHeap::copyMemory(pJVar3, pJVar5 + 1, (pJVar5->mFileDataOffs) + this->mSizeOfMemPart);
					mpHeader =
						(JKRArchive__Header *)((char *)&mpDataHeader->mNodeCount + (pJVar5->mFileDataOffs));
					if (this->mSizeOfAramPart != 0) {
						pJVar4 = (JKRAramHeap *)
									 JKRAram::sAramObject->mpHeap->alloc(this->mSizeOfAramPart, 0);
						this->aramheapptr = pJVar4;
						if (this->aramheapptr == nullptr) {
							mMountMode = None;
						} else {
							JKRAram::mainRamToAram((uchar *)((u64)&pJVar5->mSignature +
															 (pJVar5->mHeaderSize) + (pJVar5->mFileDataOffs) + this->mSizeOfMemPart),
												   (ulong)this->aramheapptr->mHeapLink.mpNext,
												   this->mSizeOfAramPart, 0, 0, nullptr, -1);
						}
					}
				}
			}
		}
		pJVar3 = mpDataHeader;
		mpNodes = (JKRArchive__Node *)((u64)&pJVar3->mNodeCount + (pJVar3->mNodeOffs));
		pJVar3 = mpDataHeader;
		mpFileEntries =
			(SDIFileEntry *)((u64)&pJVar3->mNodeCount + (pJVar3->mFileEntryOffs));
		pJVar3 = mpDataHeader;
		mpStrData = (char *)((u64)&pJVar3->mNodeCount + (pJVar3->mStrTableOffs));
		this->archiveData = (pJVar5->mHeaderSize) + (pJVar5->mFileDataOffs);
#ifdef PTR64
		entries_data = (void **)calloc(sizeof(void *), mpDataHeader->mFileEntryCount);
#endif

		header = pJVar5;
	} else if ((int)archiveCompType < 1) {
		if (-1 < (int)archiveCompType) {
		LAB_802bbb94:
			unaff_r29 = -0x20;
			if (mMountDirection == 1) {
				unaff_r29 = 0x20;
			}
			pJVar3 = (JKRArchive__DataHeader *)
				JKRHeap::alloc((header->mFileDataOffs) + this->mSizeOfMemPart, unaff_r29, mpHeap);
			mpDataHeader = pJVar3;
			pJVar3 = mpDataHeader;
			if (pJVar3 == nullptr) {
				mMountMode = None;
			} else {
				JKRDvdRipper::loadToMainRAM(entry, (uchar *)pJVar3, 1, (header->mFileDataOffs) + this->mSizeOfMemPart,
											nullptr, 1, 0x20, nullptr);
				mpHeader = (JKRArchive__Header *)((u64)&mpDataHeader->mNodeCount + (header->mFileDataOffs));
				if (this->mSizeOfAramPart != 0) {
					pJVar4 = (JKRAramHeap *)JKRAram::sAramObject->mpHeap->alloc(this->mSizeOfAramPart, 0);
					this->aramheapptr = pJVar4;
					if (this->aramheapptr == nullptr) {
						mMountMode = None;
						goto LAB_802bbea8;
					}
					JKRDvdAramRipper::loadToAram(entry, (ulong)this->aramheapptr->mHeapLink.mpNext, 1,
												 (header->mHeaderSize) + (header->mFileDataOffs) + this->mSizeOfMemPart, 0);
				}
				pJVar3 = mpDataHeader;
				mpNodes = (JKRArchive__Node *)((u64)&pJVar3->mNodeCount + (pJVar3->mNodeOffs));
				pJVar3 = mpDataHeader;
				mpFileEntries =
					(SDIFileEntry *)((u64)&pJVar3->mNodeCount + (pJVar3->mFileEntryOffs));
				pJVar3 = mpDataHeader;
				mpStrData = (char *)((u64)&pJVar3->mNodeCount + (pJVar3->mStrTableOffs));
				this->archiveData = (header->mHeaderSize) + (header->mFileDataOffs);
#ifdef PTR64
				entries_data = (void **)calloc(sizeof(void *), mpDataHeader->mFileEntryCount);
#endif
			}
		}
	} else if ((int)archiveCompType < 3)
		goto LAB_802bbb94;
LAB_802bbea8:
	expandedSizes = nullptr;
	uVar8 = 0;
	pSVar9 = mpFileEntries;
	for (iVar7 = (mpDataHeader->mFileEntryCount); iVar7 != 0; iVar7 = iVar7 + -1) {
		uVar1 = (uint)be_s32(pSVar9->mAttrAndNameOffs) >> 0x18;
		if ((((uint)be_s32(pSVar9->mAttrAndNameOffs) >> 0x18 & 1) != 0) && ((uVar1 & 0x10) == 0)) {
			uVar8 = uVar8 | uVar1 & 4;
		}
		pSVar9 = pSVar9 + 1;  // Incorrect on entries loaded from disk
	}
	if (uVar8 != 0) {
		iVar7 = abs(unaff_r29);
		piVar6 = (int *)JKRHeap::alloc((mpDataHeader->mFileEntryCount) * sizeof(void *), iVar7,
									   mpHeap);
		expandedSizes = piVar6;
		piVar6 = expandedSizes;
		if (piVar6 == nullptr) {
			JKRHeap::sSystemHeap->free(mpDataHeader);
			mMountMode = None;
		} else {
			// FUN_800033a8((int)piVar6, 0, (mpDataHeader)->mFileEntryCount  * sizeof(void*));
			memset(piVar6, 0, (mpDataHeader->mFileEntryCount) * sizeof(void *));
		}
	}
LAB_802bbf5c:
	if (header != nullptr) {
		JKRHeap::sSystemHeap->free(header);
	}
	if (mMountMode == None) {
		m_Do_printf::OSReport(":::[%s: %d] Cannot alloc memory in mounting CompArchive\n", "JKRCompArchive.cpp",
							  0x224);
		dvdfile = this->dvdfile;
		delete dvdfile;
		iVar7 = 0;
	} else {
		iVar7 = 1;
	}
	return iVar7;
}

JKRCompArchive::JKRCompArchive(long param_1, EMountDirection param_2) : JKRArchive(param_1, Comp) {
	uint uVar1;
	int __oflag;

	__oflag = 4;
	mMountDirection = param_2;
	uVar1 = open(param_1);
	if ((uVar1 & 0xff) != 0) {
		type = 0x52415243;
		loaderfilename = mpStrData + (mpNodes->stroffset);
		JKRFileLoader::sVolumeList.prepend(&mVolumeLink);
		mbIsMounted = 1;
	}
	return;
}

JKRCompArchive::~JKRCompArchive() {
	JKRArchive__DataHeader *__ptr;
	JKRAramHeap *pJVar1;
	int *__ptr_00;
	JKRDvdFile *pJVar2;
	short in_r4;
	uint uVar3;
	SDIFileEntry *pSVar4;

	// if (!this)
	//	return;
	//  this may be a part of an inlined JKRArchive DTOR?
	if (mpDataHeader != nullptr) {
		pSVar4 = mpFileEntries;
		uVar3 = 0;
		while (true) {
			__ptr = mpDataHeader;
			if ((uint)__ptr->mFileEntryCount <= uVar3)
				break;
#ifndef PTR64
			if ((((uint)pSVar4->mAttrAndNameOffs >> 0x18 & 0x10) == 0) &&
				(pSVar4->mpData != nullptr)) {
				JKRHeap::free(pSVar4->mpData, mpHeap);
			}
#else
			if ((((uint)pSVar4->mAttrAndNameOffs >> 0x18 & 0x10) == 0) &&
				(entries_data[uVar3] != nullptr)) {
				JKRHeap::free(entries_data[uVar3], mpHeap);
			}
#endif

			pSVar4 = pSVar4 + 1;
			uVar3 = uVar3 + 1;
		}
		JKRHeap::free(__ptr, mpHeap);
		mpDataHeader = nullptr;
	}

	delete this->aramheapptr;
	JKRHeap::free(expandedSizes, nullptr);
	delete this->dvdfile;
	JKRFileLoader::sVolumeList.remove(&mVolumeLink);
	mbIsMounted = 0;
}

struct Yaz0Header {
	int magic;
	int size;
	int padding[6];
};

uint JKRCompArchive::getExpandedResSize(void *dataPtr) {
	uint uVar1;
	SDIFileEntry *fileEntry;
	Yaz0Header header;
	SDIFileEntry__AttributeType attrType;

	if (expandedSizes == nullptr) {
		return this->getResSize(dataPtr);
	} else {
		fileEntry = findPtrResource(dataPtr);
		if (fileEntry == nullptr) {
			uVar1 = 0xffffffff;
		} else {
			attrType = (SDIFileEntry__AttributeType)(fileEntry->mAttrAndNameOffs >> 0x18);
			if ((attrType & SDIFileEntry__AttributeType::Compressed) == 0) {
				uVar1 = this->getResSize(dataPtr);
			} else if ((attrType & MEM) == 0) {
				if ((attrType & ARAM) == 0) {
					if ((attrType & DVD) == 0) {
						m_Do_printf::OSPanic("JKRCompArchive.cpp", 0x3b0, "illegal resource.");
					} else {
						JKRDvdRipper::loadToMainRAM(resId, (uchar *)&header, 2, 0x20, nullptr, 1,
													this->archiveData + fileEntry->mDataOffs, nullptr);
						os::DCInvalidateRange((uchar *)&header, 0x20);
					}
				} else {
					JKRAram::aramToMainRam((intptr_t) & (this->aramheapptr->mHeapLink.mpNext)->mpData + fileEntry->mDataOffs,
										   (uchar *)&header, 0x20, 0, 0, nullptr, -1, nullptr);
				}
				// vanilla seems to have decleared header as a byte array and manually reconstructs size from the header?
				// uVar1 = (uint)bStack57 |
				// 		(uint)bStack58 << 8 |
				// 		(uint)bStack60 << 0x18 |
				// 		(uint)bStack59 << 0x10;
				this->setExpandSize(fileEntry, header.size);
			} else {
				uVar1 = (uint) * (byte *)((intptr_t)dataPtr + 7) |
						(uint) * (byte *)((intptr_t)dataPtr + 6) << 8 |
						(uint) * (byte *)((intptr_t)dataPtr + 4) << 0x18 |
						(uint) * (byte *)((intptr_t)dataPtr + 5) << 0x10;
			}
		}
	}
	return uVar1;
}

void *JKRCompArchive::fetchResource(void *param_1, uint param_2, SDIFileEntry *param_3, uint *param_4) {
	uint uVar1;
	uint size;
	ulong uVar2;
	ulong puVar3;
	ulong puVar4;

	puVar4 = 0x0;
	if (mbIsMounted == 0) {
		JUTAssertion::getSDevice()->showAssert("JKRCompArchive.cpp", 0x2b8, "isMounted()");
		m_Do_printf::OSPanic("JKRCompArchive.cpp", 0x2b8, "Halt");
	}
	puVar3 = param_3->mDataSize;
	size = (uint)(puVar3 + 0x1f) & 0xffffffe0;
	uVar1 = (uint)param_3->mAttrAndNameOffs >> 0x18;
	if (((uint)param_3->mAttrAndNameOffs >> 0x18 & 4) == 0) {
		uVar2 = 0;
	} else if ((uVar1 & 0x80) == 0) {
		uVar2 = 1;
	} else {
		uVar2 = 2;
	}
	void *d;
#ifndef PTR64
	d = param_3->mpData;
#else
	int idx = param_3 - mpFileEntries;
	ASSERT(idx >= 0 && idx < mpDataHeader->mFileEntryCount);
	d = entries_data[idx];
#endif

	if (d == nullptr) {
		if ((uVar1 & 0x10) == 0) {
			if ((uVar1 & 0x20) == 0) {
				if ((uVar1 & 0x40) == 0) {
					m_Do_printf::OSPanic("JKRCompArchive.cpp", 0x2f4, ":::CompArchive: bad mode.");
				} else {
					puVar4 = JKRDvdArchive::fetchResource_subroutine(resId, this->archiveData + param_3->mDataOffs,
																	 size, (uchar *)param_1, param_2 & 0xffffffffffffffe0, uVar2,
																	 mCompressionType);
				}
			} else {
				abort();
				// puVar4 = JKRAramArchive::fetchResource_subroutine((JKRAramArchive *)((u64)this->aramheapptr->mHeapLink.mpNext + (param_3->mDataOffs - this->mSizeOfMemPart)), size, (ulong)param_1, (uchar *)(param_2 & 0xffffffffffffffe0), uVar2, uVar2);
			}
		} else {
			puVar4 = JKRMemArchive::fetchResource_subroutine(
				(uchar *)((intptr_t) & (mpHeader)->mSignature + param_3->mDataOffs),
				size,
				(uchar *)param_1,
				param_2 & 0xffffffe0,
				uVar2);
		}
	} else {
		if ((uVar2 == 2) &&
			(puVar4 = getExpandSize(param_3),
			 puVar4 != 0x0)) {
			puVar3 = puVar4;
		}
		puVar4 = puVar3;
		if (param_2 < puVar3) {
			puVar4 = param_2;
		}
		JKRHeap::copyMemory(param_1, d, (ulong)puVar4);
	}
	if (param_4) {
		*param_4 = puVar4;
	}
	return param_1;
}

void *JKRCompArchive::fetchResource(SDIFileEntry *param_1, uint *param_2) {
	ulong uVar1;
	uint uVar2;
	uchar **in_r8;
	int pJVar3;
	uchar *local_28;
	void *local_24;
	uint local_20[4];

	if (mbIsMounted == 0) {
		JUTAssertion::getSDevice()->showAssert("JKRCompArchive.cpp", 0x242, "isMounted()");
		m_Do_printf::OSPanic("JKRCompArchive.cpp", 0x242, "Halt");
	}
	uVar1 = param_1->mDataSize;
	uVar2 = (uint)param_1->mAttrAndNameOffs >> 0x18;
	if (((uint)param_1->mAttrAndNameOffs >> 0x18 & 4) == 0) {
		pJVar3 = 0;
	} else if ((uVar2 & 0x80) == 0) {
		pJVar3 = 1;
	} else {
		pJVar3 = 2;
	}
	if (!param_2) {
		param_2 = local_20;
	}

#ifndef PTR64
	auto &d = param_1->mpData;
#else
	int idx = param_1 - mpFileEntries;
	ASSERT(idx >= 0 && idx < mpDataHeader->mFileEntryCount);
	auto &d = entries_data[idx];
#endif

	if (d == nullptr) {
		if ((uVar2 & 0x10) == 0) {
			if ((uVar2 & 0x20) == 0) {
				if ((uVar2 & 0x40) != 0) {
					uVar2 = JKRDvdArchive::fetchResource_subroutine(resId, this->archiveData + param_1->mDataOffs, uVar1,
																	mpHeap, pJVar3, mCompressionType, &local_28);
					if (param_2) {
						*param_2 = uVar2;
					}
					d = local_28;
					if (pJVar3 == 2) {
						setExpandSize(param_1, *param_2);
					}
				}
			} else {
				abort();
				//					uVar2 = JKRAramArchive::fetchResource_subroutine((JKRAramArchive *)((int)(this->aramheapptr->base).mHeapLink.mpNext + (param_1->mDataOffs - this->mSizeOfMemPart)),
				//																	 uVar1, (ulong)mpHeap, (JKRHeap *)pJVar3, (int)&local_24, in_r8);
				*param_2 = uVar2;
				d = local_24;
				if (pJVar3 == 2) {
					setExpandSize(param_1, *param_2);
				}
			}
		} else {
			d = (void *)((u64) & (mpHeader)->mSignature + param_1->mDataOffs);
			*param_2 = uVar1;
		}
	} else if (param_2) {
		*param_2 = uVar1;
	}
	return d;
}