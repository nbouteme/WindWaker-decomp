#pragma once

struct mDoAud_zelAudio_c {
	static int mInitFlag;
};

namespace m_Do_audio {
	JKRSolidHeap *g_mDoAud_audioHeap;

	mDoDvdThd_command_c *l_affCommand;
	mDoDvdThd_mountArchive_c *l_arcCommand;

	void mDoAud_Create(void) {
		ulong uVar1;
		undefined4 in_r4;
		JKRArchive *pJVar2;
		undefined8 uVar3;
		char aSStack104[104];

		// if (l_affCommand == nullptr) {
		// 	l_affCommand = mDoDvdThd_toMainRam_c::create("/Audiores/JaiInit.aaf", 2, nullptr);
		// 	if (l_affCommand == nullptr) {
		// 		return;
		// 	}
		// }

		// if (l_arcCommand == (mDoDvdThd_mountArchive_c *)0x0) {
		// 	//JAInter::SequenceMgr::getArchiveName(aSStack104);
		// 	l_arcCommand =
		// 		mDoDvdThd_mountArchive_c::create((char *)aSStack104, '\0', nullptr);
		// 	if (l_arcCommand == (mDoDvdThd_mountArchive_c *)0x0) {
		// 		return;
		// 	}
		// }
		// if (l_affCommand->mStatus && l_arcCommand->mStatus) {
		// 	pJVar2 = l_affCommand;
		// 	JAIGlobalParameter::setParamInitDataPointer((l_affCommand->parent).mVolumeLink.mpList);
		// 	JAInter::SequenceMgr::setArchivePointer((SequenceMgr *)l_arcCommand->mpResult, pJVar2);
		// 	m_Do_audio::mDoAud_setupStreamBuffer();
		// 	if (!m_Do_audio::g_mDoAud_audioHeap) {
		// 		m_Do_printf::OSReport_Error("ヒープ確保失敗につきオーディオ初期化できません\n");
		// 	} else {
		// 		JKRHeap::becomeCurrentHeap(nullptr);
		// 		JAIZelBasic::init((JAIZelBasic *)&m_Do_audio::g_mDoAud_zelAudio, m_Do_audio::g_mDoAud_audioHeap, 0xa00000);
		// 		JKRHeap::becomeCurrentHeap(m_Do_ext::zeldaHeap);
		// 		JKRSolidHeap::adjustSize(m_Do_audio::g_mDoAud_audioHeap);
		// 	}
		// 	JAIZelBasic::setEventBit((JAIZelBasic *)&m_Do_audio::g_mDoAud_zelAudio,
		// 							 &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent);
		// 	mDoAud_zelAudio_c::reset((mDoAud_zelAudio_c *)&m_Do_audio::g_mDoAud_zelAudio);
		// 	uVar1 = os::OSGetSoundMode();
		// 	JAIZelBasic::setOutputMode(JAIZelBasic::zel_basic, uVar1);
		// 	JKRHeap::free(l_affCommand->mVolumeLink.mpList, nullptr);
		// 	if (l_affCommand != nullptr) {
		// 		(*(code *)((l_affCommand->parent).parent.mHeapLink.mpPrev)->mpPrev)(l_affCommand, 1);
		// 	}
		// 	if (l_arcCommand != (mDoDvdThd_mountArchive_c *)0x0) {
		// 		(**(code **)(*(int *)&l_arcCommand->field_0x10 + 8))(l_arcCommand, 1);
		// 	}
		// 	mDoAud_zelAudio_c::mInitFlag = 1;
		// 	mDoDvdThd::SyncWidthSound = 1;
		// }
	}

	void mDoAud_Execute(void) {
		mDoAud_zelAudio_c *self;

		if (mDoAud_zelAudio_c::mInitFlag == 0) {
			m_Do_audio::mDoAud_Create();
		} else {
			// m_Do_audio::mDoAud_executeStreamBuffer();
			// self = (mDoAud_zelAudio_c *)
				// JAIZelBasic::gframeProcess((JAIZelBasic *)&m_Do_audio::g_mDoAud_zelAudio);
			// mDoAud_zelAudio_c::calcLoadTimer(self);
		}
		return;
	}
}