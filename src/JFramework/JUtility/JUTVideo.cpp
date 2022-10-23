#include "JUTVideo.h"
#define _GNU_SOURCE
#include <fenv.h>

JUTVideo *JUTVideo::sManager;
ulong JUTVideo::sVideoLastTick;
int JUTVideo::sVideoInterval;

JUTVideo *JUTVideo::createManager(gx::GXRenderModeObj *obj) {
	JUTVideo *ret;

	ret = JUTVideo::sManager;
	if (!JUTVideo::sManager) {
		ret = new JUTVideo(obj);
	}
	JUTVideo::sManager = ret;
	return JUTVideo::sManager;
}

void JUTVideo::destroyManager() {
	if (sManager)
		sManager->~JUTVideo();
}

void JUTVideo::setRenderMode(gx::GXRenderModeObj *param_1) {
	if ((this->mpRenderMode) &&
		(param_1->viTVmode != this->mpRenderMode->viTVmode)) {
		this->waitFinished = 1;
		this->flushesRemaining = 4;
	}
	this->mpRenderMode = param_1;
	// why are you complaining you st
	vi::VIConfigure((gx::GXRenderModeObj *)param_1);
	vi::VIFlush();
	if (this->waitFinished != 0) {
		vi::VIWaitForRetrace();
		vi::VIWaitForRetrace();
	}
}
void JUTVideo::drawDoneCallback() {
	short sVar1;
	JUTXfb *pJVar2;
	void *param_1;

	pJVar2 = JUTXfb::sManager;
	if (JUTXfb::sManager != (JUTXfb *)0x0) {
		param_1 = (undefined *)0x0;
		JUtility::sDrawWaiting = 0;
		if (JUTXfb::sManager->xfbnum == 1) {
			if (JUTXfb::sManager->renderStatus == 1) {
				JUTXfb::sManager->renderStatus = 0;
				sVar1 = pJVar2->idx1;
				if (-1 < sVar1) {
					param_1 = (&pJVar2->xfb0)[sVar1];
				}
				if ((undefined *)param_1 != (undefined *)0x0) {
					if (sVar1 < 0) {
						param_1 = (undefined *)0x0;
					} else {
						param_1 = (&pJVar2->xfb0)[sVar1];
					}
					vi::VISetNextFrameBuffer(param_1);
					vi::VIFlush();
				}
			}
		}
	}
}

void JUTVideo::preRetraceProc(u32 param_1) {
	JUTXfb *pJVar1;
	int iVar2;
	void *puVar3;

	if (JUTVideo::sManager->preRetraceCB) {
		(*JUTVideo::sManager->preRetraceCB)(param_1);
	}
	iVar2 = os::OSGetTick();
	pJVar1 = JUTXfb::sManager;
	JUTVideo::sVideoInterval = iVar2 - JUTVideo::sVideoLastTick;
	JUTVideo::sVideoLastTick = iVar2;
	if (JUTXfb::sManager == (JUTXfb *)0x0) {
		vi::VISetBlack(1);
		vi::VIFlush();
	} else {
		if (JUtility::init$2183 == '\0') {
			JUtility::frameBuffer$2182 = (undefined *)0x0;
			JUtility::init$2183 = '\x01';
		}
		if (JUtility::frameBuffer$2182 != (undefined *)0x0) {
			JUTDirectPrint::sDirectPrint->changeFrameBuffer(JUtility::frameBuffer$2182,
															JUTVideo::sManager->mpRenderMode->fbWidth,
															JUTVideo::sManager->mpRenderMode->efbHeight);
		}
		if (JUTVideo::sManager->waitFinished == 1) {
			iVar2 = JUTVideo::sManager->flushesRemaining;
			if (0 < iVar2) {
				iVar2 = iVar2 + -1;
			}
			JUTVideo::sManager->flushesRemaining = iVar2;
			JUTVideo::sManager->waitFinished = 1 - (iVar2 == 0);
			vi::VISetBlack(1);
			vi::VIFlush();
		} else if (pJVar1 == (JUTXfb *)0x0) {
			vi::VISetBlack(1);
			vi::VIFlush();
		} else {
			iVar2 = pJVar1->xfbnum;
			if ((iVar2 == 3) || (iVar2 == 2)) {
				if (JUtility::sDrawWaiting == '\0') {
					pJVar1->idx2 = pJVar1->idx1;
					if ((short)pJVar1->idx1 < 0) {
						vi::VISetBlack(1);
						vi::VIFlush();
					} else {
						vi::VISetBlack(0);
						if ((short)pJVar1->idx2 < 0) {
							puVar3 = (undefined *)0x0;
						} else {
							puVar3 = (&pJVar1->xfb0)[(short)pJVar1->idx2];
						}
						vi::VISetNextFrameBuffer(puVar3);
						vi::VIFlush();
						if ((short)pJVar1->idx2 < 0) {
							JUtility::frameBuffer$2182 = (undefined *)0x0;
						} else {
							JUtility::frameBuffer$2182 = (&pJVar1->xfb0)[(short)pJVar1->idx2];
						}
					}
				}
			} else if (iVar2 == 1) {
				if (pJVar1->renderStatus == 0) {
					if ((short)pJVar1->idx1 < 0) {
						vi::VISetBlack(1);
					} else {
						pJVar1->idx2 = pJVar1->idx1;
						if ((short)pJVar1->idx2 < 0) {
							puVar3 = (undefined *)0x0;
						} else {
							puVar3 = (&pJVar1->xfb0)[(short)pJVar1->idx2];
						}
						gx::GXCopyDisp(puVar3, 1);
						gx::GXFlush();
						pJVar1->renderStatus = 2;
						if ((short)pJVar1->idx2 < 0) {
							JUtility::frameBuffer$2182 = (undefined *)0x0;
						} else {
							JUtility::frameBuffer$2182 = (&pJVar1->xfb0)[(short)pJVar1->idx2];
						}
						vi::VISetBlack(0);
					}
				}
				vi::VIFlush();
			}
		}
	}
	return;
}

