#include <f_pc/profile.h>
#include <static_actors/d_s_logo.h>

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
	return 0;
}
}