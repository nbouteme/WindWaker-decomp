#pragma once

#include <dolphin/dvd.h>
#include <dolphin/os.h>
#include <doltypes.h>
#include <machine/dolphin/printf.h>

#include "../JKernel/JKRDisposer.h"
#include "../JUtility/JUTAssert.h"

struct JSUIosBase {
	virtual ~JSUIosBase() {}
};

struct JSUInputStream : public JSUIosBase {
	virtual uint readData(void *b, uint s) = 0;

	byte status;

	uint read(void *b, uint s) {
		auto r = readData(b, s);
		if (r != s)
			status |= 1;
		return r;
	}

	virtual int skip(uint param_1) {
		int iVar1;
		int iVar2;
		undefined auStack24[12];

		iVar2 = 0;
		while (true) {
			if (param_1 <= iVar2) {
				return iVar2;
			}
			iVar1 = readData(auStack24, 1);
			if (iVar1 != 1)
				break;
			iVar2 = iVar2 + 1;
		}
		this->status = this->status | 1;
		return iVar2;
	}

	virtual ~JSUInputStream() {}
};

struct JSURandomInputStream : public JSUInputStream {
	virtual ~JSURandomInputStream() {}
	virtual uint getAvailable() {
		return getPosition() - getLength();
	}

	virtual void skip(int n) {
		auto p = seekPos(n, 1);
		if (p != n)
			status |= 1;
	}

	virtual uint readData(void *b, uint n) = 0;
	virtual uint getLength() = 0;
	virtual uint getPosition() = 0;
	virtual uint seekPos(uint p, uint from) = 0;
};

struct JKRFile : public JKRDisposer {
	virtual ~JKRFile() {}

	byte mStatus;

	virtual int open(char *fn) = 0;
	virtual void close() = 0;
	virtual u32 readData(void *param_1, long param_2, long param_3) = 0;
	virtual u32 writeData(void *param_1, long param_2, long param_3) = 0;
	virtual u32 getFileSize() = 0;
};

struct JKRDvdFile : public JKRFile {
	os::OSMutex mutex1, mutex2;
	dvd::DVDFileInfo fileinfo;

	// might be an aliasing issue and this is actually a userptr from DVDFileInfo?
	// me from the future: self NEEDS to be right after fileinfo so that doneProcess can get a pointer to self
	// this is bad because it relies on alignment
	JKRDvdFile *self;
	os::OSMessageQueue queue2;
	os::OSMessage msg2;
	os::OSMessageQueue queue1;
	os::OSMessage msg1;
	JSUPtrLink mLink;
	JKRAramBlock *aramAreaPointer;
	JSUFileInputStream *fileinputstream;
	os::OSThread *currentThread, *executionThread;
	int s2;

	static JSUPtrList sDvdList;

	void initiate() {
		this->self = this;
		os::OSInitMutex(&this->mutex1);
		os::OSInitMutex(&this->mutex2);
		os::OSInitMessageQueue(&this->queue1, &this->msg1, 1);
		os::OSInitMessageQueue(&this->queue2, &this->msg2, 1);
		this->currentThread = nullptr;
		this->executionThread = nullptr;
		this->s2 = 0;
	}

	JKRDvdFile() : mLink(this) {
		initiate();
	}

	JKRDvdFile(char *param_1) : mLink(this) {
		this->mStatus = 0;
		initiate();
		this->mStatus = open(param_1);
	}

	JKRDvdFile(long param_1) : mLink(this) {
		initiate();
		this->mStatus = open(param_1);
	}

	virtual int open(char *fn) {
		bool bVar1;

		if (this->mStatus == 0) {
			bVar1 = dvd::DVDOpen(fn, &this->fileinfo);
			this->mStatus = 1 - !bVar1;
			if (this->mStatus != 0) {
				sDvdList.append(&this->mLink);
				dvd::DVDGetCommandBlockStatus(&this->fileinfo.cb);
			}
		}
		return this->mStatus;
	};

	virtual uint open(uint id) {
		int iVar1;

		if (this->mStatus == 0) {
			iVar1 = dvd::DVDFastOpen(id, &this->fileinfo);
			this->mStatus = 1 - (iVar1 == 0);
			if (this->mStatus != 0) {
				sDvdList.append(&this->mLink);
				dvd::DVDGetCommandBlockStatus(&this->fileinfo.cb);
			}
		}
		return (uint)this->mStatus;
	}

