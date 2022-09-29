#pragma once

#include <doltypes.h>

#include "JKRHeap.h"
#include "JSUIosBase.h"
#include "JKRDvdRipper.h"

#include "JKRDvdAramRipper.h"

#include "JKRAramPiece.h"

#include <cstring>

namespace JKernel {
	char rootPath$2460[];
	void JKRDefaultMemoryErrorRoutine(JKRHeap *param_1, u32 param_2, u32 param_3);
	static int DBfoundSize, DBfoundOffset;
	static void *DBfoundBlock, *DBnewFreeBlock, *DBnewUsedBlock;
	static os::OSThread *preEnd;

	byte isInitMutex;
	void *szpBuf;
	void *szpEnd;
	byte *refBuf, *refEnd;

	byte *refCurrent;
	os::OSMutex decompMutex;

	uint transLeft,
		readCount,
		srcOffset,
		fileOffset,
		maxDest;

	void *srcLimit;

	JKRDvdFile *srcFile;

	void *firstSrcData() {
		void *pvVar1;
		int iVar2;
		uint uVar3;

		pvVar1 = szpBuf;
		srcLimit = szpEnd + -0x19;
		uVar3 = (int)szpEnd - (int)szpBuf;
		if (transLeft < (uint)((int)szpEnd - (int)szpBuf)) {
			uVar3 = transLeft;
		}
		while (true) {
			iVar2 = dvd::DVDReadPrio(&srcFile->fileinfo, pvVar1, uVar3, srcOffset, 2);
			if (-1 < iVar2) {
				if (transLeft - uVar3 == 0) {
					srcLimit = pvVar1 + uVar3;
				}
				srcOffset = srcOffset + uVar3;
				transLeft = transLeft - uVar3;
				return pvVar1;
			}
			if ((iVar2 == -3) || (JKRDvdRipper::errorRetry == '\0'))
				break;
			vi::VIWaitForRetrace();
		}
		return nullptr;
	}

	byte *nextSrcData(byte *param_1) {
		ulong uVar1;
		int iVar2;
		uint uVar3;
		byte *pbVar4;
		byte *dst;

		uVar3 = (int)szpEnd - (int)param_1;
		dst = (byte *)szpBuf;
		if ((uVar3 & 0x1f) != 0) {
			dst = (byte *)((int)szpBuf + (0x20 - (uVar3 & 0x1f)));
		}
		//copy_bytes(dst, param_1, uVar3);
		memcpy(dst, param_1, uVar3);
		pbVar4 = dst + uVar3;
		uVar3 = (int)szpEnd - (int)pbVar4;
		if (transLeft < (uint)((int)szpEnd - (int)pbVar4)) {
			uVar3 = transLeft;
		}
		if (uVar3 == 0) {
			JUTAssertion::getSDevice()->showAssert("JKRDvdRipper.cpp", 0x498, "transSize > 0");
			m_Do_printf::OSPanic("JKRDvdRipper.cpp", 0x498, "Halt");
		}
		while (true) {
			iVar2 = dvd::DVDReadPrio(&srcFile->fileinfo, pbVar4, uVar3, srcOffset, 2);
			if (-1 < iVar2) {
				if (transLeft - uVar3 == 0) {
					srcLimit = pbVar4 + uVar3;
				}
				srcOffset = srcOffset + uVar3;
				transLeft = transLeft - uVar3;
				return dst;
			}
			if (iVar2 == -3)
				break;
			vi::VIWaitForRetrace();
		}
		return (byte *)0x0;
	}
	byte *dmaCurrent, *dmaBuf, *dmaEnd;

	uint JKernel::dmaBufferFlush(ulong param_1) {
		uint len;

		if (JKernel::dmaCurrent == JKernel::dmaBuf) {
			len = 0;
		} else {
			len = (JKernel::dmaCurrent - JKernel::dmaBuf) + 0x1f & 0xffffffe0;
			JKRAramPiece::orderSync(0, (ulong)JKernel::dmaBuf, param_1, len, (JKRAramBlock *)0x0);
			JKernel::dmaCurrent = JKernel::dmaBuf;
		}
		return len;
	}

	//
	undefined4 JKernel::decompSZS_subroutine(char *param_1, uint param_2)

