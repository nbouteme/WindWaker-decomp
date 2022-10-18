#include "dvd.h"

#include <JFramework/JKernel/JKRDvdRipper.h>
#include <JFramework/JKernel/JKRHeap.h>
#include <JFramework/JKernel/JKRMemArchive.h>
#include <JFramework/JKernel/JKRThread.h>
#include <JFramework/JKernel/JKernel.h>
#include <dolphin/dvd.h>

#include <cstdio>

mDoDvdThd_command_c::mDoDvdThd_command_c() {
	mStatus = 0;
	SComponent::cNd_ForcedClear(this);
}

mDoDvdThd_command_c::~mDoDvdThd_command_c() {}

mDoDvdThd_callback_c::mDoDvdThd_callback_c(CBType *cb, void *up) : mDoDvdThd_command_c() {
	this->callback = cb;
	this->userptr = up;
	this->cbresult = nullptr;
}

mDoDvdThd_callback_c *mDoDvdThd_callback_c::create(CBType *param_1, void *param_2) {
	JKRHeap *heap;
	mDoDvdThd_callback_c *selft;

	heap = m_Do_ext::mDoExt_getCommandHeap();
	selft = new (heap, -4) mDoDvdThd_callback_c(param_1, param_2);
	mDoDvdThd::l_param.addition(selft);
	//printf("LPARAM AT %p\n", &mDoDvdThd::l_param);
	return selft;
}

bool mDoDvdThd_callback_c::execute() {
	this->cbresult = (node_class *)(*this->callback)(this->userptr);
	this->mStatus = 1;
	return this->cbresult != nullptr;
}

mDoDvdThd_callback_c::~mDoDvdThd_callback_c() {}

mDoDvdThd_toMainRam_c::mDoDvdThd_toMainRam_c(byte direction) : mDoDvdThd_command_c() {
	if (!direction)
		direction = mDoDvdThd::sDefaultDirection;
	mDirection = direction;
}

