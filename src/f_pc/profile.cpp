#include "profile.h"

#include <cstdio>

namespace f_pc_profile {
	f_pc_profile__Profile_Base **g_fpcPf_ProfileList_p;

	f_pc_profile__Profile_Base *fpcPf_Get(short param_1) {
		if (!g_fpcPf_ProfileList_p[param_1])
			printf("No such profile (%d) so I'm going to crash :3, glhf\n", param_1);
		return g_fpcPf_ProfileList_p[param_1];
	}
}