	{
		undefined4 uVar1;
		int iVar2;
		int iVar3;
		byte *pbVar4;
		byte *pbVar5;
		uint uVar6;
		uint uVar7;
		int iVar8;
		byte *pbVar9;
		uint uVar10;

		iVar8 = 0;
		uVar7 = 0;
		if ((((*param_1 == 'Y') && (param_1[1] == 'a')) && (param_1[2] == 'z')) && (param_1[3] == '0')) {
			uVar10 = param_2 + (*(int *)(param_1 + 4) - JKernel::fileOffset);
			if (param_2 + JKernel::maxDest < uVar10) {
				uVar10 = param_2 + JKernel::maxDest;
			}
			pbVar4 = (byte *)(param_1 + 0x10);
			uVar6 = param_2;
			do {
				pbVar5 = pbVar4;
				if (iVar8 == 0) {
					if ((JKernel::srcLimit < pbVar4) && (JKernel::transLeft != 0)) {
						pbVar4 = (byte *)JKernel::nextSrcData(pbVar4);
					}
					uVar7 = (uint)*pbVar4;
					iVar8 = 8;
					pbVar5 = pbVar4 + 1;
				}
				if ((uVar7 & 0x80) == 0) {
					iVar2 = (int)(uint)*pbVar5 >> 4;
					pbVar9 = JKernel::refCurrent + (-1 - ((*pbVar5 & 0xf) << 8 | (uint)pbVar5[1]));
					pbVar4 = pbVar5 + 2;
					if (pbVar9 < JKernel::refBuf) {
						pbVar9 = pbVar9 + ((int)JKernel::refEnd - (int)JKernel::refBuf);
					}
					if (iVar2 == 0) {
						iVar2 = *pbVar4 + 0x12;
						pbVar4 = pbVar5 + 3;
					} else {
						iVar2 = iVar2 + 2;
					}
					do {
						if (JKernel::fileOffset <= JKernel::readCount) {
							pbVar5 = JKernel::dmaCurrent + 1;
							*JKernel::dmaCurrent = *pbVar9;
							JKernel::dmaCurrent = pbVar5;
							param_2 = param_2 + 1;
							if (JKernel::dmaCurrent == JKernel::dmaEnd) {
								iVar3 = JKernel::dmaBufferFlush(uVar6);
								uVar6 = uVar6 + iVar3;
							}
							if (param_2 == uVar10)
								break;
						}
						pbVar5 = JKernel::refCurrent + 1;
						*JKernel::refCurrent = *pbVar9;
						JKernel::refCurrent = pbVar5;
						if (JKernel::refCurrent == JKernel::refEnd) {
							JKernel::refCurrent = JKernel::refBuf;
						}
						pbVar9 = pbVar9 + 1;
						if (pbVar9 == JKernel::refEnd) {
							pbVar9 = JKernel::refBuf;
						}
						JKernel::readCount = JKernel::readCount + 1;
						iVar2 = iVar2 + -1;
					} while (iVar2 != 0);
				} else {
					if (JKernel::fileOffset <= JKernel::readCount) {
						pbVar4 = JKernel::dmaCurrent + 1;
						*JKernel::dmaCurrent = *pbVar5;
						JKernel::dmaCurrent = pbVar4;
						param_2 = param_2 + 1;
						if (JKernel::dmaCurrent == JKernel::dmaEnd) {
							iVar2 = JKernel::dmaBufferFlush(uVar6);
							uVar6 = uVar6 + iVar2;
						}
						if (param_2 == uVar10)
							break;
					}
					pbVar4 = JKernel::refCurrent + 1;
					*JKernel::refCurrent = *pbVar5;
					JKernel::refCurrent = pbVar4;
					if (JKernel::refCurrent == JKernel::refEnd) {
						JKernel::refCurrent = JKernel::refBuf;
					}
					JKernel::readCount = JKernel::readCount + 1;
					pbVar4 = pbVar5 + 1;
				}
				uVar7 = uVar7 << 1;
				iVar8 = iVar8 + -1;
			} while (param_2 < uVar10);
			JKernel::dmaBufferFlush(uVar6);
			uVar1 = 0;
		} else {
			uVar1 = 0xffffffff;
		}
		return uVar1;
	}

	// 802b4f20
	int decompSZS_subroutine(char *param_1, byte *param_2)