bool mDoDvdThd_toMainRam_c::execute() {
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

mDoDvdThd_toMainRam_c *mDoDvdThd_toMainRam_c::create(char *pFilePath, byte direction, JKRHeap *pHeap) {
	JKRHeap *heap;
	int entryNum;
	mDoDvdThd_toMainRam_c *dvdThd;

	heap = m_Do_ext::mDoExt_getCommandHeap();
	dvdThd = new (heap, -4) mDoDvdThd_toMainRam_c(direction);
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

mDoDvdThd_toMainRam_c::~mDoDvdThd_toMainRam_c() {}

namespace m_Do_dvd_thread {

	undefined4 cb(mDoDvdThd_command_c *param_1) {
		int iVar1;

		// iVar1 = (**(code **)((param_1->field0_0x0).parent.mpPrevNode[1].mpData + 0xc))();
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

mDoDvdThd_mountArchive_c *mDoDvdThd_mountArchive_c::create(char *param_1, uchar param_2, JKRHeap *param_3) {
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

mDoDvdThd_mountArchive_c::mDoDvdThd_mountArchive_c(int param_1) : mDoDvdThd_command_c() {
	this->mDirection = param_1;
	this->mEntryNum = -1;
	this->mpResult = nullptr;
	this->mpHeap = nullptr;
	if (!param_1) {
		this->mDirection = mDoDvdThd::sDefaultDirection;
	}
}

mDoDvdThd_mountArchive_c::~mDoDvdThd_mountArchive_c() {
}

namespace mDoDvdThd {
	int sDefaultDirection;
	os::OSThread l_thread;
	byte SyncWidthSound;

	mDoDvdThd_param_c l_param;
#ifdef DOLPHIN
	byte dvdstack[0x1000];
#else
	// need more space on pc
	byte dvdstack[0x40000];
#endif

	void *main(void *up) {
		os::OSThread *pOVar1;

		pOVar1 = os::OSGetCurrentThread();
		{
			JKRThread JStack120(pOVar1, 0);
		}
		printf("DVDStack: %p-%p\n", dvdstack, dvdstack + sizeof(dvdstack));
		//((JKRHeap *)0x0)->becomeCurrentHeap();
		((mDoDvdThd_param_c *)up)->mainLoop();
		return 0;
	}

	void create(int prio) {
		// danger? this works in the game only because dvd error's BSS is right after l_param, which in turn uses
		// the memcard thread stack space, which in turn eats into the "memcard work area"
		os::OSCreateThread(&l_thread, main, (void *)&l_param, (void *)dvdstack + sizeof(dvdstack), sizeof(dvdstack), prio, 1);
		os::OSResumeThread(&l_thread);
	}
}

mDoDvdThd_param_c::mDoDvdThd_param_c() {
	os::OSInitMessageQueue(&queue, &msg, 1);
	os::OSInitMutex(&this->mMutex);
	SComponent::cLs_Create(&this->mChildList);
}

void mDoDvdThd_param_c::kick() {
	os::OSSendMessage(&queue, 0, 0);
}

int mDoDvdThd_param_c::waitForKick() {
	return os::OSReceiveMessage(&queue, 0, 1);
}

node_class *mDoDvdThd_param_c::getFirstCommand() {
	//printf("mDoDvdThd_param_c: %p\n", this);
	return mChildList.mpHead;
}

int i = 0;

void mDoDvdThd_param_c::addition(mDoDvdThd_command_c *param_1) {
	os::OSLockMutex(&this->mMutex);
	SComponent::cLs_Addition(&this->mChildList, param_1);
	os::OSUnlockMutex(&this->mMutex);
	kick();
}

void mDoDvdThd_param_c::cut(mDoDvdThd_command_c *param_1) {
	os::OSLockMutex(&this->mMutex);
	SComponent::cLs_SingleCut(param_1);
	os::OSUnlockMutex(&this->mMutex);
	kick();
}

void mDoDvdThd_param_c::mainLoop() {
	int iVar1;
	mDoDvdThd_command_c *local_18[4];

	while (iVar1 = waitForKick(), iVar1 != 0) {
		while (true) {
			local_18[0] = (mDoDvdThd_command_c *)getFirstCommand();
			if (!local_18[0])
				break;
			cut(local_18[0]);
			if (mDoDvdThd::SyncWidthSound == 0) {
				m_Do_dvd_thread::cb(local_18[0]);
			} else {
				puts("SOUND SYNC FAIL");
				m_Do_dvd_thread::cb(local_18[0]);

				// JASystem::Dvd::sendCmdMsg(m_Do_dvd_thread::cb, local_18, 4);
			}
		}
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

	byte errstack[0x1000];

	void mDoDvdErr_ThdInit() {
		using namespace os;

		os::OSThread *pOVar1;
		int iVar2;

		if (mDoDvdErr_initialized == 0) {
			pOVar1 = os::OSGetCurrentThread();
			iVar2 = os::OSGetThreadPriority(pOVar1);
			os::OSCreateThread(&DvdErr_thread, mDoDvdErr_Watch, 0,
							   errstack + 0x1000, 0x1000, iVar2 + -3, 1);
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

bool mDoDvdThd_mountArchive_c::execute() {
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

mDoDvdThd_mountXArchive_c::mDoDvdThd_mountXArchive_c(uchar param_1, EMountMode param_2) {
	this->mDirection = param_1;
	this->state = -1;
	this->mpArchive = nullptr;
	this->mMountMode = param_2;
	if (param_1 == '\0') {
		this->mDirection = mDoDvdThd::sDefaultDirection;
	}
}

bool mDoDvdThd_mountXArchive_c::execute() {
	JKRExpHeap *pJVar1;
	JKRArchive *pJVar2;
	EMountDirection EVar3;

	EVar3 = 2;
	if (this->mDirection == 0) {
		EVar3 = 1;
	}
	pJVar1 = m_Do_ext::mDoExt_getArchiveHeap();
	this->mpArchive = JKRArchive::mount(this->state, (EMountMode)this->mMountMode, pJVar1, EVar3);
	;
	pJVar2 = this->mpArchive;
	mStatus = 1;
	return this->mpArchive != nullptr;
}

mDoDvdThd_mountXArchive_c *mDoDvdThd_mountXArchive_c::create(char *param_1, byte param_2, EMountMode param_3) {
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

mDoDvdThd_mountXArchive_c::~mDoDvdThd_mountXArchive_c() {}
