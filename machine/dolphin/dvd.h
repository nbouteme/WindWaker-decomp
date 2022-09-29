#pragma once

#include <dolphin/os.h>
#include <SComponent.h>
#include <JFramework/JKernel/JKRHeap.h>
#include <JFramework/JKernel/JKRThread.h>
#include <JFramework/JKernel/JKRDvdRipper.h>
#include <JFramework/JKernel/JKRMemArchive.h>

#include "./ext.h"

struct mDoDvdThd_command_c : public node_class {
	int mStatus;
	mDoDvdThd_command_c() {
		mStatus = 0;
		SComponent::cNd_ForcedClear(this);
	}

	virtual ~mDoDvdThd_command_c() {}
};

struct mDoDvdThd_callback_c : public mDoDvdThd_command_c {
	using CBType = void *(void *);
	CBType *callback;
	void *userptr;
	void *cbresult;

	mDoDvdThd_callback_c(CBType *cb, void *up) : mDoDvdThd_command_c() {
		this->callback = cb;
		this->userptr = up;
		this->cbresult = nullptr;
	}

	static mDoDvdThd_callback_c *create(CBType *param_1, void *param_2) {
		JKRHeap *heap;
		mDoDvdThd_callback_c *selft;

		heap = m_Do_ext::mDoExt_getCommandHeap();
		selft = new (heap, -4) mDoDvdThd_callback_c(param_1, param_2);
		mDoDvdThd::l_param.addition(selft);
		return selft;
	}

	virtual bool execute() {
		this->cbresult = (node_class *)(*this->callback)(this->userptr);
		this->mStatus = 1;
		return this->cbresult != nullptr;
	}

	virtual ~mDoDvdThd_callback_c() {}
};

struct mDoDvdThd_toMainRam_c : public mDoDvdThd_command_c {
	byte mDirection;
	int mDvdEntryNum;
	JKRArchive__Header *mpArchiveHeader;
	int mHeapSize;
	JKRHeap *mpHeap;

	mDoDvdThd_toMainRam_c(byte direction) : mDoDvdThd_command_c() {
		if (!direction)
			direction = mDoDvdThd::sDefaultDirection;
		mDirection = direction;
	}

	bool execute() {
		JKRArchive__Header *pJVar1;
		int heapSize;
		JKRHeap *heap;
		int EVar2;	// EAllocDirection

		heap = this->mpHeap;
		if (!heap) {
			heap = m_Do_ext::mDoExt_getArchiveHeap();
		}
		EVar2 = 2;
		if (this->mDirection == 0) {
			EVar2 = 1;
		}
		pJVar1 = JKRDvdRipper::loadToMainRAM(this->mDvdEntryNum, (uchar *)0x0, 1, 0, heap, EVar2, 0, (int *)0x0);
		this->mpArchiveHeader = pJVar1;
		if (this->mpArchiveHeader) {
			heapSize = heap->getSize(this->mpArchiveHeader);
			this->mHeapSize = heapSize;
		}
		mStatus = 1;
		return this->mpArchiveHeader != nullptr;
	}

	static mDoDvdThd_toMainRam_c *create(char *pFilePath, byte direction, JKRHeap *pHeap) {
		JKRHeap *heap;
		int entryNum;
		mDoDvdThd_toMainRam_c *dvdThd;

		heap = m_Do_ext::mDoExt_getCommandHeap();
		dvdThd = new (heap, 0xfffffffc) mDoDvdThd_toMainRam_c(direction);
		if (dvdThd) {
			entryNum = m_Do_dvd_thread::my_DVDConvertPathToEntrynum(pFilePath);
			dvdThd->mDvdEntryNum = entryNum;
			if (dvdThd->mDvdEntryNum == -1) {
				dvdThd->mStatus = 1;
				if (dvdThd) {
					dvdThd->~mDoDvdThd_toMainRam_c();
					// free?
				}
				dvdThd = nullptr;
			} else {
				dvdThd->mpHeap = pHeap;
				mDoDvdThd::l_param.addition(dvdThd);
			}
		}
		return dvdThd;
	}

	virtual ~mDoDvdThd_toMainRam_c() {}
};

namespace m_Do_dvd_thread {

	undefined4 cb(mDoDvdThd_callback_c *param_1) {
		int iVar1;

		//iVar1 = (**(code **)((param_1->field0_0x0).parent.mpPrevNode[1].mpData + 0xc))();
		iVar1 = param_1->execute();
		if (iVar1 != 1) {
			m_Do_printf::OSReport_Error("mDoDvdThd_param_c::mainLoop() コマンドの実行が失敗しました。\n");
		}
		return 0;
	}

	int my_DVDConvertPathToEntrynum(char *pFilePath) {
		int entryNum;
		ulong uVar1;

		entryNum = dvd::DVDConvertPathToEntrynum(pFilePath);
		if (entryNum < 0) {
			auto uVar1 = JUTAssertion::getSDevice();
			uVar1->setWarningMessage_f("m_Do_dvd_thread.cpp", 0x240, "can\'t open:[%s]\n", pFilePath);
		}
		return entryNum;
	}
}

struct mDoDvdThd_mountArchive_c : public mDoDvdThd_command_c {
	node_list_class mChildList;
	os::OSMutex mMutex;

	int mDirection;
	int mEntryNum;
	JKRMemArchive *mpResult;
	JKRHeap *mpHeap;

