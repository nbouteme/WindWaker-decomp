#include "game.h"

#include <doltypes.h>
#include <f_op/camera.h>
#include <f_op/draw.h>
#include <f_op/overlap.h>
#include <f_op/scene.h>
#include <f_pc/manager.h>
#include <machine/dolphin/HIO.h>

namespace f_ap_game {
	fapGm_HIO_c g_HIO;

	void fapGm_After(void)	{
		f_op_scene_mng::fopScnM_Management();
		f_op_overlap_mng::fopOvlpM_Management();
		f_op_camera_mng::fopCamM_Management();
		return;
	}

	void fapGm_Create() {
		f_pc_manager::fpcM_Init();
		f_op_scene_mng::fopScnM_Init();
		f_op_overlap_mng::fopOvlpM_Init();
		f_op_camera_mng::fopCamM_Init();
		f_op_draw_tag::fopDwTg_CreateQueue();
		f_op_scene_mng::fopScnM_CreateReq(5, 0x7fff, 0, 0);
		g_HIO.HIOLoaded = m_Do_hostIO::mDoHIO_root.subroot.createChild("ゲームシステム", &g_HIO);
	}

	void fapGm_Execute() {
		f_pc_manager::fpcM_Management(0, (f_pc_manager::code*)f_ap_game::fapGm_After);
		SComponent::cCt_Counter(0);
	}
};