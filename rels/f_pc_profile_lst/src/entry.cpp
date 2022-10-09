#include <c_dylink.h>
#include <common/d_com_lib_game.h>
#include <f_op/scene.h>
#include <f_pc/node.h>
#include <f_pc/profile.h>
#include <machine/dolphin/printf.h>

namespace d_s_logo {
	struct dScnLogo_c : scene_class {
		static profile_method_class methods;
		request_of_phase_process_class phaseproc;
		dDlst_2D_c *dlistlink[7];
		byte drawstep, wantsprogressive, isprogressive;
		ushort transitiontimer, newtimer, prevtimer, isoddframe, framesleft;
		void *systemblock;
	};

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
		} else if ((mDoAud_zelAudio_c::mInitFlag == '\0') ||
				   (iVar1 = JAIZelBasic::checkFirstWaves(JAIZelBasic::zel_basic), iVar1 == 0)) {
			iVar1 = dRes_control_c::setRes("System", d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40,
										   "/res/Object/", 0, (JKRHeap *)0x0);
			if (iVar1 != 1) {
				JUTAssertion::getSDevice()->showAssert("d_s_logo.cpp", 0x546, "rt == 1");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x546, "Halt");
			}
			iVar1 = dRes_control_c::setRes("Logo", d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40,
										   "/res/Object/", 2, (JKRHeap *)0x0);
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

		iVar1 = dRes_control_c::syncAllRes(d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
		if (iVar1 == 0) {
			dDlst_list_c::mToonImage = (ResTIMG *)dRes_control_c::getRes("System", 3, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
			if (dDlst_list_c::mToonImage == (ResTIMG *)0x0) {
				JUTAssertion::getSDevice()->showAssert("d_s_logo.cpp", 0x592, "toonImage != 0");
				m_Do_printf::OSPanic("d_s_logo.cpp", 0x592, "Halt");
			}
			dDlst_list_c::mToonExImage = (ResTIMG *)dRes_control_c::getRes("System", 4, d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo, 0x40);
			if (dDlst_list_c::mToonExImage == (ResTIMG *)0x0) {
				JUTAssertion::getSDevice()->showAssert("d_s_logo.cpp", 0x597, "toonImage != 0");
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

	int dScnLogo_Create(dScnLogo_c *param_1) {
		static StepFunction<dScnLogo_c> *l_method[] = {
			phase_0,
			phase_1,
			phase_2,
		};
		// checkProgSelect(param_1);
		return d_com_lib_game::dComLbG_PhaseHandler(&param_1->phaseproc, &l_method, param_1);
	}

	f_pc_profile__Profile_Scene g_profile_LOGO_SCENE = MAKE_SCENE(5, dScnLogo_c, 0, 0, 0);
	profile_method_class dScnLogo_c::methods = MAKE_PROFILE_METHODS(dScnLogo);
};

namespace f_pc_profile_lst {
	f_pc_profile__Profile_Base *g_fpcPfLst_ProfileList[] = {
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		&d_s_logo::g_profile_LOGO_SCENE,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
	};
}

extern "C" {
int prolog() {
	f_pc_profile::g_fpcPf_ProfileList_p = f_pc_profile_lst::g_fpcPfLst_ProfileList;
}
}