#pragma once

#include <SComponent.h>
#include <f_op/scene.h>

struct mDoDvdThd_mountXArchive_c;
struct mDoDvdThd_toMainRam_c;
struct dDlst_2D_c;

namespace d_s_logo {
	extern mDoDvdThd_mountXArchive_c *l_lodCommand;
	extern mDoDvdThd_mountXArchive_c *l_anmCommand;
	extern mDoDvdThd_mountXArchive_c *l_fmapCommand;
	extern mDoDvdThd_mountXArchive_c *l_itemResCommand;
	extern mDoDvdThd_mountXArchive_c *l_fmapResCommand;
	extern mDoDvdThd_mountXArchive_c *l_dmapResCommand;
	extern mDoDvdThd_mountXArchive_c *l_clctResCommand;
	extern mDoDvdThd_mountXArchive_c *l_optResCommand;
	extern mDoDvdThd_mountXArchive_c *l_clothResCommand;
	extern mDoDvdThd_mountXArchive_c *l_itemiconCommand;
	extern mDoDvdThd_mountXArchive_c *l_actioniconCommand;
	extern mDoDvdThd_mountXArchive_c *l_scopeResCommand;
	extern mDoDvdThd_mountXArchive_c *l_camResCommand;
	extern mDoDvdThd_mountXArchive_c *l_swimResCommand;
	extern mDoDvdThd_mountXArchive_c *l_windResCommand;
	extern mDoDvdThd_mountXArchive_c *l_nameResCommand;
	extern mDoDvdThd_mountXArchive_c *l_tmsgCommand;
	extern mDoDvdThd_mountXArchive_c *l_dmsgCommand;
	extern mDoDvdThd_mountXArchive_c *l_errorResCommand;
	extern mDoDvdThd_mountXArchive_c *l_saveResCommand;
	extern mDoDvdThd_mountXArchive_c *l_msgDtCommand;
	extern mDoDvdThd_mountXArchive_c *l_msgDtCommand2;
	extern mDoDvdThd_mountXArchive_c *l_msgCommand;
	extern mDoDvdThd_mountXArchive_c *l_menuCommand;
	extern mDoDvdThd_mountXArchive_c *l_fontCommand;
	extern mDoDvdThd_mountXArchive_c *l_rubyCommand;

	extern mDoDvdThd_toMainRam_c *l_particleCommand;
	extern mDoDvdThd_toMainRam_c *l_itemTableCommand;
	extern mDoDvdThd_toMainRam_c *l_ActorDataCommand;
	extern mDoDvdThd_toMainRam_c *l_FmapDataCommand;

	mDoDvdThd_mountXArchive_c *aramMount(char *param_1);

	mDoDvdThd_mountXArchive_c *onMemMount(char *param_1);

	struct dScnLogo_c : scene_class {
		static profile_leaf_method_class methods;
		request_of_phase_process_class phaseproc;
		dDlst_2D_c *dlistlink[7];
		byte drawstep, wantsprogressive, isprogressive;
		ushort transitiontimer, newtimer, prevtimer, isoddframe, framesleft;
		void *systemblock;
		int confirmedMode;
	};

	int phase_0(dScnLogo_c *param_1);
	int phase_1(dScnLogo_c *param_1);
	int phase_2(dScnLogo_c *param_1);
	
    int nintendoInDraw(dScnLogo_c *param_1);
	int nintendoOutDraw(dScnLogo_c *param_1);
	int nintendoOut2Draw(dScnLogo_c *param_1);
	int dolbyInDraw(dScnLogo_c *param_1);
	int dolbyOutDraw(dScnLogo_c *param_1);
	int progInDraw(dScnLogo_c *param_1);
	int dvdWaitDraw(dScnLogo_c *param_1);

	extern f_pc_profile__Profile_Scene g_profile_LOGO_SCENE;
};
