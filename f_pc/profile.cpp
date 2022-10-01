#include "profile.h"

namespace f_pc_profile {
	f_pc_profile__Profile_Base *g_fpcPf_ProfileList_p[] = {
        //TODO: make some 500 profiles, i dunno
    };

	f_pc_profile__Profile_Base *fpcPf_Get(short param_1) {
		return g_fpcPf_ProfileList_p[param_1];
	}
}