	{
		uint uVar1;
		byte *pbVar2;
		byte *pbVar3;
		int iVar4;
		int iVar5;
		uint uVar6;
		byte *pbVar7;
		byte *pbVar8;

		iVar4 = 0;
		uVar1 = 0;
		if ((((*param_1 == 'Y') && (param_1[1] == 'a')) && (param_1[2] == 'z')) && (param_1[3] == '0')) {
			pbVar8 = param_2 + (*(int *)(param_1 + 4) - fileOffset);
			if (param_2 + maxDest < param_2 + (*(int *)(param_1 + 4) - fileOffset)) {
				pbVar8 = param_2 + maxDest;
			}
			pbVar2 = (byte *)(param_1 + 0x10);
			do {
				pbVar3 = pbVar2;
				if (iVar4 == 0) {
					if (((srcLimit < pbVar2) && (transLeft != 0)) &&
						(pbVar2 = nextSrcData(pbVar2), pbVar2 == (byte *)0x0)) {
						return -1;
					}
					uVar1 = (uint)*pbVar2;
					iVar4 = 8;
					pbVar3 = pbVar2 + 1;
				}
				if ((uVar1 & 0x80) == 0) {
					uVar6 = (*pbVar3 & 0xf) << 8 | (uint)pbVar3[1];
					iVar5 = (int)(uint)*pbVar3 >> 4;
					pbVar2 = pbVar3 + 2;
					if (fileOffset == 0) {
						pbVar7 = param_2 + (-1 - uVar6);
					} else {
						pbVar7 = (byte *)refCurrent + (-1 - uVar6);
						if (pbVar7 < refBuf) {
							pbVar7 = pbVar7 + ((int)refEnd - (int)refBuf);
						}
					}
					if (iVar5 == 0) {
						iVar5 = *pbVar2 + 0x12;
						pbVar2 = pbVar3 + 3;
					} else {
						iVar5 = iVar5 + 2;
					}
					if (fileOffset == 0) {
						do {
							*param_2 = *pbVar7;
							param_2 = param_2 + 1;
							if (param_2 == pbVar8)
								break;
							readCount = readCount + 1;
							iVar5 = iVar5 + -1;
							pbVar7 = pbVar7 + 1;
						} while (iVar5 != 0);
					} else {
						do {
							if (fileOffset <= readCount) {
								*param_2 = *pbVar7;
								param_2 = param_2 + 1;
								if (param_2 == pbVar8)
									break;
							}
							pbVar3 = (byte *)refCurrent + 1;
							*refCurrent = *pbVar7;
							refCurrent = pbVar3;
							if (refCurrent == refEnd) {
								refCurrent = refBuf;
							}
							pbVar7 = pbVar7 + 1;
							if (pbVar7 == refEnd) {
								pbVar7 = refBuf;
							}
							readCount = readCount + 1;
							iVar5 = iVar5 + -1;
						} while (iVar5 != 0);
					}
				} else {
					if (fileOffset == 0) {
						*param_2 = *pbVar3;
						param_2 = param_2 + 1;
						if (param_2 == pbVar8)
							break;
					} else {
						if (fileOffset <= readCount) {
							*param_2 = *pbVar3;
							param_2 = param_2 + 1;
							if (param_2 == pbVar8)
								break;
						}
						pbVar2 = refCurrent + 1;
						*refCurrent = *pbVar3;
						refCurrent = pbVar2;
						if (refCurrent == refEnd) {
							refCurrent = refBuf;
						}
					}
					pbVar2 = pbVar3 + 1;
					readCount = readCount + 1;
				}
				uVar1 = uVar1 << 1;
				iVar4 = iVar4 + -1;
			} while (param_2 < pbVar8);
			iVar4 = 0;
		} else {
			iVar4 = -1;
		}
		return iVar4;
	}

	int JKRDecompressFromDVD(JKRDvdFile *param_1, void *param_2, uint param_3, uint param_4, uint param_5, uint param_6) {
		using namespace os;

		undefined4 uVar1;
		ulong uVar2;
		int iVar3;
		int puVar4;

		uVar1 = os::OSDisableInterrupts();
		if (isInitMutex == '\0') {
			os::OSInitMutex(&decompMutex);
			isInitMutex = '\x01';
		}
		os::OSRestoreInterrupts(uVar1);
		os::OSLockMutex(&decompMutex);
		iVar3 = JKRDvdRipper::sSzpBufferSize;
		szpBuf = JKRHeap::sSystemHeap->alloc(JKRDvdRipper::sSzpBufferSize, -0x20);
		if (szpBuf == nullptr) {
			JUTAssertion::getSDevice()->showAssert("JKRDvdRipper.cpp", 0x374, "szpBuf != 0");
			m_Do_printf::OSPanic("JKRDvdRipper.cpp", 0x374, "Halt");
		}
		szpEnd = szpBuf + iVar3;
		if (param_5 == 0) {
			refBuf = nullptr;
		} else {
			refBuf = (byte *)JKRHeap::sSystemHeap->alloc(0x1120, -4);
			if (refBuf == nullptr) {
				JUTAssertion::getSDevice()->showAssert("JKRDvdRipper.cpp", 0x37d, "refBuf != 0");
				m_Do_printf::OSPanic("JKRDvdRipper.cpp", 0x37d, "Halt");
			}
			refEnd = refBuf + 0x1120;
			refCurrent = refBuf;
		}
		transLeft = param_3 - param_6;
		readCount = 0;
		srcOffset = param_6;
		srcFile = param_1;
		fileOffset = param_5;
		maxDest = param_4;
		auto piVar3 = firstSrcData();
		if (piVar3 == 0) {
			puVar4 = -1;
		} else {
			puVar4 = decompSZS_subroutine((char *)piVar3, (byte *)param_2);
		}
		uVar1 = *(undefined4 *)(piVar3 + 4);
		JKRHeap::free(szpBuf, nullptr);
		if (refBuf) {
			JKRHeap::free(refBuf, nullptr);
		}
		os::DCStoreRangeNoSync(param_2, uVar1);
		os::OSUnlockMutex(&decompMutex);
		return puVar4;
	}

