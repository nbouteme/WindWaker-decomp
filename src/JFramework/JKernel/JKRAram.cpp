#include "JKRAram.h"

#include <cstdlib>

#include "../JSupport/JSUIosBase.h"
#include "JKRAramHeap.h"
#include "JKRDecomp.h"
#include "JKRExpHeap.h"
#include "JKernel.h"

JKRAramStreamCommand::JKRAramStreamCommand() {
	fullfilled = 0;
}

JKRAramStream *JKRAramStream::sAramStreamObject;
void *JKRAramStream::transBuffer;
uint JKRAramStream::transSize;
JKRHeap *JKRAramStream::transHeap;

JKRAramStreamCommand *JKRAramStream::write_StreamToAram_Async(JSUFileInputStream *param_1, ulong param_2, ulong param_3, ulong param_4) {
	JKRAramStreamCommand *command = new ((JKRHeap *)JKRHeap::sSystemHeap, -4) JKRAramStreamCommand();
	command->direction = 2;
	command->dest = param_2;
	command->remaining = param_3;
	command->inputstream = (JSURandomInputStream *)param_1;
	command->stat = 0;
	command->currentOffset = param_4;
	command->buffadr = JKRAramStream::transBuffer;
	command->heap = JKRAramStream::transHeap;
	command->size = JKRAramStream::transSize;
	os::OSInitMessageQueue(&command->mqueue, command->msgs, 1);
	os::OSSendMessage(&JKRAramStream::sMessageQueue, command, 1);
	return command;
}

void JKRAramStream::setTransBuffer(byte *param_1, ulong param_2, JKRHeap *param_3) {
	transBuffer = 0;
	transSize = 0x400;
	if (param_1) {
		transBuffer = (void *)(((uint)param_1 + 0x1f) & 0xffffffe0);
	}
	if (param_2) {
		transSize = param_2 & 0xffffffe0;
	}
	if (!param_3) {
		transHeap = nullptr;
		return;
	}
	if (param_1) {
		transHeap = nullptr;
		return;
	}
	transHeap = param_3;
}

int JKRAramStream::readFromAram() {
	return 1;
}

os::OSMessageQueue JKRAramStream::sMessageQueue;
os::OSMessage JKRAramStream::sMessageBuffer[4];

int JKRAramStream::writeToAram(JKRAramStreamCommand *param_1) {
	uint uVar1;
	ssize_t sVar2;
	void *__buf;
	ulong size;
	uint uVar3;
	JKRHeap *pHeap;
	ulong dest;
	int iVar4;
	uint uVar5;

	uVar5 = param_1->remaining;
	uVar3 = param_1->currentOffset;
	iVar4 = 0;
	dest = param_1->dest;
	__buf = param_1->buffadr;
	uVar1 = param_1->size;
	pHeap = param_1->heap;
	if (__buf == nullptr) {
		size = 0x400;
		if (uVar1 != 0) {
			size = uVar1;
		}
		if (pHeap == nullptr) {
			__buf = (void *)JKRHeap::alloc(size, -0x20, nullptr);
			param_1->buffadr = __buf;
		} else {
			__buf = (void *)JKRHeap::alloc(size, -0x20, pHeap);
			param_1->buffadr = __buf;
		}
		param_1->size = size;
		param_1->fullfilled = 1;
	} else {
		size = 0x400;
		if (uVar1 != 0) {
			size = uVar1;
		}
		param_1->size = size;
		param_1->fullfilled = 0;
	}
	if (__buf == nullptr) {
		if (pHeap == nullptr) {
			JKRHeap::sCurrentHeap->dump();
		} else {
			pHeap->dump();
		}
		m_Do_printf::OSReport(":::Cannot alloc memory [%s][%d]\n", "JKRAramStream.cpp", 0xa8);
		m_Do_printf::OSPanic("JKRAramStream.cpp", 0xa9, "abort\n");
	}
	if (__buf != nullptr) {
		param_1->inputstream->seekPos(uVar3, 0);
		// JSURandomInputStream::seek(param_1->inputstream, uVar3, 0);
		for (; uVar5 != 0; uVar5 = uVar5 - uVar1) {
			uVar1 = uVar5;
			if (size < uVar5) {
				uVar1 = size;
			}
			// TODO: implement
			sVar2 = param_1->inputstream->read(__buf, uVar1);
			// sVar2 = JSUInputStream::read((JSUInputStream *)param_1->inputstream, __buf, uVar1);
			if (sVar2 == 0) {
				iVar4 = 0;
				break;
			}
			// JKRAramPiece::orderSync(0, (ulong)__buf, dest, uVar1, nullptr);
			iVar4 = iVar4 + uVar1;
			dest = dest + uVar1;
		}
		if (param_1->fullfilled != '\0') {
			JKRHeap::free(__buf, nullptr);
			param_1->fullfilled = 0;
		}
	}
	os::OSSendMessage(&param_1->mqueue, (void **)&iVar4, 0);
	return iVar4;
}

