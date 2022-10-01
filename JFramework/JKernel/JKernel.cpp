#include <doltypes.h>
#include <dolphin/vi.h>

#include <machine/dolphin/printf.h>
#include "JKRAramPiece.h"
#include "JKRDvdRipper.h"
#include "../JSupport/JSUIosBase.h"
#include "JKRHeap.h"
#include "JKRExpHeap.h"
#include "JKRDvdAramRipper.h"

void *operator new(ulong size) {
	void *pvVar1;

	pvVar1 = (void *)JKRHeap::alloc(size, 4, (JKRHeap *)0x0);
	return pvVar1;
}

void *operator new(ulong size, int param_2) {
	void *pvVar1;

	pvVar1 = (void *)JKRHeap::alloc(size, param_2, (JKRHeap *)0x0);
	return pvVar1;
}

void *operator new(ulong size, JKRHeap *heap, int align) {
	void *pvVar1;

	pvVar1 = (void *)JKRHeap::alloc(size, align, heap);
	return pvVar1;
}

void *operator new[](unsigned long param_1) {
	return JKRHeap::alloc(param_1, 4, nullptr);
}

void *operator new[](unsigned long param_1, int param_2) {
	return JKRHeap::alloc(param_1, param_2, nullptr);
}

void *operator new[](unsigned long param_1, JKRHeap *param_2, int param_3) {
	return JKRHeap::alloc(param_1, param_3, param_2);
}

void operator delete(void *ptr) {
	JKRHeap::free(ptr, nullptr);
}

void operator delete[](void *param_1) {
	JKRHeap::free(param_1, nullptr);
}

namespace JKernel {
	void JKRDefaultMemoryErrorRoutine(JKRHeap *param_1, int param_2, int param_3) {
		m_Do_printf::OSReport("Error: Cannot allocate memory %d(0x%x)byte in %d byte alignment from %08x\n", param_2,
							  param_2, param_3, param_1);
		m_Do_printf::OSPanic("JKRHeap.cpp", 0x2ff, "abort\n");
		return;
	}
}

namespace JKernel {
	char rootPath$2460[] = "/";
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

	uint dmaBufferFlush(ulong param_1) {
		uint len;

		if (dmaCurrent == dmaBuf) {
			len = 0;
		} else {
			len = (dmaCurrent - dmaBuf) + 0x1f & 0xffffffe0;
			JKRAramPiece::orderSync(0, (ulong)dmaBuf, param_1, len, (JKRAramBlock *)0x0);
			dmaCurrent = dmaBuf;
		}
		return len;
	}