	static mDoDvdThd_mountArchive_c *create(char *param_1, uchar param_2, JKRHeap *param_3) {
		JKRHeap *heap;
		int iVar1;
		mDoDvdThd_mountArchive_c *pCmd;

		heap = m_Do_ext::mDoExt_getCommandHeap();
		pCmd = new (heap, -4) mDoDvdThd_mountArchive_c(param_2);
		if (pCmd != (mDoDvdThd_mountArchive_c *)0x0) {
			iVar1 = m_Do_dvd_thread::my_DVDConvertPathToEntrynum(param_1);
			pCmd->mEntryNum = iVar1;
			if (pCmd->mEntryNum == -1) {
				pCmd->mStatus = 1;
				pCmd->~mDoDvdThd_mountArchive_c();	// need to add explicit deallocation here
			} else {
				pCmd->mpHeap = param_3;
				mDoDvdThd::l_param.addition(pCmd);
			}
		}
		return pCmd;
	}

	mDoDvdThd_mountArchive_c(int param_1) : mDoDvdThd_command_c() {
		this->mDirection = param_1;
		this->mEntryNum = -1;
		this->mpResult = nullptr;
		this->mpHeap = nullptr;
		if (!param_1) {
			this->mDirection = mDoDvdThd::sDefaultDirection;
		}
	}

	virtual ~mDoDvdThd_mountArchive_c() {
	}
};

struct mDoDvdThd_param_c {
	os::OSMessageQueue queue;
	os::OSMessage msg;
	node_list_class mChildList;
	os::OSMutex mMutex;

	mDoDvdThd_param_c() {
		os::OSInitMessageQueue(&queue, &msg, 1);
		os::OSInitMutex(&this->mMutex);
		SComponent::cLs_Create(&this->mChildList);
	}

	void kick() {
		os::OSSendMessage(&queue, 0, 0);
	}

	int waitForKick() {
		return os::OSReceiveMessage(&queue, 0, 1);
	}

	node_class *getFirstCommand() {
		return mChildList.mpHead;
	}

	void addition(mDoDvdThd_command_c *param_1) {
		os::OSLockMutex(&this->mMutex);
		SComponent::cLs_Addition(&this->mChildList, param_1);
		os::OSUnlockMutex(&this->mMutex);
		kick();
	}

	void cut(mDoDvdThd_command_c *param_1) {
		os::OSLockMutex(&this->mMutex);
		SComponent::cLs_SingleCut(param_1);
		os::OSUnlockMutex(&this->mMutex);
		kick();
	}

	void mainLoop() {
		int iVar1;
		mDoDvdThd_command_c *local_18[4];

		while (iVar1 = waitForKick(), iVar1 != 0) {
			while (true) {
				local_18[0] = (mDoDvdThd_command_c *)getFirstCommand();
				if (!local_18[0])
					break;
				cut(local_18[0]);
				if (mDoDvdThd::SyncWidthSound == 0) {
					m_Do_dvd_thread::cb((mDoDvdThd_callback_c *)local_18[0]);
				} else {
					//JASystem::Dvd::sendCmdMsg(m_Do_dvd_thread::cb, local_18, 4);
				}
			}
		}
	}
};

namespace mDoDvdThd {
	int sDefaultDirection;
	os::OSThread l_thread;
	byte SyncWidthSound;

	mDoDvdThd_param_c l_param;

	void *main(void *up) {
		return up;
	}

	void create(int prio) {
		// danger? this works in the game only because dvd error's BSS is right after l_param, which in turn uses
		// the memcard thread stack space, which in turn eats into the "memcard work area"
		os::OSCreateThread(&l_thread, main, (void *)&l_param, (void *)&l_param, 0x1000, prio, 1);
		os::OSResumeThread(&l_thread);
	}
}

namespace m_Do_DVDError {
	byte mDoDvdErr_initialized;
	os::OSAlarm Alarm;
	os::OSThread DvdErr_thread;

	void *mDoDvdErr_Watch(void *) {
		using namespace os;
		OSThread *pOVar1;
		int iVar2;
		JKRThread JStack120(os::OSGetCurrentThread(), 0);  // why

		((JKRHeap *)0x0)->becomeCurrentHeap();	// WHY
		do {
			iVar2 = dvd::DVDGetDriveStatus();
			if (iVar2 == -1) {
				os::OSSuspendThread(&mDoDvdThd::l_thread);
			}
			os::OSSuspendThread(&DvdErr_thread);
		} while (true);
	}

	void AlarmHandler(os::OSAlarm *alarm, os::OSContext *context) {
		os::OSResumeThread(&DvdErr_thread);
	}

	void mDoDvdErr_ThdCleanup(void) {
		if (mDoDvdErr_initialized) {
			os::OSCancelThread(&DvdErr_thread);
			os::OSCancelAlarm(&Alarm);
			mDoDvdErr_initialized = 0;
		}
	}

	void mDoDvdErr_ThdInit() {
		using namespace os;

		os::OSThread *pOVar1;
		int iVar2;

		if (mDoDvdErr_initialized == 0) {
			pOVar1 = os::OSGetCurrentThread();
			iVar2 = os::OSGetThreadPriority(pOVar1);
			os::OSCreateThread(&DvdErr_thread, mDoDvdErr_Watch, 0,
							   &Alarm, 0x1000, iVar2 + -3, 1);
			os::OSResumeThread((os::OSThread *)&DvdErr_thread);
			os::OSCreateAlarm(&Alarm);

			// might need a special convention
			//			os::OSSetPeriodicAlarm(&Alarm, 0x80020000, (int)(os::OSGetTime() >> 0x20), (int)os::OSGetTime(), 0,
			//								   162000000 >> 2, AlarmHandler);

			os::OSSetPeriodicAlarm(&Alarm, os::OSGetTime(), 162000000 >> 2, AlarmHandler);
			mDoDvdErr_initialized = '\x01';
		}
	}
}