void *JKRAramStream::run() {
	int iVar1;
	JKRAramStreamCommand *local_18[5];

	os::OSInitMessageQueue((os::OSMessageQueue *)&JKRAramStream::sMessageQueue,
						   (os::OSMessage *)&JKRAramStream::sMessageBuffer, 4);
	do {
		while (true) {
			os::OSReceiveMessage(&JKRAramStream::sMessageQueue, (void **)local_18, 1);
			iVar1 = *(int *)local_18[0];
			if (iVar1 != 2)
				break;
			JKRAramStream::writeToAram(local_18[0]);
		}
		if ((iVar1 < 2) && (0 < iVar1)) {
			JKRAramStream::readFromAram();
		}
	} while (true);
	return nullptr;
}

void JKRAramStream::sync(JKRAramStreamCommand *param_1, int param_2) {
	undefined4 local_18[5];

	if (param_2 == 0) {
		os::OSReceiveMessage(&param_1->mqueue, (void **)local_18, 1);
	} else {
		os::OSReceiveMessage(&param_1->mqueue, (void **)local_18, 0);
	}
	return;
}

JKRAramStream *JKRAramStream::create(int param_1) {
	JKRAramStream *self;

	if (!sAramStreamObject) {
		param_1 = 0;
		self = new ((JKRHeap *)JKRHeap::sSystemHeap, 0) JKRAramStream(param_1);
		sAramStreamObject = self;
		JKRAramStream::setTransBuffer(nullptr, 0, nullptr);
	}
	return sAramStreamObject;
}
#include <cstdio>
JKRAramStream::JKRAramStream(uint p) : JKRThread(0x4000, 0x10, p) {
	os::OSResumeThread(this->thread);
}

JKRAram *JKRAram::sAramObject;
JSUPtrList JKRAram::sAramCommandList;
os::OSMessageQueue JKRAram::sMessageQueue;
int JKRAram::sSzpBufferSize;

JKRAram::~JKRAram() {}

JKRAram::JKRAram(unsigned param_1, unsigned param_2, unsigned param_3) : JKRThread(0x4000, 0x10, param_3) {
	int aramuserbase;
	int aramsize;
	undefined4 uVar1;
	ulong uVar2;

	aramuserbase = ar::ARInit((u32 *)this->stackbase, 3);
	ar::ARQInit();
	aramsize = ar::ARGetSize();
	m_Do_printf::OSReport("ARAM size = %08x\n", aramsize);
	this->audioAreaSize = param_1;
	if (param_2 == 0xffffffff) {
		this->graphAreaSize = (aramsize - param_1) - aramuserbase;
		this->userAreaSize = 0;
	} else {
		this->graphAreaSize = param_2;
		this->userAreaSize = (aramsize - (param_1 + param_2)) - aramuserbase;
	}
	this->audioArea = ar::ARAlloc(this->audioAreaSize);
	this->graphArea = ar::ARAlloc(this->graphAreaSize);
	if (this->userAreaSize == 0) {
		this->userArea = 0;
	} else {
		this->userArea = ar::ARAlloc(this->userAreaSize);
	}
	m_Do_printf::OSReport("ARAM audio area %08x: %08x\n", this->audioArea, this->audioAreaSize);
	m_Do_printf::OSReport("ARAM graph area %08x: %08x\n", this->graphArea, this->graphAreaSize);
	m_Do_printf::OSReport("ARAM  user area %08x: %08x\n", this->userArea, this->userAreaSize);
	this->mpHeap = new ((JKRHeap *)JKRHeap::sSystemHeap, 0) JKRAramHeap(this->graphArea, this->graphAreaSize);
}

JKRAram *JKRAram::create(ulong param_1, ulong param_2, long param_3, long param_4, long param_5) {
	JKRAram *self;

	self = JKRAram::sAramObject;
	if (!self) {
		self = new JKRAram(param_1, param_2, param_5);
	}
	JKRAram::sAramObject = self;
	JKRAramStream::create(param_3);
	JKRDecomp::create(param_4);
	os::OSResumeThread(JKRAram::sAramObject->thread);
	return self;
}