	//
	undefined4 decompSZS_subroutine(char *param_1, uint param_2) {
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
			uVar10 = param_2 + (*(int *)(param_1 + 4) - fileOffset);
			if (param_2 + maxDest < uVar10) {
				uVar10 = param_2 + maxDest;
			}
			pbVar4 = (byte *)(param_1 + 0x10);
			uVar6 = param_2;
			do {
				pbVar5 = pbVar4;
				if (iVar8 == 0) {
					if ((srcLimit < pbVar4) && (transLeft != 0)) {
						pbVar4 = (byte *)nextSrcData(pbVar4);
					}
					uVar7 = (uint)*pbVar4;
					iVar8 = 8;
					pbVar5 = pbVar4 + 1;
				}
				if ((uVar7 & 0x80) == 0) {
					iVar2 = (int)(uint)*pbVar5 >> 4;
					pbVar9 = refCurrent + (-1 - ((*pbVar5 & 0xf) << 8 | (uint)pbVar5[1]));
					pbVar4 = pbVar5 + 2;
					if (pbVar9 < refBuf) {
						pbVar9 = pbVar9 + ((int)refEnd - (int)refBuf);
					}
					if (iVar2 == 0) {
						iVar2 = *pbVar4 + 0x12;
						pbVar4 = pbVar5 + 3;
					} else {
						iVar2 = iVar2 + 2;
					}
					do {
						if (fileOffset <= readCount) {
							pbVar5 = dmaCurrent + 1;
							*dmaCurrent = *pbVar9;
							dmaCurrent = pbVar5;
							param_2 = param_2 + 1;
							if (dmaCurrent == dmaEnd) {
								iVar3 = dmaBufferFlush(uVar6);
								uVar6 = uVar6 + iVar3;
							}
							if (param_2 == uVar10)
								break;
						}
						pbVar5 = refCurrent + 1;
						*refCurrent = *pbVar9;
						refCurrent = pbVar5;
						if (refCurrent == refEnd) {
							refCurrent = refBuf;
						}
						pbVar9 = pbVar9 + 1;
						if (pbVar9 == refEnd) {
							pbVar9 = refBuf;
						}
						readCount = readCount + 1;
						iVar2 = iVar2 + -1;
					} while (iVar2 != 0);
				} else {
					if (fileOffset <= readCount) {
						pbVar4 = dmaCurrent + 1;
						*dmaCurrent = *pbVar5;
						dmaCurrent = pbVar4;
						param_2 = param_2 + 1;
						if (dmaCurrent == dmaEnd) {
							iVar2 = dmaBufferFlush(uVar6);
							uVar6 = uVar6 + iVar2;
						}
						if (param_2 == uVar10)
							break;
					}
					pbVar4 = refCurrent + 1;
					*refCurrent = *pbVar5;
					refCurrent = pbVar4;
					if (refCurrent == refEnd) {
						refCurrent = refBuf;
					}
					readCount = readCount + 1;
					pbVar4 = pbVar5 + 1;
				}
				uVar7 = uVar7 << 1;
				iVar8 = iVar8 + -1;
			} while (param_2 < uVar10);
			dmaBufferFlush(uVar6);
			uVar1 = 0;
		} else {
			uVar1 = 0xffffffff;
		}
		return uVar1;
	}

	// 802b4f20
	int decompSZS_subroutine(char *param_1, byte *param_2) {
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
									undefined4 fileOffset, int srcOffset) {
		undefined4 uVar1;
		ulong uVar2;
		int iVar3;

		uVar1 = os::OSDisableInterrupts();
		if (isInitMutex == '\0') {
			os::OSInitMutex(&decompMutex);
			isInitMutex = '\x01';
		}
		os::OSRestoreInterrupts(uVar1);
		os::OSLockMutex(&decompMutex);
		iVar3 = JKRDvdAramRipper::sSzpBufferSize;
		szpBuf = (undefined *)JKRHeap::sSystemHeap->alloc(iVar3, 0x20);
		if (!szpBuf) {
			JUTAssertion::getSDevice()->showAssert("JKRDvdAramRipper.cpp", 0x2b5, "szpBuf != 0");
			m_Do_printf::OSPanic("JKRDvdAramRipper.cpp", 0x2b5, "Halt");
		}
		szpEnd = szpBuf + iVar3;
		refBuf = (byte *)JKRHeap::sSystemHeap->alloc(0x1120, 0);
		if (!refBuf) {
			JUTAssertion::getSDevice()->showAssert("JKRDvdAramRipper.cpp", 0x2bd, "refBuf != 0");
			m_Do_printf::OSPanic("JKRDvdAramRipper.cpp", 0x2bd, "Halt");
		}
		refEnd = refBuf + 0x1120;
		refCurrent = refBuf;
		dmaBuf = (byte *)JKRHeap::sSystemHeap->alloc(0x100, 0x20);
		if (dmaBuf == (void *)0x0) {
			JUTAssertion::getSDevice()->showAssert("JKRDvdAramRipper.cpp", 0x2c6, "dmaBuf != 0");
			m_Do_printf::OSPanic("JKRDvdAramRipper.cpp", 0x2c6, "Halt");
		}
		dmaEnd = dmaBuf + 0x100;
		dmaCurrent = dmaBuf;
		transLeft = totalsize - srcOffset;
		readCount = 0;
		srcOffset = srcOffset;
		srcFile = srcFile;
		fileOffset = fileOffset;
		maxDest = maxDest;
		char *data = (char *)firstSrcData();
		if (data == 0) {
			uVar1 = 0xffffffff;
		} else {
			uVar1 = decompSZS_subroutine(data, blksize);
		}
		JKRHeap::free(szpBuf, (JKRHeap *)0x0);
		JKRHeap::free(refBuf, (JKRHeap *)0x0);
		JKRHeap::free(dmaBuf, (JKRHeap *)0x0);
		os::OSUnlockMutex(&decompMutex);
	}
}
