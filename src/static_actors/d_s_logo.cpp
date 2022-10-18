#include "d_s_logo.h"

#include <JFramework/JFWDisplay.h>
#include <JFramework/JKernel/JKRAramHeap.h>
#include <JFramework/JUtility/JUTFader.h>
#include <JFramework/JUtility/JUTGamePad.h>
#include <c_dylink.h>
#include <common/dComIfG_inf_c.h>
#include <common/d_com_lib_game.h>
#include <f_op/scene.h>
#include <f_pc/node.h>
#include <f_pc/profile.h>
#include <machine/dolphin/dvd.h>
#include <machine/dolphin/mDoAud.h>
#include <machine/dolphin/printf.h>
#include <machine/dolphin/rst.h>

namespace d_s_logo {

	mDoDvdThd_mountXArchive_c *l_lodCommand;
	mDoDvdThd_mountXArchive_c *l_anmCommand;
	mDoDvdThd_mountXArchive_c *l_fmapCommand;
	mDoDvdThd_mountXArchive_c *l_itemResCommand;
	mDoDvdThd_mountXArchive_c *l_fmapResCommand;
	mDoDvdThd_mountXArchive_c *l_dmapResCommand;
	mDoDvdThd_mountXArchive_c *l_clctResCommand;
	mDoDvdThd_mountXArchive_c *l_optResCommand;
	mDoDvdThd_mountXArchive_c *l_clothResCommand;
	mDoDvdThd_mountXArchive_c *l_itemiconCommand;
	mDoDvdThd_mountXArchive_c *l_actioniconCommand;
	mDoDvdThd_mountXArchive_c *l_scopeResCommand;
	mDoDvdThd_mountXArchive_c *l_camResCommand;
	mDoDvdThd_mountXArchive_c *l_swimResCommand;
	mDoDvdThd_mountXArchive_c *l_windResCommand;
	mDoDvdThd_mountXArchive_c *l_nameResCommand;
	mDoDvdThd_mountXArchive_c *l_tmsgCommand;
	mDoDvdThd_mountXArchive_c *l_dmsgCommand;
	mDoDvdThd_mountXArchive_c *l_errorResCommand;
	mDoDvdThd_mountXArchive_c *l_saveResCommand;
	mDoDvdThd_mountXArchive_c *l_msgDtCommand;
	mDoDvdThd_mountXArchive_c *l_msgDtCommand2;
	mDoDvdThd_mountXArchive_c *l_msgCommand;
	mDoDvdThd_mountXArchive_c *l_menuCommand;
	mDoDvdThd_mountXArchive_c *l_fontCommand;
	mDoDvdThd_mountXArchive_c *l_rubyCommand;

	mDoDvdThd_toMainRam_c *l_particleCommand;
	mDoDvdThd_toMainRam_c *l_itemTableCommand;
	mDoDvdThd_toMainRam_c *l_ActorDataCommand;
	mDoDvdThd_toMainRam_c *l_FmapDataCommand;

	mDoDvdThd_mountXArchive_c *aramMount(char *param_1) {
		return mDoDvdThd_mountXArchive_c::create(param_1, 0, Aram);
	}

	mDoDvdThd_mountXArchive_c *onMemMount(char *param_1) {
		return mDoDvdThd_mountXArchive_c::create(param_1, 0, Mem);
	}

