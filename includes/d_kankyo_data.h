#pragma once
#include <ctypes.h>



namespace d_kankyo {

namespace d_kankyo_data {
stage_palet_info_class * dKyd_dmpalet_getp(void);
stage_pselect_info_class * dKyd_dmpselect_getp(void);
stage_envr_info_class * dKyd_dmenvr_getp(void);
stage_vrbox_info_class * dKyd_dmvrbox_getp(void);
undefined * dKyd_schejule_getp(void);
undefined * dKyd_schejule_boss_getp(void);
undefined * dKyd_schejule_menu_getp(void);
void dKyd_xfog_table_set(uint param_1);
}
}