	virtual void close() {
		int iVar1;

		if (this->mStatus) {
			iVar1 = dvd::DVDClose(&this->fileinfo);
			if (iVar1 == 0) {
				m_Do_printf::OSPanic("JKRDvdFile.cpp", 0xd4, "cannot close DVD file\n");
			} else {
				this->mStatus = 0;
				sDvdList.remove(&this->mLink);
			}
		}
	};

	static void doneProcess(s32 res, dvd::DVDFileInfo *info) {
		auto self = (JKRDvdFile *)info[1].cb.next;	// why did they do this
		os::OSSendMessage(&self->queue1, (void *)res, 0);
	}

	uint sync() {
		uint local_18[5];

		os::OSLockMutex(&this->mutex1);
		os::OSReceiveMessage(&this->queue1, (void **)local_18, 1);
		this->currentThread = nullptr;
		os::OSUnlockMutex(&this->mutex1);
		return local_18[0];
	}

	virtual u32 readData(void *param_1, long param_2, long param_3) {
		ulong uVar1;
		uint pJVar2;
		os::OSThread *pOVar3;
		int iVar4;

		if ((param_2 & 0x1fU) != 0) {
			auto uVar1 = JUTAssertion::getSDevice();
			uVar1->showAssert("JKRDvdFile.cpp", 0xec, "( length & 0x1f ) == 0");
			m_Do_printf::OSPanic("JKRDvdFile.cpp", 0xec, "Halt");
		}
		os::OSLockMutex(&this->mutex1);
		if (!this->currentThread) {
			pOVar3 = os::OSGetCurrentThread();
			this->currentThread = pOVar3;
			pJVar2 = ~0ul;
			iVar4 = dvd::DVDReadAsyncPrio(&this->fileinfo, param_1, param_2, param_3, JKRDvdFile::doneProcess, 2);
			if (iVar4 != 0) {
				pJVar2 = sync();
			}
			this->currentThread = nullptr;
			os::OSUnlockMutex(&this->mutex1);
		} else {
			os::OSUnlockMutex(&this->mutex1);
			pJVar2 = ~0ul;
		}
		return pJVar2;
	}

	virtual u32 writeData(void *param_1, long length, long param_3) {
		if ((length & 0x1fU) != 0) {
			auto uVar1 = JUTAssertion::getSDevice();
			uVar1->showAssert("JKRDvdFile.cpp", 0x154, "( length & 0x1f ) == 0");
			m_Do_printf::OSPanic("JKRDvdFile.cpp", 0x154, "Halt");
		}
		return ~0;
	}

	virtual u32 getFileSize() {
		return this->fileinfo.length;
	}
};

struct JSUFileInputStream : public JSURandomInputStream {
	uint state0;
	JKRFile *filehandle;
	uint position;
	JSUFileInputStream(JKRFile *file) {
		filehandle = file;
		position = 0;
	}

	virtual uint getPosition() {
		return this->position;
	}

	uint JSUFileInputStream::getLength() {
		return this->filehandle->getFileSize();
	}

	uint seekPos(uint param_1, uint param_2) {
		int iVar1;
		undefined4 uVar2;
		int iVar3;

		iVar3 = this->position;
		if (param_2 == 1) {
			this->position = iVar3 + param_1;
		} else if ((int)param_2 < 1) {
			if (-1 < (int)param_2) {
				this->position = param_1;
			}
		} else if ((int)param_2 < 3) {
			iVar1 = this->filehandle->getFileSize();
			this->position = iVar1 - param_1;
		}
		if ((int)this->position < 0) {
			this->position = 0;
		}
		iVar1 = this->filehandle->getFileSize();
		if (iVar1 < (int)this->position) {
			uVar2 = this->filehandle->getFileSize();
			this->position = uVar2;
		}
		return this->position - iVar3;
	}

	virtual uint readData(void *param_1, uint len) override {
		JKRFile *pJVar1;
		uint uVar2;
		int iVar3;
		int iVar4;

		iVar4 = 0;
		pJVar1 = this->filehandle;
		if (pJVar1->mStatus) {
			uVar2 = pJVar1->getFileSize();
			if (uVar2 < (uint)(this->position + len)) {
				iVar3 = this->filehandle->getFileSize();
				len = iVar3 - this->position;
			}
			if (0 < len) {
				iVar4 = this->filehandle->readData(param_1, len, this->position);
				if (iVar4 < 0) {
					iVar4 = 0;
				} else {
					this->position = this->position + iVar4;
				}
			}
		}
		return iVar4;
	}
};