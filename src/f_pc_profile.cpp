#include <f_pc_profile.h>


namespace f_pc_profile {
undefined4 g_fpcPf_ProfileList_p;

/* __stdcall fpcPf_Get(short) */

f_pc_profile__Profile_Actor * fpcPf_Get(short param_1)

{
  return *(f_pc_profile__Profile_Actor **)(g_fpcPf_ProfileList_p + param_1 * 4);
}

