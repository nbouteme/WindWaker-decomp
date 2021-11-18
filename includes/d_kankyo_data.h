#pragma once
#include <ctypes.h>



namespace d_kankyo {

namespace d_kankyo_data {
//[Data] Expected size is 0x000084
extern undefined l_time_attribute;

//[Data] Expected size is 0x000084
extern undefined l_time_attribute_boss;

//[Data] Expected size is 0x000084
extern undefined l_time_attribute_menu;

//[Data] Expected size is 0x0002c0
extern struct stage_palet_info_class l_field_data[16];

//[Data] Expected size is 0x000018
extern struct stage_pselect_info_class l_pselect_default[2];

//[Data] Expected size is 0x000010
extern struct stage_envr_info_class l_envr_default[2];

//[Data] Expected size is 0x000120
extern struct stage_vrbox_info_class l_vr_box_data[8];

//[Data] Expected size is 0x000028
extern struct _GXFogAdjTable S_xfog_table_data[2];

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