JUTVideo::JUTVideo(gx::GXRenderModeObj *param_1) {
	int iVar1;
	vi::VIRetraceCallback puVar2;

	this->mpRenderMode = nullptr;
	vi::VIInit();
	this->waitFinished = 1;	 // initialized *after* setRenderMode in vanilla
	setRenderMode(param_1);
	this->waitFinished = 1;
	this->flushesRemaining = 2;
	vi::VISetBlack(1);
	vi::VIFlush();
	//*(undefined4 *)&this->field_0x8 = 0;
	iVar1 = vi::VIGetRetraceCount();
	this->mRetraceCount = iVar1;
	//*(undefined4 *)&this->field_0x10 = 1;
	//*(undefined4 *)&this->field_0x18 = 0;
	JUTVideo::sVideoLastTick = os::OSGetTick();
	JUTVideo::sVideoInterval = 670000;
	puVar2 = vi::VISetPreRetraceCallback(JUTVideo::preRetraceProc);
	this->mpOldPreRetraceProc = puVar2;
	puVar2 = vi::VISetPostRetraceCallback(JUTVideo::postRetraceProc);
	this->mpOldPostRetraceProc = puVar2;
	this->preRetraceCB = nullptr;
	this->postRetraceCB = nullptr;
	os::OSInitMessageQueue(&this->mMesgQ, &this->mMesg, 1);
	gx::GXSetDrawDoneCallback(JUTVideo::drawDoneCallback);
}

void JUTVideo::drawDoneStart() {
	JUtility::sDrawWaiting = 1;
	gx::GXSetDrawDone();
}

void JUTVideo::postRetraceProc(u32 param_1) {
	undefined4 uVar1;

	if (JUTVideo::sManager->postRetraceCB) {
		JUTVideo::sManager->postRetraceCB();
	}
	uVar1 = vi::VIGetRetraceCount();
	os::OSSendMessage(&JUTVideo::sManager->mMesgQ, (void *)uVar1, 0);
}

void JUTVideo::dummyNoDrawWait() {
	JUtility::sDrawWaiting = 0;
}

void JUTVideo::waitRetraceIfNeed() {}

gx::GXRenderModeObj *JUTVideo::getRenderMode() {
	return this->mpRenderMode;
}

JUTVideo *JUTVideo::getManager() {
	return JUTVideo::sManager;
}

JUTVideo::~JUTVideo() {
	vi::VISetPreRetraceCallback(this->mpOldPreRetraceProc);
	vi::VISetPostRetraceCallback(this->mpOldPostRetraceProc);
}
