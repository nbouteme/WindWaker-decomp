#pragma once

#include <dolphin/os.h>

#include "../JSupport/JSUIosBase.h"
#include "../JSupport/JSUPtrList.h"

struct JKRADCommand : public JSUPtrLink {
	JKRDvdFile *dvdfile;
	uint offset, availableAramBuffer, size;
	JKRAramBlock *aramAreaPointer;
	JKRExpandSwitch expand;
	byte unused[24];
	void (*callback)(JKRADCommand *);
	int commandsucc;
	byte dataloaded;
	JKRAramStreamCommand *streamcmd;
	JKRADCommand() : JSUPtrLink(this) {}
};

namespace JKRDvdAramRipper {
	int sSzpBufferSize;
	JSUPtrList sDvdAramAsyncList;

	undefined4 syncAram(JKRADCommand *param_1, int param_2) {
		JKRAramStreamCommand *pJVar1;
		int *piVar2;
		JKRDvdFile *pJVar3;

		pJVar3 = param_1->dvdfile;
		os::OSLockMutex(&pJVar3->mutex2);
		pJVar1 = param_1->streamcmd;
		if (pJVar1 != (JKRAramStreamCommand *)0x0) {
			JKRAramStream::sync(pJVar1, param_2);
			param_1->commandsucc = -(uint)(pJVar1 == (JKRAramStreamCommand *)0x0);
			if ((param_2 != 0) && (pJVar1 == (JKRAramStreamCommand *)0x0)) {
				os::OSUnlockMutex(&pJVar3->mutex2);
				return 0;
			}
		}
		JKRDvdAramRipper::sDvdAramAsyncList.remove(param_1);
		if (param_1->streamcmd != (JKRAramStreamCommand *)0x0) {
			delete (param_1->streamcmd);
		}
		delete pJVar3->fileinputstream;
		pJVar3->executionThread = 0;
		os::OSUnlockMutex(&pJVar3->mutex2);
		return 1;
	}

	byte errorRetry;

	JKRADCommand *JKRDvdAramRipper::callCommand_Async(JKRADCommand *param_1)

