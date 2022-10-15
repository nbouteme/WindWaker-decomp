#include "mDoAud.h"

#include <JFramework/JKernel/JKRArchive.h>
#include <JFramework/JKernel/JKRExpHeap.h>

#include "dvd.h"

int mDoAud_zelAudio_c::mInitFlag;

namespace m_Do_audio {
	JKRSolidHeap *g_mDoAud_audioHeap;

	mDoDvdThd_toMainRam_c *l_affCommand;
	mDoDvdThd_mountArchive_c *l_arcCommand;

	void *mDoAud_StreamBufferPointer;
	int mDoAud_StreamBufferBlocks;
	JKRHeap *mDoAud_audioStreamHeap;

	void mDoAud_allocStreamBuffer(void) {
		ulong size;
		ulong uVar2;
		char cVar3;

		if (mDoAud_StreamBufferPointer != (void *)0x0) {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "m_Do_audio.cpp", 0x62, "mDoAud_StreamBufferPointer == 0");
			m_Do_printf::OSPanic("m_Do_audio.cpp", 0x62, "Halt");
		}
		auto uVar1 = (ulong)mDoAud_StreamBufferBlocks;
		while (true) {
			JAIGlobalParameter::setParamStreamDecodedBufferBlocks(uVar1);
			size = JAInter::StreamLib::getNeedBufferSize();
			if (mDoAud_audioStreamHeap != (JKRExpHeap *)0x0) {
				auto uVar2 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar2, "m_Do_audio.cpp", 0x7c, "mDoAud_audioStreamHeap == 0");
				m_Do_printf::OSPanic("m_Do_audio.cpp", 0x7c, "Halt");
			}
			mDoAud_audioStreamHeap = m_Do_ext::archiveHeap;
			mDoAud_StreamBufferPointer =
				(void *)JKRHeap::alloc(size, 0, m_Do_ext::archiveHeap);
			if (mDoAud_StreamBufferPointer == (void *)0x0) {
				mDoAud_audioStreamHeap = m_Do_ext::gameHeap;
				mDoAud_StreamBufferPointer = JKRHeap::alloc(size, 0, m_Do_ext::gameHeap);
			}
			if (mDoAud_StreamBufferPointer == (void *)0x0) {
				mDoAud_audioStreamHeap = m_Do_ext::zeldaHeap;
				mDoAud_StreamBufferPointer =
					(void *)JKRHeap::alloc(size, 0, m_Do_ext::zeldaHeap);
			}
			if (mDoAud_StreamBufferPointer != (void *)0x0)
				break;
			if (uVar1 < 4) {
				if (true) {
					auto uVar1 = JUTAssertion::getSDevice();
					JUTAssertion::showAssert(uVar1, "m_Do_audio.cpp", 0x90, "mDoAud_StreamBufferPointer");
					m_Do_printf::OSPanic("m_Do_audio.cpp", 0x90, "Halt");
				}
				return;
			}
			uVar1 = uVar1 - 1;
		}
		cVar3 = g_mDoAud_zelAudio.allocStreamBuffer(mDoAud_StreamBufferPointer, size);
		if (cVar3 != '\0') {
			return;
		}
		auto uVar12 = JUTAssertion::getSDevice();
		JUTAssertion::showAssert(uVar12, "m_Do_audio.cpp", 0x94, "success");
		m_Do_printf::OSPanic("m_Do_audio.cpp", 0x94, "Halt");
	}

	void mDoAud_deallocStreamBuffer(void) {
		char cVar2;

		if (mDoAud_StreamBufferPointer == (void *)0x0) {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "m_Do_audio.cpp", 0xae, "mDoAud_StreamBufferPointer");
			m_Do_printf::OSPanic("m_Do_audio.cpp", 0xae, "Halt");
		}
		cVar2 = g_mDoAud_zelAudio.deallocStreamBuffer();
		if (cVar2 == '\0') {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "m_Do_audio.cpp", 0xb6, "success");
			m_Do_printf::OSPanic("m_Do_audio.cpp", 0xb6, "Halt");
		}
		JKRHeap::free(mDoAud_StreamBufferPointer, mDoAud_audioStreamHeap);
		mDoAud_StreamBufferPointer = (void *)0x0;
		mDoAud_audioStreamHeap = (JKRHeap *)0x0;
	}

	void mDoAud_setupStreamBuffer(void) {
		JAIGlobalParameter::setParamStreamInsideBufferCut(true);
		mDoAud_StreamBufferPointer = 0;
		mDoAud_StreamBufferBlocks = 0xc;
		mDoAud_audioStreamHeap = 0;
		JAInter::StreamLib::setAllocBufferCallback(mDoAud_allocStreamBuffer);
		JAInter::StreamLib::setDeallocBufferCallback(mDoAud_deallocStreamBuffer);
	}

	int mBgmSet;

	void reset(void) {
		mBgmSet = 0;
		return;
	}

	void mDoAud_Create(void) {
		ulong uVar1;
		JKRArchive *pJVar2;
		undefined8 uVar3;
		char archivename[104];

		if ((!l_affCommand) &&
			(l_affCommand = mDoDvdThd_toMainRam_c::create("/Audiores/JaiInit.aaf", 2, (JKRHeap *)0x0),
			 !l_affCommand)) {
			return;
		}
		if (!l_arcCommand) {
			JAInter::SequenceMgr::getArchiveName(archivename);
			l_arcCommand = mDoDvdThd_mountArchive_c::create(archivename, '\0', (JKRHeap *)0x0);
			if (!l_arcCommand) {
				return;
			}
		}

		if ((l_affCommand->mStatus) && (l_arcCommand->mStatus)) {
			JAIGlobalParameter::setParamInitDataPointer(l_affCommand->mpArchiveHeader);
			JAInter::SequenceMgr::setArchivePointer(l_arcCommand->mpResult);
			mDoAud_setupStreamBuffer();
			if (g_mDoAud_audioHeap == (JKRSolidHeap *)0x0) {
				m_Do_printf::OSReport_Error("ヒープ確保失敗につきオーディオ初期化できません\n");
			} else {
				((JKRHeap *)0x0)->becomeCurrentHeap();
				g_mDoAud_zelAudio.init(g_mDoAud_audioHeap, 0xa00000);
				m_Do_ext::zeldaHeap->becomeCurrentHeap();
				g_mDoAud_audioHeap->adjustSize();
			}
			g_mDoAud_zelAudio.setEventBit(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent.mBits);
			reset();
			uVar1 = os::OSGetSoundMode();
			JAIZelBasic::zel_basic->setOutputMode(uVar1);
			JKRHeap::free(l_affCommand->mpArchiveHeader, (JKRHeap *)0x0);
			delete l_affCommand;
			delete l_arcCommand;
			mDoAud_zelAudio_c::mInitFlag = 1;
			mDoDvdThd::SyncWidthSound = 1;
		}
	}

	void mDoAud_Execute(void) {
		if (mDoAud_zelAudio_c::mInitFlag == 0) {
			mDoAud_Create();
		} else {
			mDoAud_executeStreamBuffer();
			g_mDoAud_zelAudio.gframeProcess();
			mDoAud_zelAudio_c::calcLoadTimer();
		}
		return;
	}
}