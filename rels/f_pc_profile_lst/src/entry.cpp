#include <f_pc/profile.h>

namespace f_pc_profile_lst {
    f_pc_profile__Profile_Base *g_fpcPfLst_ProfileList[] = {
    };
}

extern "C" {
    int prolog() {
        f_pc_profile::g_fpcPf_ProfileList_p = f_pc_profile_lst::g_fpcPfLst_ProfileList;
    }
}