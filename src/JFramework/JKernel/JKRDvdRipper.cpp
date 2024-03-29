#include "JKRDvdRipper.h"

#include <dolphin/vi.h>

#include "../JSupport/JSUIosBase.h"
#include "JKRExpHeap.h"
#include "JKRHeap.h"
#include "JKernel.h"

JSUPtrList JKRDvdRipper::sDvdAsyncList;
int JKRDvdRipper::sSzpBufferSize;
byte JKRDvdRipper::errorRetry;

byte JKRDvdRipper::isErrorRetry() {
	return errorRetry;
}

void *JKRDvdRipper::loadToMainRAM(JKRDvdFile *param_1, uchar *param_2, JKRExpandSwitch shouldexpand, ulong param_4,
								  JKRHeap *heap, EAllocDirection direction, ulong param_7, int *outCompType)

{
	uint size;
	bool bVar1;
	int iVar2;
	ulong uVar3;
	uint unaff_r24;
	JKRDecomp__CompressionType JVar4;
	uchar *self;
	uchar auStack160[64];
	char aJStack96[0x20];

	bVar1 = false;
	JVar4 = NotCompressed;
	self = nullptr;
	iVar2 = param_1->getFileSize();
	size = iVar2 + 0x1fU & 0xffffffe0;
	if (shouldexpand == 1) {
		while (iVar2 = dvd::DVDReadPrio(&param_1->fileinfo, aJStack96, 0x20, 0, 2), iVar2 < 0) {
			if ((iVar2 == -3) || (JKRDvdRipper::errorRetry == '\0')) {
				return nullptr;
			}
			vi::VIWaitForRetrace();
		}
		os::DCInvalidateRange(aJStack96, 0x20);
		JVar4 = JKRDecomp::checkCompressed((uchar *)aJStack96);
		unaff_r24 = (uint)(byte)aJStack96[7] |
					(uint)(byte)aJStack96[6] << 8 |
					(uint)(byte)aJStack96[4] << 0x18 | (uint)(byte)aJStack96[5] << 0x10;
	}
	if (outCompType != nullptr) {
		*outCompType = JVar4;
	}
	if ((shouldexpand == 1) && (JVar4 != NotCompressed)) {
		if ((param_4 != 0) && (param_4 < unaff_r24)) {
			unaff_r24 = param_4;
		}
		if (param_2 == nullptr) {
			iVar2 = -0x20;
			if (direction == 1) {
				iVar2 = 0x20;
			}
			param_2 = (uchar *)JKRHeap::alloc(unaff_r24, iVar2, heap);
			bVar1 = true;
		}
		if (param_2 == nullptr) {
			return nullptr;
		}
		if (((JVar4 == Yay0Compressed) &&
			 (self = (uchar *)JKRHeap::alloc(size, 0x20, heap), self == nullptr)) &&
			(bVar1)) {
			JKRHeap::free(param_2, nullptr);
			return nullptr;
		}
	} else {
		if (param_2 == nullptr) {
			iVar2 = -0x20;
			if (direction == 1) {
				iVar2 = 0x20;
			}
			param_2 = (uchar *)JKRHeap::alloc(size - param_7, iVar2, heap);
			bVar1 = true;
		}
		if (param_2 == nullptr) {
			return nullptr;
		}
	}
	if (JVar4 == NotCompressed) {
		JVar4 = NotCompressed;
		if (param_7 != 0) {
			while (iVar2 = dvd::DVDReadPrio(&param_1->fileinfo, auStack160, 0x20, param_7, 2), iVar2 < 0) {
				if ((iVar2 == -3) || (JKRDvdRipper::errorRetry == '\0')) {
					if (bVar1) {
						JKRHeap::free(param_2, nullptr);
					}
					return nullptr;
				}
				vi::VIWaitForRetrace();
			}
			os::DCInvalidateRange(auStack160, 0x20);
			JVar4 = JKRDecomp::checkCompressed(auStack160);
		}
		if (((JVar4 == NotCompressed) || (shouldexpand == 2)) || (shouldexpand == 0)) {
			uVar3 = size - param_7;
			if ((param_4 != 0) && (param_4 < uVar3)) {
				uVar3 = param_4;
			}
			while (iVar2 = dvd::DVDReadPrio(&param_1->fileinfo, param_2, uVar3, param_7, 2), iVar2 < 0) {
				if ((iVar2 == -3) || (JKRDvdRipper::errorRetry == '\0')) {
					if (bVar1) {
						JKRHeap::free(param_2, nullptr);
					}
					return nullptr;
				}
				vi::VIWaitForRetrace();
			}
		} else if (JVar4 == Yaz0Compressed) {
			JKernel::JKRDecompressFromDVD(param_1, param_2, size, param_4, 0, param_7);
		} else {
			m_Do_printf::OSPanic("JKRDvdRipper.cpp", 0x13a, "Sorry, not prepared for SZP resource\n");
		}
	} else if (JVar4 == Yay0Compressed) {
		if (param_7 != 0) {
			m_Do_printf::OSPanic("JKRDvdRipper.cpp", 0x144, ":::Not support SZP with offset read");
		}
		while (iVar2 = dvd::DVDReadPrio(&param_1->fileinfo, self, size, 0, 2), iVar2 < 0) {
			if ((iVar2 == -3) || (JKRDvdRipper::errorRetry == '\0')) {
				if (bVar1) {
					JKRHeap::free(param_2, nullptr);
				}
				JKRHeap::free(self, nullptr);
				return nullptr;
			}
			vi::VIWaitForRetrace();
		}
		JKRDecomp::orderSync(self, param_2, unaff_r24, param_7);
		JKRHeap::free(self, nullptr);
	} else if (JVar4 == Yaz0Compressed) {
		iVar2 = JKernel::JKRDecompressFromDVD(param_1, param_2, size, unaff_r24, param_7, 0);
		if (iVar2 != 0) {
			if (bVar1) {
				JKRHeap::free(param_2, nullptr);
			}
			param_2 = nullptr;
		}
	} else {
		if (bVar1) {
			JKRHeap::free(param_2, nullptr);
		}
		param_2 = nullptr;
	}
	return param_2;
}

JKRArchive__Header *JKRDvdRipper::loadToMainRAM(long param_1,
												uchar *param_2,
												JKRExpandSwitch param_3,
												ulong param_4,
												JKRHeap *param_5,
												EAllocDirection param_6,
												ulong param_7,
												int *param_8)

{
	uint uVar1;
	JKRArchive__Header *pJVar2;
	JKRDvdFile JStack280;

	uVar1 = JStack280.open(param_1);
	if ((uVar1 & 0xff) == 0) {
		pJVar2 = nullptr;
	} else {
		pJVar2 = (JKRArchive__Header *)JKRDvdRipper::loadToMainRAM(&JStack280, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
	}
	return pJVar2;
}

JKRArchive__Header *JKRDvdRipper::loadToMainRAM(char *param_1, uchar *param_2, JKRExpandSwitch param_3, ulong param_4, JKRHeap *param_5,
												EAllocDirection param_6, ulong param_7, int *param_8) {
	uint uVar1;
	JKRArchive__Header *uVar2;
	JKRDvdFile local_118;

	uVar1 = local_118.open(param_1);
	if ((uVar1 & 0xff) == 0) {
		uVar2 = 0;
	} else {
		uVar2 = (JKRArchive__Header *)loadToMainRAM(&local_118, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
	}
	return uVar2;
}
