#include "JKRCompArchive.h"

inline static uint byteswap(uint value) {
	return __builtin_bswap32(value);
}

inline static int byteswap(int value) {
	return __builtin_bswap32(value);
}

inline static ushort byteswap(ushort value) {
	return __builtin_bswap16(value);
}

inline static short byteswap(short value) {
	return __builtin_bswap16(value);
}

bool JKRCompArchive::removeResource(void *param_1) {
	SDIFileEntry *pSVar1;
	undefined4 uVar2;

	pSVar1 = findPtrResource(param_1);
	if (pSVar1 == (SDIFileEntry *)0x0) {
		uVar2 = 0;
	} else {
		if (((uint)pSVar1->mAttrAndNameOffs >> 0x18 & 0x10) == 0) {
			JKRHeap::free(param_1, mpHeap);
		}
		pSVar1->mpData = (void *)0x0;
		uVar2 = 1;
	}
	return uVar2;
}

void JKRCompArchive::removeResourceAll() {
	uint uVar1;
	SDIFileEntry *pSVar2;

	if ((mpDataHeader != (JKRArchive__DataHeader *)0x0) &&
		(mMountMode != Mem)) {
		pSVar2 = mpFileEntries;
		for (uVar1 = 0; uVar1 < (uint)(mpDataHeader)->mFileEntryCount; uVar1 = uVar1 + 1) {
			if (pSVar2->mpData != (void *)0x0) {
				if (((uint)pSVar2->mAttrAndNameOffs >> 0x18 & 0x10) == 0) {
					JKRHeap::free(pSVar2->mpData, mpHeap);
				}
				pSVar2->mpData = (void *)0x0;
			}
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

	mpDataHeader = (JKRArchive__DataHeader *)0x0;
	mpHeader = (JKRArchive__Header *)0x0;
	this->aramheapptr = (JKRAramHeap *)0x0;
	this->archiveData = 0;
	this->mSizeOfMemPart = 0;
	this->mSizeOfAramPart = 0;
	// unused
	// this->field6_0x7c = 0;
	mpNodes = (JKRArchive__Node *)0x0;
	mpFileEntries = (SDIFileEntry *)0x0;
	mpStrData = (char *)0x0;
	dvdfile = this->dvdfile = new (JKRHeap::sSystemHeap, 0) JKRDvdFile(entry);
	if (this->dvdfile == (JKRDvdFile *)0x0) {
		mMountMode = None;
		return 0;
	}
	header = (JKRArchive__Header *)JKRHeap::sSystemHeap->alloc(0x20, -0x20);
	if (header == (JKRArchive__Header *)0x0) {
		mMountMode = None;
		goto LAB_802bbf5c;
	}
	JKRDvdRipper::loadToMainRAM(entry, (uchar *)header, 1, 0x20, (JKRHeap *)0x0, 1, 0, (int *)&mCompressionType);
	this->mSizeOfMemPart = byteswap(header->mSizeOfMemPart);
	this->mSizeOfAramPart = byteswap(header->mSizeOfAramPart);
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
		if (__ptr == (uchar *)0x0) {
			mMountMode = None;
			pJVar5 = header;
		} else {
			JKRDvdRipper::loadToMainRAM(entry, __ptr, 2, uVar8, (JKRHeap *)0x0, 1, 0, (int *)0x0);
			uVar8 = ((uint)__ptr[7] |
					 (uint)__ptr[6] << 8 | (uint)__ptr[4] << 0x18 | (uint)__ptr[5] << 0x10) +
						0x1f &
					0xffffffe0;
			pJVar5 = (JKRArchive__Header *)JKRHeap::alloc(uVar8, -unaff_r29, mpHeap);
			if (pJVar5 == (JKRArchive__Header *)0x0) {
				mMountMode = None;
				pJVar5 = header;
			} else {
				JKRDecomp::orderSync(__ptr, (uchar *)pJVar5, uVar8, 0);
				JKRHeap::sSystemHeap->free(__ptr);
				pJVar3 = (JKRArchive__DataHeader *)
					JKRHeap::alloc(byteswap(pJVar5->mFileDataOffs) + this->mSizeOfMemPart, unaff_r29,
								   mpHeap);
				mpDataHeader = pJVar3;
				pJVar3 = mpDataHeader;
				if (pJVar3 == (JKRArchive__DataHeader *)0x0) {
					mMountMode = None;
				} else {
					JKRHeap::copyMemory(pJVar3, pJVar5 + 1, byteswap(pJVar5->mFileDataOffs) + this->mSizeOfMemPart);
					mpHeader =
						(JKRArchive__Header *)((char *)&mpDataHeader->mNodeCount + byteswap(pJVar5->mFileDataOffs));
					if (this->mSizeOfAramPart != 0) {
						pJVar4 = (JKRAramHeap *)
									 JKRAram::sAramObject->mpHeap->alloc(this->mSizeOfAramPart, 0);
						this->aramheapptr = pJVar4;
						if (this->aramheapptr == (JKRAramHeap *)0x0) {
							mMountMode = None;
						} else {
							JKRAram::mainRamToAram((uchar *)((u64)&pJVar5->mSignature +
															 byteswap(pJVar5->mHeaderSize) + byteswap(pJVar5->mFileDataOffs) + this->mSizeOfMemPart),
												   (ulong)this->aramheapptr->mHeapLink.mpNext,
												   this->mSizeOfAramPart, 0, 0, (JKRHeap *)0x0, -1);
						}
					}
				}
			}
		}
		pJVar3 = mpDataHeader;
		mpNodes = (JKRArchive__Node *)((u64)&pJVar3->mNodeCount + byteswap(pJVar3->mNodeOffs));
		pJVar3 = mpDataHeader;
		mpFileEntries =
			(SDIFileEntry *)((u64)&pJVar3->mNodeCount + byteswap(pJVar3->mFileEntryOffs));
		pJVar3 = mpDataHeader;
		mpStrData = (char *)((u64)&pJVar3->mNodeCount + byteswap(pJVar3->mStrTableOffs));
		this->archiveData = byteswap(pJVar5->mHeaderSize) + byteswap(pJVar5->mFileDataOffs);
		header = pJVar5;
	} else if ((int)archiveCompType < 1) {
		if (-1 < (int)archiveCompType) {
		LAB_802bbb94:
			unaff_r29 = -0x20;
			if (mMountDirection == 1) {
				unaff_r29 = 0x20;
			}
			pJVar3 = (JKRArchive__DataHeader *)
				JKRHeap::alloc(byteswap(header->mFileDataOffs) + this->mSizeOfMemPart, unaff_r29, mpHeap);
			mpDataHeader = pJVar3;
			pJVar3 = mpDataHeader;
			if (pJVar3 == (JKRArchive__DataHeader *)0x0) {
				mMountMode = None;
			} else {
				JKRDvdRipper::loadToMainRAM(entry, (uchar *)pJVar3, 1, byteswap(header->mFileDataOffs) + this->mSizeOfMemPart,
											(JKRHeap *)0x0, 1, 0x20, (int *)0x0);
				mpHeader = (JKRArchive__Header *)((u64)&mpDataHeader->mNodeCount + byteswap(header->mFileDataOffs));
				if (this->mSizeOfAramPart != 0) {
					pJVar4 = (JKRAramHeap *)JKRAram::sAramObject->mpHeap->alloc(this->mSizeOfAramPart, 0);
					this->aramheapptr = pJVar4;
					if (this->aramheapptr == (JKRAramHeap *)0x0) {
						mMountMode = None;
						goto LAB_802bbea8;
					}
					JKRDvdAramRipper::loadToAram(entry, (ulong)this->aramheapptr->mHeapLink.mpNext, 1,
												 byteswap(header->mHeaderSize) + byteswap(header->mFileDataOffs) + this->mSizeOfMemPart, 0);
				}
				pJVar3 = mpDataHeader;
				mpNodes = (JKRArchive__Node *)((u64)&pJVar3->mNodeCount + byteswap(pJVar3->mNodeOffs));
				pJVar3 = mpDataHeader;
				mpFileEntries =
					(SDIFileEntry *)((u64)&pJVar3->mNodeCount + byteswap(pJVar3->mFileEntryOffs));
				pJVar3 = mpDataHeader;
				mpStrData = (char *)((u64)&pJVar3->mNodeCount + byteswap(pJVar3->mStrTableOffs));
				this->archiveData = byteswap(header->mHeaderSize) + byteswap(header->mFileDataOffs);
			}
		}
	} else if ((int)archiveCompType < 3)
		goto LAB_802bbb94;
LAB_802bbea8:
	expandedSizes = (int *)0x0;
	uVar8 = 0;
	pSVar9 = mpFileEntries;
	for (iVar7 = byteswap(mpDataHeader->mFileEntryCount); iVar7 != 0; iVar7 = iVar7 + -1) {
		uVar1 = (uint)byteswap(pSVar9->mAttrAndNameOffs) >> 0x18;
		if ((((uint)byteswap(pSVar9->mAttrAndNameOffs) >> 0x18 & 1) != 0) && ((uVar1 & 0x10) == 0)) {
			uVar8 = uVar8 | uVar1 & 4;
		}
		pSVar9 = pSVar9 + 1;
	}
	if (uVar8 != 0) {
		iVar7 = abs(unaff_r29);
		piVar6 = (int *)JKRHeap::alloc(byteswap(mpDataHeader->mFileEntryCount)  * sizeof(void*), iVar7,
									   mpHeap);
		expandedSizes = piVar6;
		piVar6 = expandedSizes;
		if (piVar6 == (int *)0x0) {
			JKRHeap::sSystemHeap->free(mpDataHeader);
			mMountMode = None;
		} else {
			// FUN_800033a8((int)piVar6, 0, (mpDataHeader)->mFileEntryCount  * sizeof(void*));
			memset(piVar6, 0, byteswap(mpDataHeader->mFileEntryCount)  * sizeof(void*));
		}
	}
LAB_802bbf5c:
	if (header != (JKRArchive__Header *)0x0) {
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
		loaderfilename = mpStrData + byteswap(mpNodes->stroffset);
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

	if (this != (JKRCompArchive *)0x0) {
		if (mpDataHeader != (JKRArchive__DataHeader *)0x0) {
			pSVar4 = mpFileEntries;
			uVar3 = 0;
			while (true) {
				__ptr = mpDataHeader;
				if ((uint)__ptr->mFileEntryCount <= uVar3)
					break;
				if ((((uint)pSVar4->mAttrAndNameOffs >> 0x18 & 0x10) == 0) &&
					(pSVar4->mpData != (void *)0x0)) {
					JKRHeap::free(pSVar4->mpData, mpHeap);
				}
				pSVar4 = pSVar4 + 1;
				uVar3 = uVar3 + 1;
			}
			JKRHeap::free(__ptr, mpHeap);
			mpDataHeader = (JKRArchive__DataHeader *)0x0;
		}
		pJVar1 = this->aramheapptr;
		delete pJVar1;
		__ptr_00 = expandedSizes;
		JKRHeap::free(__ptr_00, (JKRHeap *)0x0);
		pJVar2 = this->dvdfile;
		delete this->dvdfile;
		JKRFileLoader::sVolumeList.remove(&mVolumeLink);
		mbIsMounted = 0;
	}
}

uint JKRCompArchive::getExpandedResSize(void *dataPtr) {
	uint uVar1;
	SDIFileEntry *fileEntry;
	uchar auStack64[4];
	byte bStack60;
	byte bStack59;
	byte bStack58;
	byte bStack57;
	SDIFileEntry__AttributeType attrType;

	if (expandedSizes == (int *)0x0) {
		return this->getResSize(dataPtr);
	} else {
		fileEntry = findPtrResource(dataPtr);
		if (fileEntry == (SDIFileEntry *)0x0) {
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
						JKRDvdRipper::loadToMainRAM(resId, auStack64, 2, 0x20, (JKRHeap *)0x0, 1,
													this->archiveData + fileEntry->mDataOffs, (int *)0x0);
						os::DCInvalidateRange(auStack64, 0x20);
					}
				} else {
					JKRAram::aramToMainRam((int)&(this->aramheapptr->mHeapLink.mpNext)->mpData + fileEntry->mDataOffs,
										   auStack64, 0x20, 0, 0, (JKRHeap *)0x0, -1, (ulong *)0x0);
				}
				uVar1 = (uint)bStack57 |
						(uint)bStack58 << 8 | (uint)bStack60 << 0x18 | (uint)bStack59 << 0x10;
				this->setExpandSize(fileEntry, uVar1);
			} else {
				uVar1 = (uint) * (byte *)((int)dataPtr + 7) |
						(uint) * (byte *)((int)dataPtr + 6) << 8 |
						(uint) * (byte *)((int)dataPtr + 4) << 0x18 |
						(uint) * (byte *)((int)dataPtr + 5) << 0x10;
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
	if (param_3->mpData == (void *)0x0) {
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
			puVar4 = JKRMemArchive::fetchResource_subroutine((uchar *)((int)&(mpHeader)->mSignature + param_3->mDataOffs), size, (uchar *)param_1, param_2 & 0xffffffe0, uVar2);
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
		JKRHeap::copyMemory(param_1, param_3->mpData, (ulong)puVar4);
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
	if (param_1->mpData == (void *)0x0) {
		if ((uVar2 & 0x10) == 0) {
			if ((uVar2 & 0x20) == 0) {
				if ((uVar2 & 0x40) != 0) {
					uVar2 = JKRDvdArchive::fetchResource_subroutine(resId, this->archiveData + param_1->mDataOffs, uVar1,
																	mpHeap, pJVar3, mCompressionType, &local_28);
					if (param_2) {
						*param_2 = uVar2;
					}
					param_1->mpData = local_28;
					if (pJVar3 == 2) {
						setExpandSize(param_1, *param_2);
					}
				}
			} else {
				abort();
				//					uVar2 = JKRAramArchive::fetchResource_subroutine((JKRAramArchive *)((int)(this->aramheapptr->base).mHeapLink.mpNext + (param_1->mDataOffs - this->mSizeOfMemPart)),
				//																	 uVar1, (ulong)mpHeap, (JKRHeap *)pJVar3, (int)&local_24, in_r8);
				*param_2 = uVar2;
				param_1->mpData = local_24;
				if (pJVar3 == 2) {
					setExpandSize(param_1, *param_2);
				}
			}
		} else {
			param_1->mpData = (void *)((u64) & (mpHeader)->mSignature + param_1->mDataOffs);
			*param_2 = uVar1;
		}
	} else if (param_2) {
		*param_2 = uVar1;
	}
	return param_1->mpData;
}