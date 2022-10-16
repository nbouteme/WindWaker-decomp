#pragma once

#include <JFramework/JKernel/JKRDvdRipper.h>
#include <JFramework/JKernel/JKRHeap.h>
#include <JFramework/JKernel/JKRMemArchive.h>
#include <JFramework/JKernel/JKRThread.h>
#include <SComponent.h>
#include <dolphin/os.h>

#include "./ext.h"

struct mDoDvdThd_command_c : public node_class {
	int mStatus;
	mDoDvdThd_command_c();
	virtual ~mDoDvdThd_command_c();
};

struct mDoDvdThd_callback_c : public mDoDvdThd_command_c {
	using CBType = void *(void *);
	CBType *callback;
	void *userptr;
	void *cbresult;
	static mDoDvdThd_callback_c *create(CBType *param_1, void *param_2);

	mDoDvdThd_callback_c(CBType *cb, void *up);
	virtual bool execute();
	virtual ~mDoDvdThd_callback_c();
};

struct mDoDvdThd_toMainRam_c : public mDoDvdThd_command_c {
	byte mDirection;
	int mDvdEntryNum;
	JKRArchive__Header *mpArchiveHeader;
	int mHeapSize;
	JKRHeap *mpHeap;

	mDoDvdThd_toMainRam_c(byte direction);
	bool execute();
	static mDoDvdThd_toMainRam_c *create(char *pFilePath, byte direction, JKRHeap *pHeap);
	virtual ~mDoDvdThd_toMainRam_c();
};

namespace m_Do_dvd_thread {
	undefined4 cb(mDoDvdThd_callback_c *param_1);
	int my_DVDConvertPathToEntrynum(char *pFilePath);
}

// Apparently uses multiple inheritance but no idea what the second is
struct mDoDvdThd_mountArchive_c : public mDoDvdThd_command_c {
	byte mDirection;
	int mEntryNum;
	JKRMemArchive *mpResult;
	JKRHeap *mpHeap;

	static mDoDvdThd_mountArchive_c *create(char *param_1, uchar param_2, JKRHeap *param_3);
	mDoDvdThd_mountArchive_c(int param_1);
	virtual bool execute() {
		JKRExpHeap *heap;
		JKRMemArchive *this_00;
		JKRExpHeap *pJVar1;

		heap = (JKRExpHeap *)this->mpHeap;
		if (heap == nullptr) {
			heap = m_Do_ext::mDoExt_getArchiveHeap();
		}
		while (true) {
			if (this->mDirection == 0) {
				this_00 = new (heap, 0) JKRMemArchive(this->mEntryNum, 1);
			} else {
				this_00 = new (heap, -4) JKRMemArchive(this->mEntryNum, 2);
			}
			if (this_00 && this_00->mbIsMounted)
				break;
			m_Do_printf::OSReport_Error("mDoDvdThd_mountArchive_c::execute マウント失敗\n");
			delete this_00;
			pJVar1 = m_Do_ext::mDoExt_getZeldaHeap();
			if (heap == pJVar1) {
				m_Do_printf::OSReport_FatalError("mDoDvdThd_mountArchive_c::execute ヒープが致命的に足りません！\n");
			LAB_80018740:
				this->mStatus = 1;
				return this->mpResult != nullptr;
			}
			m_Do_printf::OSReport_Error("mDoDvdThd_mountArchive_c::execute システムヒープで再チャレンジ！\n");
			heap = m_Do_ext::mDoExt_getZeldaHeap();
		}
		this->mpResult = this_00;
		goto LAB_80018740;
	}
	virtual ~mDoDvdThd_mountArchive_c();
};

struct mDoDvdThd_mountXArchive_c : public mDoDvdThd_command_c {
	byte mDirection;
	int state;
	JKRArchive *mpArchive;
	uint mMountMode;

	static mDoDvdThd_mountXArchive_c *create(uchar param_2, JKRHeap *param_3);

	mDoDvdThd_mountXArchive_c(uchar param_1, EMountMode param_2) {
		this->mDirection = param_1;
		this->state = -1;
		this->mpArchive = nullptr;
		this->mMountMode = param_2;
		if (param_1 == '\0') {
			this->mDirection = mDoDvdThd::sDefaultDirection;
		}
	}

	virtual bool execute() {
		JKRExpHeap *pJVar1;
		JKRArchive *pJVar2;
		EMountDirection EVar3;

		EVar3 = 2;
		if (this->mDirection == 0) {
			EVar3 = 1;
		}
		pJVar1 = m_Do_ext::mDoExt_getArchiveHeap();
		this->mpArchive = JKRArchive::mount(this->state, (EMountMode)this->mMountMode, pJVar1, EVar3);;
		pJVar2 = this->mpArchive;
		mStatus = 1;
		return this->mpArchive != nullptr;
	}

	static mDoDvdThd_mountXArchive_c *create(char *param_1, byte param_2, EMountMode param_3) {
		JKRExpHeap *heap;
		mDoDvdThd_mountXArchive_c *self;
		int iVar1;

		heap = m_Do_ext::mDoExt_getCommandHeap();
		self = new (heap, -4) mDoDvdThd_mountXArchive_c(param_2, param_3);
		if (self) {
			iVar1 = m_Do_dvd_thread::my_DVDConvertPathToEntrynum(param_1);
			self->state = iVar1;
			if (self->state == -1) {
				self->mStatus = 1;
				delete self;
				self = nullptr;
			} else {
				mDoDvdThd::l_param.addition(self);
			}
		}
		return self;
	}

	virtual ~mDoDvdThd_mountXArchive_c();
};

struct mDoDvdThd_param_c {
	os::OSMessageQueue queue;
	os::OSMessage msg;
	node_list_class mChildList;
	os::OSMutex mMutex;

	mDoDvdThd_param_c();

	void kick();
	int waitForKick();
	node_class *getFirstCommand();
	void addition(mDoDvdThd_command_c *param_1);
	void cut(mDoDvdThd_command_c *param_1);
	void mainLoop();
};

namespace mDoDvdThd {
	extern int sDefaultDirection;
	extern os::OSThread l_thread;
	extern byte SyncWidthSound;
	extern mDoDvdThd_param_c l_param;

	void *main(void *up);
	void create(int prio);
}

namespace m_Do_DVDError {
	extern byte mDoDvdErr_initialized;
	extern os::OSAlarm Alarm;
	extern os::OSThread DvdErr_thread;

	void *mDoDvdErr_Watch(void *);
	void AlarmHandler(os::OSAlarm *alarm, os::OSContext *context);
	void mDoDvdErr_ThdCleanup(void);
	void mDoDvdErr_ThdInit();
}