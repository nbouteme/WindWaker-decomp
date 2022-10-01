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

struct mDoDvdThd_mountArchive_c : public mDoDvdThd_command_c {
	node_list_class mChildList;
	os::OSMutex mMutex;

	int mDirection;
	int mEntryNum;
	JKRMemArchive *mpResult;
	JKRHeap *mpHeap;

	static mDoDvdThd_mountArchive_c *create(char *param_1, uchar param_2, JKRHeap *param_3);
	mDoDvdThd_mountArchive_c(int param_1);
	virtual ~mDoDvdThd_mountArchive_c();
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