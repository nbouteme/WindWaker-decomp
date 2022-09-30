#include "JKRAram.h"

JKRAramStreamCommand::JKRAramStreamCommand() {
	fullfilled = 0;
}

JKRAramStream *JKRAramStream::sAramStreamObject;
void *JKRAramStream::transBuffer;
uint JKRAramStream::transSize;
JKRHeap *JKRAramStream::transHeap;

JKRAramStreamCommand *JKRAramStream::write_StreamToAram_Async(JSUFileInputStream *param_1, ulong param_2, ulong param_3, ulong param_4) {
	JKRAramStreamCommand *command = new (JKRHeap::sSystemHeap, -4) JKRAramStreamCommand();
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
	if (__buf == (void *)0x0) {
		size = 0x400;
		if (uVar1 != 0) {
			size = uVar1;
		}
		if (pHeap == (JKRHeap *)0x0) {
			__buf = (void *)JKRHeap::alloc(size, -0x20, (JKRHeap *)0x0);
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
	if (__buf == (void *)0x0) {
		if (pHeap == (JKRHeap *)0x0) {
			JKRHeap::sCurrentHeap->dump();
		} else {
			pHeap->dump();
		}
		m_Do_printf::OSReport(":::Cannot alloc memory [%s][%d]\n", "JKRAramStream.cpp", 0xa8);
		m_Do_printf::OSPanic("JKRAramStream.cpp", 0xa9, "abort\n");
	}
	if (__buf != (void *)0x0) {
		param_1->inputstream->seekPos(uVar3, 0);
		//JSURandomInputStream::seek(param_1->inputstream, uVar3, 0);
		for (; uVar5 != 0; uVar5 = uVar5 - uVar1) {
			uVar1 = uVar5;
			if (size < uVar5) {
				uVar1 = size;
			}
			// TODO: implement
			param_1->inputstream->read(__buf, uVar1);
			//sVar2 = JSUInputStream::read((JSUInputStream *)param_1->inputstream, __buf, uVar1);
			if (sVar2 == 0) {
				iVar4 = 0;
				break;
			}
			//JKRAramPiece::orderSync(0, (ulong)__buf, dest, uVar1, (JKRAramBlock *)0x0);
			iVar4 = iVar4 + uVar1;
			dest = dest + uVar1;
		}
		if (param_1->fullfilled != '\0') {
			JKRHeap::free(__buf, (JKRHeap *)0x0);
			param_1->fullfilled = 0;
		}
	}
	os::OSSendMessage(&param_1->mqueue, (void **)&iVar4, 0);
	return iVar4;
}

void *JKRAramStream::run(void *) {
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
		self = new (JKRHeap::sSystemHeap, 0) JKRAramStream(param_1);
		sAramStreamObject = self;
		JKRAramStream::setTransBuffer(nullptr, 0, nullptr);
	}
	return sAramStreamObject;
}

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
	uVar1 = ar::ARAlloc(this->audioAreaSize);
	this->audioArea = uVar1;
	uVar2 = ar::ARAlloc(this->graphAreaSize);
	this->graphArea = uVar2;
	if (this->userAreaSize == 0) {
		this->userArea = 0;
	} else {
		uVar1 = ar::ARAlloc(this->userAreaSize);
		this->userArea = uVar1;
	}
	m_Do_printf::OSReport("ARAM audio area %08x: %08x\n", this->audioArea, this->audioAreaSize);
	m_Do_printf::OSReport("ARAM graph area %08x: %08x\n", this->graphArea, this->graphAreaSize);
	m_Do_printf::OSReport("ARAM  user area %08x: %08x\n", this->userArea, this->userAreaSize);
	this->mpHeap = new (JKRHeap::sSystemHeap, 0) JKRAramHeap(this->graphArea, this->graphAreaSize);
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
		if ((param_3 == (JKRAramBlock *)0x0) || ((param_4 + param_3->roundedupaddr & 0x1f) == 0)) {
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
