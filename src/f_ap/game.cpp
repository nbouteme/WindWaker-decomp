#include "game.h"

#include <doltypes.h>
#include <f_op/camera.h>
#include <f_op/draw.h>
#include <f_op/overlap.h>
#include <f_op/scene.h>
#include <f_pc/manager.h>
#include <machine/dolphin/HIO.h>
#include <machine/dolphin/main.h>
#include <fenv.h>

#include <cstdio>

fapGm_HIO_c::fapGm_HIO_c() {
	//   *(undefined4 *)&this->field_0x20 = 0xffffffff;
	//   *(undefined4 *)&this->field_0x3c = 0xffffffff;
	//   *(undefined4 *)&this->field_0x40 = 0xffffffff;
	//   *(undefined4 *)&this->field_0x44 = 0xffffffff;
	//   *(undefined4 *)&this->field_0x48 = 0xffffffff;
	//   this->field_0x5 = 1;
	if (mDoMain::developmentMode == '\0') {
		this->forceprocessbar = 0;
		this->debugdisp = 0;
	} else {
		this->forceprocessbar = 1;
		this->debugdisp = 1;
	}
	//   this->field_0x9 = 1;
	//   this->field_0xa = 1;
	//   this->field9_0xc = 0.96;
	//   this->field_0x10 = 0;
	//   this->field_0x11 = 0;
	//   this->field_0x12 = 8;
	//   this->field_0x13 = 8;
	//   this->field_0x14 = 10;
	//   this->field_0x15 = 0xc;
	//   this->field_0x16 = 10;
	//   this->field_0x17 = 8;
	//   this->field_0x18 = 8;
	//   this->field_0x19 = 0xff;
	//   this->field_0x1a = 0;
	//   this->field_0x1b = 1;
	//   this->field_0x1c = 0;
	this->fbWidth = 0x280;
	this->efbHeight = 0x1e0;
	//   this->field_0x30 = 0;
	//   this->field_0x20 = 0xff;
	//   this->field_0x21 = 0xff;
	//   this->field_0x22 = 0xff;
	//   this->field_0x23 = 0xff;
	//   this->mTriggerThreshLo = 0.9;
	//   this->mTriggerThreshHi = 0.6;
	//   this->field_0x3c = 0xff;
	//   this->field_0x3d = 0x96;
	//   this->field_0x3e = 0;
	//   this->field_0x3f = 0xff;
	//   this->field_0x40 = 0xff;
	//   this->field_0x41 = 0x78;
	//   this->field_0x42 = 0;
	//   this->field_0x43 = 0xff;
	//   this->field_0x44 = 0;
	//   this->field_0x45 = 0;
	//   this->field_0x46 = 0;
	//   this->field_0x47 = 0xff;
	//   this->field_0x48 = 0;
	//   this->field_0x49 = 0;
	//   this->field_0x4a = 0;
	//   this->field_0x4b = 0xff;
	//   this->field62_0x4c = 0;
	//   this->field63_0x4e = 10;
	//   this->field66_0x54 = 0x1b;
	//   this->field64_0x50 = 0;
	//   this->field65_0x52 = 0;
	//   this->field_0x56 = 0x82;
}

namespace f_ap_game {
	fapGm_HIO_c g_HIO;

	void fapGm_After(void) {
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