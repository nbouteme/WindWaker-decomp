#include <d_kankyo_data.h>


namespace d_kankyo {

namespace d_kankyo_data {

/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall dKyd_dmpalet_getp(void) */

stage_palet_info_class * dKyd_dmpalet_getp(void)

{
  return l_field_data;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall dKyd_dmpselect_getp(void) */

stage_pselect_info_class * dKyd_dmpselect_getp(void)

{
  return l_pselect_default;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall dKyd_dmenvr_getp(void) */

stage_envr_info_class * dKyd_dmenvr_getp(void)

{
  return l_envr_default;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall dKyd_dmvrbox_getp(void) */

stage_vrbox_info_class * dKyd_dmvrbox_getp(void)

{
  return l_vr_box_data;
}


/* __stdcall dKyd_schejule_getp(void) */

undefined * dKyd_schejule_getp(void)

{
  return &l_time_attribute;
}


/* __stdcall dKyd_schejule_boss_getp(void) */

undefined * dKyd_schejule_boss_getp(void)

{
  return &l_time_attribute_boss;
}


/* __stdcall dKyd_schejule_menu_getp(void) */

undefined * dKyd_schejule_menu_getp(void)

{
  return &l_time_attribute_menu;
}


/* __stdcall dKyd_xfog_table_set(unsigned char) */

void dKyd_xfog_table_set(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 10;
  do {
    *(undefined2 *)((int)g_env_light.mFogAdjTable.r + iVar1) =
         *(undefined2 *)((int)S_xfog_table_data[param_1 & 0xff].r + iVar1);
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