	void JKRDecompressFromDVDToAram(JKRDvdFile *srcFile, undefined4 blksize, int totalsize, undefined4 maxDest,
									undefined4 fileOffset, int srcOffset)

	{
		undefined4 uVar1;
		ulong uVar2;
		int iVar3;

		uVar1 = os::OSDisableInterrupts();
		if (JKernel::isInitMutex == '\0') {
			os::OSInitMutex(&JKernel::decompMutex);
			JKernel::isInitMutex = '\x01';
		}
		os::OSRestoreInterrupts(uVar1);
		os::OSLockMutex(&JKernel::decompMutex);
		iVar3 = JKRDvdAramRipper::sSzpBufferSize;
		JKernel::szpBuf = (undefined *)JKRHeap::sSystemHeap->alloc(iVar3, 0x20);
		if (!JKernel::szpBuf) {
			JUTAssertion::getSDevice()->showAssert("JKRDvdAramRipper.cpp", 0x2b5, "szpBuf != 0");
			m_Do_printf::OSPanic("JKRDvdAramRipper.cpp", 0x2b5, "Halt");
		}
		JKernel::szpEnd = JKernel::szpBuf + iVar3;
		JKernel::refBuf = (byte *)JKRHeap::sSystemHeap->alloc(0x1120, 0);
		if (!JKernel::refBuf) {
			JUTAssertion::getSDevice()->showAssert("JKRDvdAramRipper.cpp", 0x2bd, "refBuf != 0");
			m_Do_printf::OSPanic("JKRDvdAramRipper.cpp", 0x2bd, "Halt");
		}
		JKernel::refEnd = JKernel::refBuf + 0x1120;
		JKernel::refCurrent = JKernel::refBuf;
		JKernel::dmaBuf = (byte *)JKRHeap::sSystemHeap->alloc(0x100, 0x20);
		if (JKernel::dmaBuf == (void *)0x0) {
			JUTAssertion::getSDevice()->showAssert("JKRDvdAramRipper.cpp", 0x2c6, "dmaBuf != 0");
			m_Do_printf::OSPanic("JKRDvdAramRipper.cpp", 0x2c6, "Halt");
		}
		JKernel::dmaEnd = JKernel::dmaBuf + 0x100;
		JKernel::dmaCurrent = JKernel::dmaBuf;
		JKernel::transLeft = totalsize - srcOffset;
		JKernel::readCount = 0;
		JKernel::srcOffset = srcOffset;
		JKernel::srcFile = srcFile;
		JKernel::fileOffset = fileOffset;
		JKernel::maxDest = maxDest;
		char *data = (char *)JKernel::firstSrcData();
		if (data == 0) {
			uVar1 = 0xffffffff;
		} else {
			uVar1 = JKernel::decompSZS_subroutine(data, blksize);
		}
		JKRHeap::free(JKernel::szpBuf, (JKRHeap *)0x0);
		JKRHeap::free(JKernel::refBuf, (JKRHeap *)0x0);
		JKRHeap::free(JKernel::dmaBuf, (JKRHeap *)0x0);
		os::OSUnlockMutex(&JKernel::decompMutex);
	}
}

void *operator new(ulong size);
void *operator new(ulong size, int param_2);
void *operator new(ulong size, void *an) {
	return an;
}
void *operator new(ulong size, JKRHeap *heap, int align);
void *operator new[](unsigned long param_1);
void *operator new[](unsigned long param_1, int param_2);
void *operator new[](unsigned long param_1, JKRHeap *param_2, int param_3);

void operator delete(void *ptr);
void operator delete[](void *param_1);