undefined4 JKRAram::checkOkAddress(byte *param_1, ulong param_2, JKRAramBlock *param_3, ulong param_4) {
	undefined4 uVar1;

	if ((((uint)param_1 & 0x1f) == 0) || ((param_2 & 0x1f) == 0)) {
		if ((param_3 == nullptr) || ((param_4 + param_3->roundedupaddr & 0x1f) == 0)) {
			uVar1 = 1;
		} else {
			m_Do_printf::OSPanic("JKRAram.cpp", 0xeb, ":::address not 32Byte aligned.");
			uVar1 = 0;
		}
	} else {
		m_Do_printf::OSPanic("JKRAram.cpp", 0xe2, ":::address not 32Byte aligned.");
		uVar1 = 0;
	}
	return uVar1;
}

void JKRAram::changeGroupIdIfNeed(byte *param_1, int param_2) {
	int iVar1;

	if ((-1 < param_2) &&
		(iVar1 = (JKRHeap::sCurrentHeap->getHeapType)(), iVar1 == 0x45585048)) {
		param_1[-0xd] = (byte)param_2;
	}
}

JKRAramBlock *JKRAram::mainRamToAram(uchar *param_1, ulong dest, ulong len, JKRExpandSwitch param_4, ulong param_5,
									 JKRHeap *param_6, int param_7) {
	uchar uVar1;
	JKRDecomp__CompressionType JVar2;
	uchar *source;
	uint uVar3;
	JKRAramBlock *pJVar4;

	pJVar4 = 0;
	JKRAram::checkOkAddress(param_1, dest, nullptr, 0);
	if (param_4 == 1) {
		JVar2 = JKRDecomp::checkCompressed(param_1);
		param_4 = (JKRExpandSwitch)(JVar2 != NotCompressed);
	}
	uVar1 = (uchar)param_7;
	if (param_4 == 1) {
		JVar2 = JKRDecomp::checkCompressed(param_1);
		if (JVar2 == NotCompressed) {
			uVar3 = 0;
		} else {
			uVar3 = (uint)param_1[7] |
					(uint)param_1[6] << 8 | (uint)param_1[4] << 0x18 | (uint)param_1[5] << 0x10;
		}
		if ((param_5 == 0) || (uVar3 < param_5)) {
			param_5 = uVar3;
		}
		if (dest == 0) {
			pJVar4 = JKRAram::sAramObject->mpHeap->alloc(param_5, 0);
			if (pJVar4 == nullptr) {
				return 0;
			}
			if (param_7 < 0) {
				uVar1 = JKRAram::sAramObject->mpHeap->status;
			}
			pJVar4->filltype = uVar1;
			dest = pJVar4->roundedupaddr;
		}
		if ((len == 0) || (uVar3 < len)) {
			len = uVar3;
		}
		if (len < param_5) {
			param_5 = len;
		}
		source = (uchar *)JKRHeap::alloc(param_5, -0x20, param_6);
		if (source == nullptr) {
			if ((pJVar4 != nullptr) &&
				(pJVar4 != nullptr)) {
				/* delete */
				delete pJVar4;
			}
			pJVar4 = 0;
		} else {
			JKRDecomp::orderSync(param_1, source, param_5, 0);
			JKRAramPiece::orderSync(0, (ulong)source, dest, len, pJVar4);
			JKRHeap::free(source, param_6);
			if (pJVar4 == nullptr) {
				pJVar4 = (JKRAramBlock *)~0ul;
			}
		}
	} else {
		if (dest == 0) {
			pJVar4 = JKRAram::sAramObject->mpHeap->alloc(len, 0);
			if (param_7 < 0) {
				uVar1 = JKRAram::sAramObject->mpHeap->status;
			}
			*(uchar *)(pJVar4 + 0x20) = uVar1;
			if (pJVar4 == nullptr) {
				return 0;
			}
			dest = pJVar4->roundedupaddr;
		}
		JKRAramPiece::orderSync(0, (ulong)param_1, dest, len, pJVar4);
		if (pJVar4 == nullptr) {
			pJVar4 = (JKRAramBlock *)~0ul;
		}
	}
	return pJVar4;
}

JKRAramBlock *JKRAram::mainRamToAram(uchar *param_1, JKRAramBlock *param_2, ulong param_3, JKRExpandSwitch param_4,
									 ulong param_5, JKRHeap *param_6, int param_7) {
	uint uVar1;

	JKRAram::checkOkAddress(param_1, 0, param_2, 0);
	if (param_2 == nullptr) {
		return JKRAram::mainRamToAram(param_1, (ulong)0, param_3, param_4, param_5, param_6, param_7);
	} else {
		uVar1 = param_2->used;
		if ((param_4 == 1) && (uVar1 <= param_5)) {
			param_5 = uVar1;
		}
		if (uVar1 < param_3) {
			param_3 = uVar1;
		}
		return JKRAram::mainRamToAram(param_1, param_2->roundedupaddr, param_3, param_4, param_5, param_6, param_7);
	}
}