	{
		bool bVar1;
		uint uVar2;
		os::OSThread *pOVar3;
		JSUFileInputStream *fileinputstream;
		uint uVar4;
		int iVar6;
		JKRAramBlock *iVar5;
		JKRAramBlock *pJVar7;
		JKRAramStreamCommand *pJVar8;
		ulong unaff_r25;
		JKRDecomp__CompressionType JVar9;
		JKRDvdFile *pJVar10;
		uchar auStack96[4];
		byte bStack92;
		byte bStack91;
		byte bStack90;
		byte bStack89;

		bVar1 = true;
		pJVar10 = param_1->dvdfile;
		JVar9 = NotCompressed;
		os::OSLockMutex(&pJVar10->mutex2);
		if (pJVar10->executionThread == 0) {
			pOVar3 = os::OSGetCurrentThread();
			pJVar10->executionThread = pOVar3;
			fileinputstream = new (JKRHeap::sSystemHeap, -4) JSUFileInputStream(pJVar10);
			pJVar10->fileinputstream = fileinputstream;
			uVar4 = pJVar10->getFileSize();
			uVar2 = param_1->availableAramBuffer;
			if ((uVar2 != 0) && (uVar2 < uVar4)) {
				uVar4 = uVar2;
			}
			uVar4 = uVar4 + 0x1f & 0xffffffe0;
			if (param_1->expand == 1) {
				while (iVar6 = dvd::DVDReadPrio(&pJVar10->fileinfo, auStack96, 0x20, 0, 2), iVar6 < 0) {
					if (JKRDvdAramRipper::errorRetry == '\0') {
						delete fileinputstream;
						return (JKRADCommand *)0x0;
					}
					vi::VIWaitForRetrace();
				}
				os::DCInvalidateRange(auStack96, 0x20);
				JVar9 = JKRDecomp::checkCompressed(auStack96);
				unaff_r25 = (uint)bStack89 |
							(uint)bStack90 << 8 | (uint)bStack92 << 0x18 | (uint)bStack91 << 0x10;
				uVar2 = param_1->availableAramBuffer;
				if ((uVar2 != 0) && (uVar2 < unaff_r25)) {
					unaff_r25 = uVar2;
				}
			}
			if (JVar9 == NotCompressed) {
				param_1->expand = 0;
			}
			if (param_1->expand == 1) {
				if ((param_1->size == 0) && (param_1->aramAreaPointer == (JKRAramBlock *)0x0)) {
					iVar5 = JKRAram::sAramObject->mpHeap->alloc(unaff_r25, 0);
					param_1->aramAreaPointer = iVar5;
					if (param_1->aramAreaPointer != (JKRAramBlock *)0x0) {
						param_1->size = param_1->aramAreaPointer->roundedupaddr;
					}
					pJVar10->aramAreaPointer = param_1->aramAreaPointer;
				}
				if (param_1->aramAreaPointer != (JKRAramBlock *)0x0) {
					param_1->size = param_1->aramAreaPointer->roundedupaddr;
				}
				if (param_1->size == 0) {
					pJVar10->executionThread = 0;
					return (JKRADCommand *)0x0;
				}
			} else {
				if ((param_1->size == 0) && (param_1->aramAreaPointer == (JKRAramBlock *)0x0)) {
					pJVar7 = JKRAram::sAramObject->mpHeap->alloc(uVar4, 0);
					param_1->aramAreaPointer = pJVar7;
				}
				if (param_1->aramAreaPointer != (JKRAramBlock *)0x0) {
					param_1->size = param_1->aramAreaPointer->roundedupaddr;
				}
				if (param_1->size == 0) {
					pJVar10->executionThread = 0;
					return (JKRADCommand *)0x0;
				}
			}
			if (JVar9 == NotCompressed) {
				pJVar8 = JKRAramStream::write_StreamToAram_Async(fileinputstream, param_1->size, uVar4 - param_1->offset, param_1->offset);
				param_1->streamcmd = pJVar8;
			} else if (JVar9 == Yay0Compressed) {
				pJVar8 = JKRAramStream::write_StreamToAram_Async(fileinputstream, param_1->size, uVar4 - param_1->offset, param_1->offset);
				param_1->streamcmd = pJVar8;
			} else if (JVar9 == Yaz0Compressed) {
				param_1->streamcmd = (JKRAramStreamCommand *)0x0;
				JKernel::JKRDecompressFromDVDToAram(param_1->dvdfile, /*blksize*/param_1->size, /*totalsize*/uVar4, /*maxDest*/unaff_r25, /*fileoffset*/param_1->offset, /*srcoffset*/0);
			}
			if (!param_1->callback) {
				JKRDvdAramRipper::sDvdAramAsyncList.append(param_1);
			} else {
				(*param_1->callback)(param_1);
			}
		} else {
			bVar1 = false;
		}
		os::OSUnlockMutex(&pJVar10->mutex2);
		if (!bVar1) {
			param_1 = (JKRADCommand *)0x0;
		}
		return param_1;
	}

	JKRADCommand *JKRDvdAramRipper::loadToAram_Async(JKRDvdFile *param_1, ulong param_2, JKRExpandSwitch param_3, void (*callback)(JKRADCommand *),
													 ulong offset, ulong aramBuffSize)

	{
		JKRADCommand *cmd;
		JKRADCommand *iVar1;

		cmd = new (JKRHeap::sSystemHeap, -4) JKRADCommand();
		cmd->dvdfile = param_1;
		cmd->size = param_2;
		cmd->aramAreaPointer = 0;
		cmd->expand = param_3;
		cmd->callback = callback;
		cmd->offset = offset;
		cmd->availableAramBuffer = aramBuffSize;
		iVar1 = JKRDvdAramRipper::callCommand_Async(cmd);
		if (iVar1 == 0) {
			delete cmd;
			cmd = (JKRADCommand *)0x0;
		}
		return cmd;
	}

	JKRAramBlock *loadToAram(JKRDvdFile *dvdfile, ulong size, JKRExpandSwitch expand, ulong offset, ulong param_5) {
		JKRADCommand *self;
		JKRAramBlock *iVar1;

		self = loadToAram_Async(dvdfile, size, expand, nullptr, offset, param_5);
		JKRDvdAramRipper::syncAram(self, 0);
		if (self->commandsucc < 0) {
			iVar1 = 0;
		} else if (size == 0) {
			iVar1 = self->aramAreaPointer;
		} else {
			iVar1 = (JKRAramBlock *)-1;
		}
		return iVar1;
	}

	JKRAramBlock *loadToAram(long param_1, ulong param_2, JKRExpandSwitch param_3, ulong param_4, ulong param_5)

	{
		uint uVar1;
		undefined4 uVar2;
		JKRDvdFile JStack280;

		uVar1 = JStack280.open(param_1);
		if ((uVar1 & 0xff) == 0) {
			return 0;
		}
		return JKRDvdAramRipper::loadToAram(&JStack280, param_2, param_3, param_4, param_5);
	}
};
