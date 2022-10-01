
#include "manager.h"

#include <dolphin/dvd.h>

#include <JFramework/J2DGraph/J2DOrthoGraph.h>
#include <JFramework/J3D/J3DSys.h>
#include <JFramework/JFWDisplay.h>
#include <machine/dolphin/graphic.h>
#include <machine/dolphin/rst.h>
#include <machine/dolphin/printf.h>

#include "creator.h"
#include "deletor.h"
#include "draw.h"
#include "executor.h"
#include "layer.h"
#include "line.h"
#include "pause.h"
#include "priority.h"

namespace f_pc_manager {
	layer_class rootlayer$4264;
	node_list_class queue$4265[10];

	int fpcM_IsPause(base_process_class *param_1, undefined1 param_2) {
		return f_pc_pause::fpcPause_IsEnable(param_1, param_2);
	}

	void fpcM_PauseEnable(process_node_class *param_1, byte param_2) {
		f_pc_pause::fpcPause_Enable(param_1, param_2);
	}

	void fpcM_PauseDisable(base_process_class *param_1, byte param_2) {
		f_pc_pause::fpcPause_Disable(param_1, param_2);
		return;
	}

	int fpcM_IsCreating(uint p) {
		return f_pc_creator::fpcCt_IsCreatingByID(p);
	}

	void fpcM_Draw(void *param_1) {
		f_pc_draw::fpcDw_Execute((base_process_class *)param_1);
	}

	void fpcM_Init() {
		f_pc_layer::fpcLy_Create(&rootlayer$4264, (void *)0x0, queue$4265, 10);
		f_pc_line::fpcLn_Create();
	}

	int *fpcM_DrawIterater(f_pc_draw::DrawFunc *param_1) {
		layer_class *plVar1;

		plVar1 = f_pc_layer::fpcLy_RootLayer();
		f_pc_layer_iter::fpcLyIt_OnlyHere(plVar1, (SComponent::Method *)param_1, 0);
		return nullptr;
	}

	int fpcM_Delete(base_process_class *param_1) {
		return f_pc_deletor::fpcDt_Delete(param_1);
	}

	using code = void *(void);

	byte init$4231;
	byte l_dvdError$4230;

	void *fpcM_Execute(void *param_1) {
		return f_pc_executor::fpcEx_Execute((base_process_class *)param_1);
	}

	void messageSet(int idx) {
		// TODO: scream
	}

	void drawDvdCondition(long param_1) {
		undefined4 uVar1;
		JFWDisplay *pJVar2;
		ulong uVar3;
		u8 uStack246;
		u8 uStack245;
		u8 local_f4;
		u8 uStack243;
		TBox2<float> local_ec;

		JFWDisplay::sManager->mpFader = nullptr;
		pJVar2 = JFWDisplay::sManager;
		(JFWDisplay::sManager->clearColor) = mDoGph_gInf_c::mBackColor;
		/* beginender */
		JFWDisplay::sManager->beginRender();
		gx::GXSetAlphaUpdate(0);
		J3DGraphBase::j3dSys.drawInit();
		struct J2DOrthoGraph local_dc(0.0, 0.0, 640.0, 480.0, -1.0, 1.0);
		local_ec.mTL[0] = -9.0;
		local_ec.mTL[1] = -21.0;
		local_ec.mBR[0] = 650.0;
		local_ec.mBR[1] = 503.0;
		local_dc.setOrtho(&local_ec, -1.0, 1.0);
		local_dc.setPort();
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mp2DOrthoGraph = &local_dc;
		if (param_1 == 4) {
			messageSet(2);
		} else if (param_1 == 5) {
			messageSet(1);
		} else if (param_1 == 6) {
			messageSet(3);
		} else if (param_1 == 0xb) {
			messageSet(4);
		} else if (param_1 == 1) {
			messageSet(0);
		} else if (param_1 == -1) {
			messageSet(5);
			//JAInter::StreamLib::stop();
		} else {
			JUTAssertion::getSDevice()->setWarningMessage_f("f_pc_manager.cpp", 0x1e1, "Dvd Error !! <%d>\n", param_1);
		}
		/* endrender */
		JFWDisplay::sManager->endRender();
	}

	int checkDvdCondition(void) {
		int iVar1;

		if (init$4231 == 0) {
			l_dvdError$4230 = 0;
			init$4231 = 1;
		}
		iVar1 = dvd::DVDGetDriveStatus();
		if ((iVar1) && (iVar1 != 1)) {
			l_dvdError$4230 = 1;
		}
		if (l_dvdError$4230) {
			if (iVar1 == 0) {
				l_dvdError$4230 = 0;
			} else if (*mDoRst::mResetData == 0) {
				drawDvdCondition(iVar1);
			} else {
				*mDoRst::mResetData = 0;
				mDoRst::mResetData[1] = 0;
				m_Do_Reset::mDoRst_reset(1, 0x80000000, 0);
			}
		}
		return l_dvdError$4230;
	}

	void fpcM_Management(code *param_1, code *param_2) {
		int iVar1;
		ulong uVar2;

		SComponent::MtxInit();
		iVar1 = checkDvdCondition();
		if (iVar1 == 0) {
			SComponent::cAPIGph_Painter();
			f_pc_deletor::fpcDt_Handler();
			iVar1 = f_pc_priority::fpcPi_Handler();
			if (iVar1 == 0) {
				JUTAssertion::getSDevice()->showAssert("f_pc_manager.cpp", 0x224, "0");
				m_Do_printf::OSPanic("f_pc_manager.cpp", 0x224, "Halt");
			}
			iVar1 = f_pc_creator::fpcCt_Handler();
			if (iVar1 == 0) {
				JUTAssertion::getSDevice()->showAssert("f_pc_manager.cpp", 0x228, "0");
				m_Do_printf::OSPanic("f_pc_manager.cpp", 0x228, "Halt");
			}
			if (param_1) {
				(*param_1)();
			}
			f_pc_executor::fpcEx_Handler((SComponent::Method *)fpcM_Execute);
			f_pc_draw::fpcDw_Handler((f_pc_draw::DrawFunc *)fpcM_DrawIterater, (f_pc_draw::DrawArg *)fpcM_Draw);
			if (param_2) {
				(*param_2)();
			}
		}
		return;
	}

}