void *JKRAram::aramToMainRam(JKRAramBlock *param_1, uchar *dest, ulong param_3, ulong size, JKRExpandSwitch switc,
							 ulong param_6, JKRHeap *heap, int param_8, ulong *neededlength) {
	uint uVar1;
	void *pvVar2;

	if (neededlength != nullptr) {
		*neededlength = 0;
	}
	JKRAram::checkOkAddress(dest, 0, param_1, size);
	if (param_1 == nullptr) {
		m_Do_printf::OSPanic("JKRAram.cpp", 0x2ab, ":::Bad Aram Block specified.\n");
	}
	uVar1 = param_1->used;
	if (size < uVar1) {
		if (param_3 == 0) {
			param_3 = uVar1;
		}
		if (uVar1 < size + param_3) {
			param_3 = uVar1 - size;
		}
		pvVar2 = JKRAram::aramToMainRam(size + param_1->roundedupaddr, dest, param_3, switc, param_6, heap, param_8, neededlength);
	} else {
		pvVar2 = nullptr;
	}
	return pvVar2;
}

void *JKRAram::aramToMainRam(ulong param_1, uchar *param_2, ulong length, JKRExpandSwitch shouldexpand,
							 ulong param_5, JKRHeap *heap, int param_7, ulong *neededlength)

{
	uchar *__ptr;
	uint unaff_r23;
	JKRDecomp__CompressionType JVar1;
	uchar auStack96[32];

	JVar1 = NotCompressed;
	if (neededlength != nullptr) {
		*neededlength = 0;
	}
	JKRAram::checkOkAddress(param_2, param_1, nullptr, 0);
	if (shouldexpand == 1) {
		JKRAramPiece::orderSync(1, param_1, (ulong)auStack96, 0x20, nullptr);
		JVar1 = JKRDecomp::checkCompressed(auStack96);
		unaff_r23 = (uint)auStack96[7] |
					(uint)auStack96[6] << 8 | (uint)auStack96[4] << 0x18 | (uint)auStack96[5] << 0x10;
	}
	if (JVar1 == Yaz0Compressed) {
		if ((param_5 != 0) && (param_5 < unaff_r23)) {
			unaff_r23 = param_5;
		}
		if (param_2 == nullptr) {
			param_2 = (uchar *)JKRHeap::alloc(unaff_r23, 0x20, heap);
		}
		if (param_2 == nullptr) {
			param_2 = nullptr;
		} else {
			JKRAram::changeGroupIdIfNeed(param_2, param_7);
			// TODO: the game has multiple overloads of the decompSZS routine,
			// two of which have the same signature (meaning they're static in two different TUs),
			//  the only difference between the two is a branch. but they also call other static
			// functions with the same definitions that may be copy pasted with slight variation
			//JKernel::JKRDecompressFromAramToMainRam(param_1, param_2, length, unaff_r23, 0);
			if (neededlength != nullptr) {
				*neededlength = unaff_r23;	// should probably go before the call
			}
		}
	} else if (JVar1 == Yay0Compressed) {
		__ptr = (uchar *)JKRHeap::alloc(length, -0x20, heap);
		if (__ptr == nullptr) {
			param_2 = nullptr;
		} else {
			JKRAramPiece::orderSync(1, param_1, (ulong)__ptr, length, nullptr);
			if ((param_5 != 0) && (param_5 < unaff_r23)) {
				unaff_r23 = param_5;
			}
			if (param_2 == nullptr) {
				param_2 = (uchar *)JKRHeap::alloc(unaff_r23, 0x20, heap);
			}
			if (param_2 == nullptr) {
				JKRHeap::free(__ptr, nullptr);
				param_2 = nullptr;
			} else {
				JKRAram::changeGroupIdIfNeed(param_2, param_7);
				JKRDecomp::orderSync(__ptr, param_2, unaff_r23, 0);
				JKRHeap::free(__ptr, heap);
				if (neededlength != nullptr) {
					*neededlength = unaff_r23;
				}
			}
		}
	} else {
		if (param_2 == nullptr) {
			param_2 = (uchar *)JKRHeap::alloc(length, 0x20, heap);
		}
		if (param_2 == nullptr) {
			param_2 = nullptr;
		} else {
			JKRAram::changeGroupIdIfNeed(param_2, param_7);
			JKRAramPiece::orderSync(1, param_1, (ulong)param_2, length, nullptr);
			if (neededlength != nullptr) {
				*neededlength = length;
			}
		}
	}
	return param_2;
}