	int phase_0(dScnLogo_c *param_1) {
		int iVar1;
		undefined4 uVar2;
		ulong uVar3;

		iVar1 = os::OSGetResetCode();
		if (iVar1 == 0) {
			// iVar1 = vi::VIGetDTVStatus();
			if (iVar1 == 0) {
				os::OSSetProgressiveMode(0);
			}
		} else {
			iVar1 = os::OSGetProgressiveMode();
			if (iVar1 == 1) {
				// mDoMch_render_c::mRenderModeObj = &m_Do_machine::g_ntscZeldaProg;
			}
		}
		iVar1 = c_dylink::cDyl_InitAsyncIsDone();
		if (iVar1 == 0) {
			uVar2 = 0;
		} else if ((mDoAud_zelAudio_c::mInitFlag == 0) ||
				   (iVar1 = JAIZelBasic::zel_basic->checkFirstWaves(), iVar1 == 0)) {
			// Load the System and Logo archives into mObjectInfo
			iVar1 = dRes_control_c::setRes("System", d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40, "/res/Object/", 0, nullptr);
			if (iVar1 != 1) {
				JUTAssertion::getSDevice()->showAssert("d_s_logo.cpp", 0x546, "rt == 1");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x546, "Halt");
			}
			iVar1 = dRes_control_c::setRes("Logo", d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40,
										   "/res/Object/", 2, nullptr);
			if (iVar1 != 1) {
				JUTAssertion::getSDevice()->showAssert("d_s_logo.cpp", 0x54a, "rt == 1");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x54a, "Halt");
			}
			param_1->isprogressive = 0;
			m_Do_ext::archiveHeap->dump_sort();
			uVar2 = 2;
		} else {
			uVar2 = 0;
		}
		return uVar2;
	}

	int phase_1(dScnLogo_c *param_1) {
		int iVar1;
		undefined4 uVar2;
		ResTIMG *pRVar3;
		ulong uVar4;
		JKRExpHeap *heap;
		void *pvVar5;

		// Ensure the previously requested archives are loaded
		iVar1 = dRes_control_c::syncAllRes(d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
		if (iVar1 == 0) {
			// resources are referred to by ID
			// 3 -> toon.bti
			dDlst_list_c::mToonImage = (ResTIMG *)dRes_control_c::getRes("System", 3, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
			if (dDlst_list_c::mToonImage == nullptr) {
				JUTAssertion::getSDevice()->showAssert("d_s_logo.cpp", 0x592, "toonImage");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x592, "Halt");
			}
			// 4 -> toonex.bti
			dDlst_list_c::mToonExImage = (ResTIMG *)dRes_control_c::getRes("System", 4, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
			if (dDlst_list_c::mToonExImage == nullptr) {
				JUTAssertion::getSDevice()->showAssert("d_s_logo.cpp", 0x597, "toonImage");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x597, "Halt");
			}
			heap = m_Do_ext::mDoExt_getGameHeap();
			param_1->systemblock = heap->alloc(0x3c8a0, 4);
			uVar2 = 2;
		} else {
			uVar2 = 0;
		}
		return uVar2;
	}

	int phase_2(dScnLogo_c *param_1) {
		JFWDisplay *pJVar1;
		int iVar2;
		ulong uVar3;
		undefined4 uVar4;
		ResTIMG *pRVar5;
		dDlst_2D_c *pdVar6;
		JUTFader *pJVar7;

		iVar2 = dRes_control_c::syncRes("Logo", d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
		if (iVar2 < 0) {
			auto uVar3 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x5bd, "rt >= 0");
			m_Do_printf::OSPanic("d_s_logo.cpp", 0x5bd, "Halt");
		}
		if (iVar2 == 0) {
			d_com_inf_game::g_dComIfG_gameInfo.mPlay.createParticle();
			pRVar5 = (ResTIMG *)dRes_control_c::getRes("Logo", 3, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
			if (pRVar5 == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x5ca, "timg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x5ca, "Halt");
			}
			pdVar6 = new dDlst_2D_c(pRVar5, 0x85, 0xaa, '\0');
			param_1->dlistlink[0] = pdVar6;
			if (param_1->dlistlink[0] == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x5cd, "i_this->nintendoImg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x5cd, "Halt");
			}
			param_1->dlistlink[0]->alpha = 0xff;
			pdVar6 = param_1->dlistlink[0];
			(pdVar6->picture).mColorBase.r = 0xdc;
			(pdVar6->picture).mColorBase.g = 0;
			(pdVar6->picture).mColorBase.b = 0;
			(pdVar6->picture).mColorBase.a = 0xff;
			pRVar5 = (ResTIMG *)
				dRes_control_c::getRes("Logo", 9, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
			if (pRVar5 == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x5da, "timg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x5da, "Halt");
			}
			pdVar6 = new dDlst_2D_c(pRVar5, 0xda, 0xa6, '\0');

			param_1->dlistlink[1] = pdVar6;
			if (param_1->dlistlink[1] == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x5de, "i_this->dolbyImg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x5de, "Halt");
			}
			param_1->dlistlink[1]->alpha = 0xff;
			pRVar5 = (ResTIMG *)
				dRes_control_c::getRes("Logo", 4, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
			if (pRVar5 == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x61d, "timg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x61d, "Halt");
			}
			pdVar6 = new dDlst_2D_c(pRVar5, 0x71, 0x119, '\0');
			param_1->dlistlink[2] = pdVar6;
			if (param_1->dlistlink[2] == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x61f, "i_this->progchoiceImg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x61f, "Halt");
			}
			param_1->dlistlink[2]->alpha = '\0';
			pRVar5 = (ResTIMG *)
				dRes_control_c::getRes("Logo", 8, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
			if (pRVar5 == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x62b, "timg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x62b, "Halt");
			}
			pdVar6 = new dDlst_2D_c(pRVar5, 0xd3, 0x174, '\0');
			param_1->dlistlink[3] = pdVar6;
			if (param_1->dlistlink[3] == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x62d, "i_this->progyesImg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x62d, "Halt");
			}
			pdVar6 = param_1->dlistlink[3];
			(pdVar6->picture).mColorBase.r = 0xff;
			(pdVar6->picture).mColorBase.g = 200;
			(pdVar6->picture).mColorBase.b = 0;
			(pdVar6->picture).mColorBase.a = 0xff;
			param_1->dlistlink[3]->alpha = '\0';
			pRVar5 = (ResTIMG *)
				dRes_control_c::getRes("Logo", 6, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
			if (pRVar5 == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x63a, "timg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x63a, "Halt");
			}
			pdVar6 = new dDlst_2D_c(pRVar5, 0x15e, 0x174, '\0');
			param_1->dlistlink[4] = pdVar6;
			if (param_1->dlistlink[4] == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x63c, "i_this->prognoImg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x63c, "Halt");
			}
			pdVar6 = param_1->dlistlink[4];
			(pdVar6->picture).mColorBase.r = 0xa0;
			(pdVar6->picture).mColorBase.g = 0xa0;
			(pdVar6->picture).mColorBase.b = 0xa0;
			(pdVar6->picture).mColorBase.a = 0xff;
			param_1->dlistlink[4]->alpha = '\0';
			pRVar5 = (ResTIMG *)
				dRes_control_c::getRes("Logo", 7, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
			if (pRVar5 == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x649, "timg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x649, "Halt");
			}
			pdVar6 = new dDlst_2D_c(pRVar5, 0x99, 0x135, '\0');
			param_1->dlistlink[5] = pdVar6;
			if (param_1->dlistlink[5] == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x64b, "i_this->progImg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x64b, "Halt");
			}
			param_1->dlistlink[5]->alpha = '\0';
			pRVar5 = (ResTIMG *)
				dRes_control_c::getRes("Logo", 5, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
			if (pRVar5 == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x657, "timg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x657, "Halt");
			}
			pdVar6 = new dDlst_2D_c(pRVar5, 0x99, 0x135, '\0');
			param_1->dlistlink[6] = pdVar6;
			if (param_1->dlistlink[6] == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x659, "i_this->interImg");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x659, "Halt");
			}
			param_1->dlistlink[6]->alpha = '\0';
			JKRHeap::free(param_1->systemblock, nullptr);
			l_lodCommand = aramMount("/res/Stage/sea/LODALL.arc");
			if (l_lodCommand == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x66d, "l_lodCommand");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x66d, "Halt");
			}
			iVar2 = dRes_control_c::setRes("Always", d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40,
										   "/res/Object/", 0, nullptr);
			if (iVar2 != 1) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x672, "rt == 1");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x672, "Halt");
			}
			m_Do_ext::archiveHeap->dump_sort();
			iVar2 = dRes_control_c::setRes("Link", d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40,
										   "/res/Object/", 0, nullptr);
			if (iVar2 != 1) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x677, "rt == 1");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x677, "Halt");
			}
			iVar2 = dRes_control_c::setRes("Agb", d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40,
										   "/res/Object/", 0, nullptr);
			if (iVar2 != 1) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x67b, "rt == 1");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x67b, "Halt");
			}
			l_anmCommand = aramMount("/res/Object/LkAnm.arc");
			l_fmapCommand = aramMount("/res/Fmap/Fmap.arc");
			l_itemResCommand = aramMount("/res/Msg/itemres.arc");
			l_fmapResCommand = aramMount("/res/Msg/fmapres.arc");
			l_dmapResCommand = aramMount("/res/Msg/dmapres.arc");
			l_clctResCommand = aramMount("/res/Msg/clctres.arc");
			l_optResCommand = aramMount("/res/Msg/optres.arc");
			l_clothResCommand = aramMount("/res/Msg/clothres.arc");
			l_itemiconCommand = aramMount("/res/Msg/itemicon.arc");
			l_actioniconCommand = aramMount("/res/Msg/acticon.arc");
			l_scopeResCommand = aramMount("/res/Msg/scoperes.arc");
			l_camResCommand = aramMount("/res/Msg/camres.arc");
			l_swimResCommand = onMemMount("/res/Msg/swimres.arc");
			l_windResCommand = aramMount("/res/Msg/windres.arc");
			l_nameResCommand = aramMount("/res/Msg/nameres.arc");
			l_tmsgCommand = aramMount("/res/Msg/tmsgres.arc");
			l_dmsgCommand = aramMount("/res/Msg/dmsgres.arc");
			l_errorResCommand = aramMount("/res/Msg/errorres.arc");
			l_saveResCommand = aramMount("/res/Msg/saveres.arc");
			l_msgDtCommand = onMemMount("/res/Msg/bmgres.arc");
			l_msgDtCommand2 = onMemMount("/res/Msg/bmgresh.arc");
			l_msgCommand = aramMount("/res/Msg/msgres.arc");
			l_menuCommand = onMemMount("/res/Msg/menures.arc");
			l_fontCommand = onMemMount("/res/Msg/fontres.arc");
			l_rubyCommand = onMemMount("/res/Msg/rubyres.arc");
			l_particleCommand = mDoDvdThd_toMainRam_c::create("/res/Particle/common.jpc", 0, (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl)->mpHeap);
			l_itemTableCommand = mDoDvdThd_toMainRam_c::create("/res/ItemTable/item_table.bin", 0, nullptr);
			if (l_itemTableCommand == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x6cf, "l_itemTableCommand");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x6cf, "Halt");
			}
			l_ActorDataCommand = mDoDvdThd_toMainRam_c::create("/res/ActorDat/ActorDat.bin", 0, nullptr);
			if (l_ActorDataCommand == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x6d3, "l_ActorDataCommand");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x6d3, "Halt");
			}
			l_FmapDataCommand = mDoDvdThd_toMainRam_c::create("/res/FmapDat/FmapDat.bin", 0, nullptr);
			if (l_FmapDataCommand == nullptr) {
				auto uVar3 = JUTAssertion::getSDevice();
				JUTAssertion::showAssert(uVar3, "d_s_logo.cpp", 0x6d7, "l_FmapDataCommand");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x6d7, "Halt");
			}
			JAIZelBasic::zel_basic->loadStaticWaves();
			pJVar1 = JFWDisplay::sManager;
			JFWDisplay::sManager->targetFrameRateReached = (os::OS_BUS_CLOCK >> 2) / 60;
			pJVar1->currentFrameRate = 0;
			JFWDisplay::sManager->waitBlanking(0);
			pJVar7 = JFWDisplay::sManager->mpFader;
			if (pJVar7) {
				pJVar7->startFadeIn(0x1e);
			}
			param_1->transitiontimer = 0x5a;
			*mDoRst::mResetData = 0;
			mDoRst::mResetData[1] = 0;
			mDoRst::mResetData[1] = 0;
			JUTGamePad::C3ButtonReset::sResetOccurred = 0;
			JUTGamePad::C3ButtonReset::sCallback = m_Do_Reset::mDoRst_resetCallBack;
			JUTGamePad::C3ButtonReset::sCallbackArg = 0;
			uVar4 = 4;
		} else {
			uVar4 = 0;
		}
		return uVar4;
	}

	int dScnLogo_Create(dScnLogo_c *param_1) {
		static StepFunction<dScnLogo_c> *l_method[] = {
			phase_0,
			phase_1,
			phase_2,
		};
		// checkProgSelect(param_1);
		return d_com_lib_game::dComLbG_PhaseHandler(&param_1->phaseproc, (StepFunction<void> **)l_method, param_1);
	}

	int dScnLogo_Delete(dScnLogo_c *param_1) {
		dDlst_2D_c *pdVar1;
		void *ball128b;
		undefined4 uVar2;
		uint uVar3;
		int iVar4;
		int iVar5;

		if (*mDoRst::mResetData) {
			m_Do_Reset::mDoRst_reset(0, 0x80000000, 0);
		}
		delete param_1->dlistlink[0];
		delete param_1->dlistlink[1];
		delete param_1->dlistlink[2];
		delete param_1->dlistlink[3];
		delete param_1->dlistlink[4];
		delete param_1->dlistlink[5];
		delete param_1->dlistlink[6];

		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl->createCommon(d_s_logo::l_particleCommand->mpArchiveHeader);
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpAnmArchive = d_s_logo::l_anmCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapArchive = d_s_logo::l_fmapCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemResArchive = d_s_logo::l_itemResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapResArchive = d_s_logo::l_fmapResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDMapResArchive = d_s_logo::l_dmapResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClctResArchive = d_s_logo::l_clctResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpOptResArchive = d_s_logo::l_optResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSaveResArchive = d_s_logo::l_saveResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClothResArchive = d_s_logo::l_clothResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive = d_s_logo::l_itemiconCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpActionIconArchive = d_s_logo::l_actioniconCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpScopeResArchive = d_s_logo::l_scopeResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCamResArchive = d_s_logo::l_camResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSwimResArchive = d_s_logo::l_swimResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpWindResArchive = d_s_logo::l_windResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpNameResArchive = d_s_logo::l_nameResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTmsgArchive = d_s_logo::l_tmsgCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDmsgArchive = d_s_logo::l_dmsgCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpErrorResArchive = d_s_logo::l_errorResCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpEnglishTextArchive = d_s_logo::l_msgDtCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpHyruleTextArchive = d_s_logo::l_msgDtCommand2->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive = d_s_logo::l_msgCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMenuArchive = d_s_logo::l_menuCommand->mpArchive;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFontArchive = d_s_logo::l_fontCommand->mpArchive;

		delete l_anmCommand;
		delete l_fmapCommand;
		delete l_itemResCommand;
		delete l_fmapResCommand;
		delete l_dmapResCommand;
		delete l_clctResCommand;
		delete l_optResCommand;
		delete l_saveResCommand;
		delete l_clothResCommand;
		delete l_itemiconCommand;
		delete l_actioniconCommand;
		delete l_scopeResCommand;
		delete l_camResCommand;
		delete l_swimResCommand;
		delete l_windResCommand;
		delete l_nameResCommand;
		delete l_tmsgCommand;
		delete l_dmsgCommand;
		delete l_errorResCommand;
		delete l_msgDtCommand;
		delete l_msgDtCommand2;
		delete l_msgCommand;
		delete l_menuCommand;
		delete l_fontCommand;
		delete l_rubyCommand;
		delete l_particleCommand;

		m_Do_ext::mDoExt_getMesgFont();
		// m_Do_ext::mDoExt_getRubyFont();
		// d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemTableArchive = d_s_logo::l_itemTableCommand->mpArchiveHeader;
		delete l_itemTableCommand;

		// dADM::SetData(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM, d_s_logo::l_ActorDataCommand->mpArchiveHeader);
		// d_com_inf_game::g_dComIfG_gameInfo.mpFmapDataArchive = (FmapData *)d_s_logo::l_FmapDataCommand->mpArchiveHeader;

		delete l_ActorDataCommand;
		delete l_FmapDataCommand;
		delete l_lodCommand;

		ball128b = dRes_control_c::getRes("Always", 0x71, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
		// dDlst_shadowControl_c::setSimpleTex(ball128b);
		dRes_control_c::deleteRes("Logo", d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
		iVar4 = 0;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.field69_0x4841 = 0;
		uVar3 = 0;
		do {
			auto uVar2 = JKRAram::sAramObject->mpHeap->alloc(0x2000, 0);
			d_com_inf_game::g_dComIfG_gameInfo.mPlay.bigAramRegion[uVar3] = uVar2;
			d_com_inf_game::g_dComIfG_gameInfo.mPlay.pictureStatus = d_com_inf_game::g_dComIfG_gameInfo.mPlay.pictureStatus & ~(byte)(1 << (uVar3 & 0xff));
			uVar3 = uVar3 + 1;
		} while ((int)uVar3 < 3);
		iVar4 = 0;
		iVar5 = 0;
		do {
			auto uVar2 = JKRAram::sAramObject->mpHeap->alloc(0x70, 0);
			d_com_inf_game::g_dComIfG_gameInfo.mPlay.smallAramRegion[iVar4] = uVar2;
			iVar4 = iVar4 + 1;
		} while (iVar4 < 4);
		m_Do_ext::mDoExt_setSafeGameHeapSize();
		m_Do_ext::mDoExt_setSafeZeldaHeapSize();
		m_Do_ext::mDoExt_setSafeCommandHeapSize();
		m_Do_ext::mDoExt_setSafeArchiveHeapSize();
		return 1;
	}

	int dScnLogo_Execute(dScnLogo_c *param_1) {
		if (*mDoRst::mResetData) {
			f_op_scene_mng::fopScnM_ChangeReq(param_1, 5, 0, 5);
		}
		return 1;
	}

	int dScnLogo_IsDelete(dScnLogo_c *param_1) {
		return 1;
	}

	int nintendoInDraw(dScnLogo_c *param_1) {
		JUTFader *pJVar1;

		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
			param_1->dlistlink[0]);

		if (param_1->transitiontimer == 0) {
			if (param_1->isprogressive == '\0') {
				param_1->drawstep = 1;
				param_1->transitiontimer = 0x1e;
				pJVar1 = JFWDisplay::sManager->mpFader;
				if (pJVar1) {
					pJVar1->startFadeOut(0x1e);
				}
			} else {
				param_1->drawstep = 5;
				param_1->transitiontimer = 0x1e;
			}
		}
		return 1;
	}

	int nintendoOutDraw(dScnLogo_c *param_1) {
		JUTFader *pJVar1;

		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
			param_1->dlistlink[0]);
		if (param_1->wantsprogressive == '\0') {
			d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
				&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
				&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
				param_1->dlistlink[5]);
		} else {
			d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
				&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
				&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
				param_1->dlistlink[6]);
		}
		if (param_1->transitiontimer == 0) {
			param_1->drawstep = 3;	// skips 2
			param_1->transitiontimer = 0x5a;
			pJVar1 = JFWDisplay::sManager->mpFader;
			if (pJVar1) {
				pJVar1->startFadeIn(0x5a);
			}
		}
		return 1;
	}

	int nintendoOut2Draw(dScnLogo_c *param_1) {
		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
			(dDlst_base_c *)param_1->dlistlink[0]);
		if (param_1->wantsprogressive == '\0') {
			d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
				&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
				&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
				(dDlst_base_c *)param_1->dlistlink[5]);
		} else {
			d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
				&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
				&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
				param_1->dlistlink[6]);
		}
		if (param_1->transitiontimer == 0) {
			param_1->drawstep = 9;
			param_1->transitiontimer = 300;
		}
		return 1;
	}

	int dolbyInDraw(dScnLogo_c *param_1) {
		JUTFader *pJVar1;
		dDlst_base_c ***pppdVar2;

		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
			param_1->dlistlink[1]);

		if (param_1->transitiontimer == 0) {
			param_1->drawstep = 4;
			param_1->transitiontimer = 0x1e;
			pJVar1 = JFWDisplay::sManager->mpFader;
			if (pJVar1) {
				pJVar1->startFadeOut(0x1e);
			}
		}

		return 1;
	}

	int dolbyOutDraw(dScnLogo_c *param_1) {
		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
			(dDlst_base_c *)param_1->dlistlink[1]);
		if (param_1->transitiontimer == 0) {
			param_1->drawstep = 10;
		}
		return 1;
	}

	int progInDraw(dScnLogo_c *param_1) {
		uchar uVar1;

		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
			param_1->dlistlink[0]);
		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
			param_1->dlistlink[2]);
		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
			param_1->dlistlink[3]);
		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.set(
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
			&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
			param_1->dlistlink[4]);
		uVar1 = (uchar)(int)((1.0 - param_1->transitiontimer / 30.0) * 255.0);
		param_1->dlistlink[2]->alpha = uVar1;
		param_1->dlistlink[3]->alpha = uVar1;
		param_1->dlistlink[4]->alpha = uVar1;
		if (param_1->transitiontimer == 0) {
			param_1->drawstep = 6;
			param_1->transitiontimer = 600;
			param_1->newtimer = 0x1e;
			param_1->prevtimer = param_1->newtimer;
			param_1->isoddframe = 0;
			param_1->confirmedMode = 0;
		}
		return 1;
	}

	int dvdWaitDraw(dScnLogo_c *param_1) {
		int iVar1;

		iVar1 = dRes_control_c::syncAllRes(d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);

		if (iVar1 == 0 &&
			l_anmCommand->mStatus && l_fmapCommand->mStatus &&
			l_itemResCommand->mStatus && l_fmapResCommand->mStatus &&
			l_dmapResCommand->mStatus && l_clctResCommand->mStatus &&
			l_optResCommand->mStatus && l_saveResCommand->mStatus &&
			l_clothResCommand->mStatus && l_itemiconCommand->mStatus &&
			l_actioniconCommand->mStatus && l_scopeResCommand->mStatus &&
			l_camResCommand->mStatus && l_swimResCommand->mStatus &&
			l_windResCommand->mStatus && l_nameResCommand->mStatus &&
			l_tmsgCommand->mStatus && l_dmsgCommand->mStatus &&
			l_errorResCommand->mStatus && l_msgDtCommand->mStatus &&
			l_msgDtCommand2->mStatus && l_msgCommand->mStatus &&
			l_menuCommand->mStatus && l_fontCommand->mStatus &&
			l_rubyCommand->mStatus && l_particleCommand->mStatus &&
			l_itemTableCommand->mStatus && l_ActorDataCommand->mStatus &&
			l_FmapDataCommand->mStatus && l_lodCommand->mStatus &&
			(*mDoRst::mResetData == 0)) {
			d_com_inf_game::dComIfG_changeOpeningScene(param_1, 8);
		}
		return 1;
	}

	int dScnLogo_Draw(dScnLogo_c *param_1) {
		using CBFunc = int(dScnLogo_c *);
		CBFunc *l_execFunc[] = {
			nintendoInDraw,
			nintendoOutDraw,
			nintendoOut2Draw,
			dolbyInDraw,
			dolbyOutDraw,
			progInDraw,
			nullptr,  // progSelDraw, //
			nullptr,  // progOutDraw,
			nullptr,  // progSetDraw,
			nullptr,  // progChangeDraw,
			dvdWaitDraw,
		};

		// there are 99 copies of this function in the game
		// d_a_npc_fa1::cLib_calcTimer(&param_1->transitiontimer);
		if (param_1->transitiontimer)  // inlines the above
			param_1->transitiontimer--;
		return l_execFunc[param_1->drawstep](param_1);
	}

	f_pc_profile__Profile_Scene g_profile_LOGO_SCENE = MAKE_SCENE(5, dScnLogo_c, 0, 0, 0);
	profile_leaf_method_class dScnLogo_c::methods = MAKE_PROFILE_METHODS(dScnLogo);
};