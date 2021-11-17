#include <d_item_data.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <dItem_data.h>


/* __thiscall dItem_data::checkAppearEffect(unsigned char) */

ulonglong __thiscall dItem_data::checkAppearEffect(dItem_data *this,uchar param_1)

{
  undefined3 in_register_00000010;
  
  if (0x80 < ((uint)this & 0xff)) {
    return (ulonglong)CONCAT31(in_register_00000010,param_1);
  }
  return (ulonglong)
         CONCAT14((ushort)effect_info[((uint)this & 0xff) * 2] != 0x8466,
                  (uint)(ushort)effect_info[((uint)this & 0xff) * 2]);
}


namespace dItem_data {

/* __thiscall getAppearEffect(unsigned char) */

uint getAppearEffect(uchar param_1)

{
  ulong uVar1;
  
  if (effect_info[(uint)param_1 * 2] == -0x7b9a) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar1,"d_item_data.cpp",0x25cc,"effect_info[no].m_appear != dPa_name::ID_SCENE_END");
    m_Do_printf::OSPanic("d_item_data.cpp",0x25cc,"Halt");
  }
  return (uint)(ushort)effect_info[(uint)param_1 * 2];
}


/* __thiscall checkSpecialEffect(unsigned char) */

uint checkSpecialEffect(dItem_data__ItemNo param_1)

{
  if (triforce_map8 < param_1) {
    return 0;
  }
  return (uint)(effect_info[(uint)param_1 * 2 + 1] != -0x7b9a);
}

}

/* __thiscall dItem_data::getSpecialEffect(unsigned char) */

short __thiscall dItem_data::getSpecialEffect(dItem_data *this,uchar param_1)

{
  ulong uVar1;
  
  if (effect_info[((uint)this & 0xff) * 2 + 1] == -0x7b9a) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar1,"d_item_data.cpp",0x25e4,
               "effect_info[no].m_sp_effect != dPa_name::ID_SCENE_END");
    m_Do_printf::OSPanic("d_item_data.cpp",0x25e4,"Halt");
  }
  return effect_info[((uint)this & 0xff) * 2 + 1];
}


namespace d_item_data {

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */

void __sinit_d_item_data_cpp(void)

{
  ::dItem_data::item_resource[0].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::item_resource[0].mIconFilename = PTR_s_bottle_00_bti_80384130;
  ::dItem_data::item_resource[1].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[1].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[2].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[2].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[3].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[3].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[4].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[4].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[5].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[5].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[6].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[6].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[7].mModelArcName = PTR_s_Vhkak_80383f28;
  ::dItem_data::item_resource[7].mIconFilename = PTR_s_heart_up_02_bti_803840ec;
  ::dItem_data::item_resource[8].mModelArcName = PTR_s_Vhutu_80383f24;
  ::dItem_data::item_resource[8].mIconFilename = PTR_s_heart_up_01_bti_803840e8;
  ::dItem_data::item_resource[9].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::item_resource[9].mIconFilename = PTR_s_bottle_00_bti_80384130;
  ::dItem_data::item_resource[10].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::item_resource[10].mIconFilename = PTR_s_bottle_00_bti_80384130;
  ::dItem_data::item_resource[11].mModelArcName = PTR_s_Bomb_00_80383f38;
  ::dItem_data::item_resource[11].mIconFilename = PTR_s_bomb_00_bti_80384128;
  ::dItem_data::item_resource[12].mModelArcName = PTR_s_Bomb_00_80383f38;
  ::dItem_data::item_resource[12].mIconFilename = PTR_s_bomb_00_bti_80384128;
  ::dItem_data::item_resource[13].mModelArcName = PTR_s_Bomb_00_80383f38;
  ::dItem_data::item_resource[13].mIconFilename = PTR_s_bomb_00_bti_80384128;
  ::dItem_data::item_resource[14].mModelArcName = PTR_s_Bomb_00_80383f38;
  ::dItem_data::item_resource[14].mIconFilename = PTR_s_bomb_00_bti_80384128;
  ::dItem_data::item_resource[15].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[15].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[16].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::item_resource[16].mIconFilename = PTR_s_bow_01_bti_80384124;
  ::dItem_data::item_resource[17].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::item_resource[17].mIconFilename = PTR_s_bow_01_bti_80384124;
  ::dItem_data::item_resource[18].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::item_resource[18].mIconFilename = PTR_s_bow_01_bti_80384124;
  ::dItem_data::item_resource[21].mModelArcName = PTR_s_VkeyN_80383f2c;
  ::dItem_data::item_resource[21].mIconFilename = PTR_s_get_key_bti_803840e4;
  ::dItem_data::item_resource[22].mModelArcName = PTR_DAT_80384040;
  ::dItem_data::item_resource[23].mIconFilename = PTR_s_heart_up_02_bti_803840ec;
  ::dItem_data::item_resource[24].mIconFilename = PTR_s_heart_up_02_bti_803840ec;
  ::dItem_data::item_resource[25].mIconFilename = PTR_s_heart_up_02_bti_803840ec;
  ::dItem_data::item_resource[26].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[26].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[30].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::item_resource[30].mIconFilename = PTR_s_bottle_00_bti_80384130;
  ::dItem_data::item_resource[31].mModelArcName = PTR_s_Vhapp_80384004;
  ::dItem_data::item_resource[31].mIconFilename = PTR_s_beast_08_bti_8038416c;
  ::dItem_data::item_resource[32].mModelArcName = PTR_s_tele_00_80383f34;
  ::dItem_data::item_resource[32].mIconFilename = PTR_s_telescope_bti_803840f0;
  ::dItem_data::item_resource[33].mModelArcName = PTR_s_Vchin_80383fd8;
  ::dItem_data::item_resource[33].mIconFilename = PTR_s_whistle_bti_803840f4;
  ::dItem_data::item_resource[34].mModelArcName = PTR_s_Vtact_8038402c;
  ::dItem_data::item_resource[34].mIconFilename = PTR_s_baton_bti_803840f8;
  ::dItem_data::item_resource[35].mModelArcName = PTR_s_VboxN_80383f80;
  ::dItem_data::item_resource[35].mIconFilename = PTR_s_camera_bti_803840fc;
  ::dItem_data::item_resource[36].mModelArcName = PTR_s_VbagE_80383f94;
  ::dItem_data::item_resource[36].mIconFilename = PTR_s_coverofbeast_bti_80384100;
  ::dItem_data::item_resource[37].mModelArcName = PTR_s_Vrope_80384008;
  ::dItem_data::item_resource[37].mIconFilename = PTR_s_rope_bti_80384108;
  ::dItem_data::item_resource[38].mModelArcName = PTR_s_VboxA_803840c4;
  ::dItem_data::item_resource[38].mIconFilename = PTR_s_camera_2_bti_8038429c;
  ::dItem_data::item_resource[39].mModelArcName = PTR_DAT_8038403c;
  ::dItem_data::item_resource[39].mIconFilename = PTR_s_bow_01_bti_80384124;
  ::dItem_data::item_resource[40].mModelArcName = PTR_s_Vpowr_80383fc8;
  ::dItem_data::item_resource[40].mIconFilename = PTR_s_gloves_00_bti_803841b4;
  ::dItem_data::item_resource[41].mModelArcName = PTR_s_Vboot_80383f70;
  ::dItem_data::item_resource[41].mIconFilename = PTR_s_boots_00_bti_80384118;
  ::dItem_data::item_resource[42].mModelArcName = PTR_s_VmagS_8038400c;
  ::dItem_data::item_resource[42].mIconFilename = PTR_s_shield_02_bti_80384148;
  ::dItem_data::item_resource[43].mModelArcName = PTR_s_VbomL_80383f74;
  ::dItem_data::item_resource[43].mIconFilename = PTR_s_boots_01_bti_8038411c;
  ::dItem_data::item_resource[44].mModelArcName = PTR_s_VbagF_80383f98;
  ::dItem_data::item_resource[44].mIconFilename = PTR_s_coverofbait_bti_80384120;
  ::dItem_data::item_resource[45].mModelArcName = PTR_DAT_80383f6c;
  ::dItem_data::item_resource[45].mIconFilename = PTR_s_boomerang_bti_80384104;
  ::dItem_data::item_resource[46].mModelArcName = PTR_s_Vfuku_80384060;
  ::dItem_data::item_resource[46].mIconFilename = PTR_s_gloves_00_bti_803841b0;
  ::dItem_data::item_resource[47].mModelArcName = PTR_s_Vhook_80383fc4;
  ::dItem_data::item_resource[47].mIconFilename = PTR_s_hookshot_bti_80384144;
  ::dItem_data::item_resource[48].mModelArcName = PTR_s_VbagH_80383f90;
  ::dItem_data::item_resource[48].mIconFilename = PTR_s_delivery_bti_80384140;
  ::dItem_data::item_resource[49].mModelArcName = PTR_s_Bomb_00_80383f38;
  ::dItem_data::item_resource[49].mIconFilename = PTR_s_bomb_00_bti_80384128;
  ::dItem_data::item_resource[50].mModelArcName = PTR_s_Vfuku_80384060;
  ::dItem_data::item_resource[50].mIconFilename = PTR_s_clothes_bti_8038426c;
  ::dItem_data::item_resource[51].mModelArcName = PTR_s_Vhamm_80383fdc;
  ::dItem_data::item_resource[51].mIconFilename = PTR_s_hammer_01_bti_80384114;
  ::dItem_data::item_resource[52].mModelArcName = PTR_s_Vleaf_80383f8c;
  ::dItem_data::item_resource[52].mIconFilename = PTR_s_fan_bti_80384110;
  ::dItem_data::item_resource[53].mModelArcName = PTR_s_Varfi_80384030;
  ::dItem_data::item_resource[53].mIconFilename = PTR_s_arrow_power_01_bti_80384294;
  ::dItem_data::item_resource[54].mModelArcName = PTR_s_Varrl_80384038;
  ::dItem_data::item_resource[54].mIconFilename = PTR_s_arrow_power_02_bti_80384298;
  ::dItem_data::item_resource[55].mIconFilename = PTR_s_clothes_bti_8038426c;
  ::dItem_data::item_resource[56].mModelArcName = PTR_s_VswoN_8038401c;
  ::dItem_data::item_resource[56].mIconFilename = PTR_s_sword_00_bti_803841a0;
  ::dItem_data::item_resource[57].mIconFilename = PTR_s_sword_01_bti_803841a4;
  ::dItem_data::item_resource[58].mIconFilename = PTR_s_sword_02_bti_80384264;
  ::dItem_data::item_resource[59].mModelArcName = PTR_s_VshiN_80384024;
  ::dItem_data::item_resource[59].mIconFilename = PTR_s_shield_00_bti_803841a8;
  ::dItem_data::item_resource[60].mModelArcName = PTR_s_VshiM_80384020;
  ::dItem_data::item_resource[60].mIconFilename = PTR_s_shield_01_bti_803841ac;
  ::dItem_data::item_resource[61].mModelArcName = PTR_s_VswoN_8038401c;
  ::dItem_data::item_resource[61].mIconFilename = PTR_s_sword_00_bti_803841a0;
  ::dItem_data::item_resource[62].mIconFilename = PTR_s_sword_03_bti_80384268;
  ::dItem_data::item_resource[63].mModelArcName = PTR_s_Vhkak_80383f28;
  ::dItem_data::item_resource[63].mIconFilename = PTR_s_heart_up_02_bti_803840ec;
  ::dItem_data::item_resource[66].mModelArcName = PTR_s_Vamuk_80383fe0;
  ::dItem_data::item_resource[66].mIconFilename = PTR_s_amulet_00_bti_803841b8;
  ::dItem_data::item_resource[67].mModelArcName = PTR_s_Vamuy_80383fe4;
  ::dItem_data::item_resource[67].mIconFilename = PTR_s_amulet_01_bti_803841bc;
  ::dItem_data::item_resource[68].mIconFilename = PTR_s_bottle_00_bti_80384130;
  ::dItem_data::item_resource[69].mModelArcName = PTR_s_Vdoku_80384064;
  ::dItem_data::item_resource[69].mIconFilename = PTR_s_beast_01_bti_80384150;
  ::dItem_data::item_resource[70].mModelArcName = PTR_s_Vboko_80383f44;
  ::dItem_data::item_resource[70].mIconFilename = PTR_s_beast_02_bti_80384154;
  ::dItem_data::item_resource[71].mModelArcName = PTR_s_Vhane_80383f40;
  ::dItem_data::item_resource[71].mIconFilename = PTR_s_beast_03_bti_80384158;
  ::dItem_data::item_resource[72].mModelArcName = PTR_s_Vbelt_80384068;
  ::dItem_data::item_resource[72].mIconFilename = PTR_s_beast_04_bti_8038415c;
  ::dItem_data::item_resource[73].mModelArcName = PTR_s_Vchuj_80383f48;
  ::dItem_data::item_resource[73].mIconFilename = PTR_s_beast_05_bti_80384160;
  ::dItem_data::item_resource[74].mModelArcName = PTR_s_Vchuj_80383f48;
  ::dItem_data::item_resource[74].mIconFilename = PTR_s_beast_06_bti_80384164;
  ::dItem_data::item_resource[75].mModelArcName = PTR_s_Vchuj_80383f48;
  ::dItem_data::item_resource[75].mIconFilename = PTR_s_beast_07_bti_80384168;
  ::dItem_data::item_resource[76].mModelArcName = PTR_s_VdunM_80383f88;
  ::dItem_data::item_resource[76].mIconFilename = PTR_s_dungeon_map_bti_80384208;
  ::dItem_data::item_resource[77].mModelArcName = PTR_s_VdunC_80383f84;
  ::dItem_data::item_resource[77].mIconFilename = PTR_s_compass_bti_8038420c;
  ::dItem_data::item_resource[78].mModelArcName = PTR_s_key_01_80383f30;
  ::dItem_data::item_resource[78].mIconFilename = PTR_s_boss_key_bti_80384210;
  ::dItem_data::item_resource[79].mIconFilename = PTR_s_bottle_00_bti_80384130;
  ::dItem_data::item_resource[80].mModelArcName = PTR_DAT_80383f64;
  ::dItem_data::item_resource[80].mIconFilename = PTR_s_bottle_00_bti_80384130;
  ::dItem_data::item_resource[81].mModelArcName = PTR_s_Med_r_80383ff0;
  ::dItem_data::item_resource[81].mIconFilename = PTR_s_bottle_01_bti_80384134;
  ::dItem_data::item_resource[82].mModelArcName = PTR_s_Med_g_80383fec;
  ::dItem_data::item_resource[82].mIconFilename = PTR_s_bottle_02_bti_80384138;
  ::dItem_data::item_resource[83].mModelArcName = PTR_s_Med_b_80383fe8;
  ::dItem_data::item_resource[83].mIconFilename = PTR_s_bottle_03_bti_8038413c;
  ::dItem_data::item_resource[84].mModelArcName = PTR_s_VbinS_80384058;
  ::dItem_data::item_resource[84].mIconFilename = PTR_s_bottle_09_bti_803842a4;
  ::dItem_data::item_resource[85].mModelArcName = PTR_s_VbinS_80384058;
  ::dItem_data::item_resource[85].mIconFilename = PTR_s_bottle_04_bti_80384214;
  ::dItem_data::item_resource[86].mModelArcName = PTR_s_VbinW_8038405c;
  ::dItem_data::item_resource[86].mIconFilename = PTR_s_bottle_05_bti_80384218;
  ::dItem_data::item_resource[87].mModelArcName = PTR_s_VBinY_80384050;
  ::dItem_data::item_resource[87].mIconFilename = PTR_s_bottle_06_bti_8038421c;
  ::dItem_data::item_resource[88].mModelArcName = PTR_s_VbinH_80384054;
  ::dItem_data::item_resource[88].mIconFilename = PTR_s_bottle_07_bti_80384220;
  ::dItem_data::item_resource[89].mModelArcName = PTR_s_FwBin_8038404c;
  ::dItem_data::item_resource[89].mIconFilename = PTR_s_bottle_08_bti_80384224;
  ::dItem_data::item_resource[97].mModelArcName = PTR_s_Vtri1_80384028;
  ::dItem_data::item_resource[97].mIconFilename = PTR_s_triforce_00_bti_8038422c;
  ::dItem_data::item_resource[98].mModelArcName = PTR_s_Vtri2_80384094;
  ::dItem_data::item_resource[98].mIconFilename = PTR_s_triforce_01_bti_80384230;
  ::dItem_data::item_resource[99].mModelArcName = PTR_s_Vtri3_80384098;
  ::dItem_data::item_resource[99].mIconFilename = PTR_s_triforce_02_bti_80384234;
  ::dItem_data::item_resource[100].mModelArcName = PTR_s_Vtri4_8038409c;
  ::dItem_data::item_resource[100].mIconFilename = PTR_s_triforce_03_bti_80384238;
  ::dItem_data::item_resource[101].mModelArcName = PTR_s_Vtri5_803840a0;
  ::dItem_data::item_resource[101].mIconFilename = PTR_s_triforce_04_bti_8038423c;
  ::dItem_data::item_resource[102].mModelArcName = PTR_s_Vtri6_803840a4;
  ::dItem_data::item_resource[102].mIconFilename = PTR_s_triforce_05_bti_80384240;
  ::dItem_data::item_resource[103].mModelArcName = PTR_s_Vtri7_803840a8;
  ::dItem_data::item_resource[103].mIconFilename = PTR_s_triforce_06_bti_80384244;
  ::dItem_data::item_resource[104].mModelArcName = PTR_s_Vtri8_803840ac;
  ::dItem_data::item_resource[104].mIconFilename = PTR_s_triforce_07_bti_80384248;
  ::dItem_data::item_resource[105].mModelArcName = PTR_s_Shinju_n_80384010;
  ::dItem_data::item_resource[105].mIconFilename = PTR_s_god_symbol_02_bti_8038419c;
  ::dItem_data::item_resource[106].mModelArcName = PTR_s_Shinju_d_80384044;
  ::dItem_data::item_resource[106].mIconFilename = PTR_s_god_symbol_00_bti_80384194;
  ::dItem_data::item_resource[107].mModelArcName = PTR_s_Shinju_f_80384048;
  ::dItem_data::item_resource[107].mIconFilename = PTR_s_god_symbol_01_bti_80384198;
  ::dItem_data::item_resource[108].mModelArcName = PTR_s_Vamuk_80383fe0;
  ::dItem_data::item_resource[108].mIconFilename = PTR_s_amulet_00_bti_803841b8;
  ::dItem_data::item_resource[109].mModelArcName = PTR_s_Vamuk_80383fe0;
  ::dItem_data::item_resource[109].mIconFilename = PTR_s_baton_bti_803840f8;
  ::dItem_data::item_resource[110].mModelArcName = PTR_s_Vamuk_80383fe0;
  ::dItem_data::item_resource[110].mIconFilename = PTR_s_baton_bti_803840f8;
  ::dItem_data::item_resource[111].mModelArcName = PTR_s_Vamuk_80383fe0;
  ::dItem_data::item_resource[111].mIconFilename = PTR_s_baton_bti_803840f8;
  ::dItem_data::item_resource[112].mModelArcName = PTR_s_Vamuk_80383fe0;
  ::dItem_data::item_resource[112].mIconFilename = PTR_s_baton_bti_803840f8;
  ::dItem_data::item_resource[113].mModelArcName = PTR_s_Vamuk_80383fe0;
  ::dItem_data::item_resource[113].mIconFilename = PTR_s_baton_bti_803840f8;
  ::dItem_data::item_resource[114].mModelArcName = PTR_s_Vamuk_80383fe0;
  ::dItem_data::item_resource[114].mIconFilename = PTR_s_baton_bti_803840f8;
  ::dItem_data::item_resource[120].mModelArcName = PTR_DAT_80383fcc;
  ::dItem_data::item_resource[120].mIconFilename = PTR_s_sail_00_bti_8038410c;
  ::dItem_data::item_resource[121].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[121].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[122].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[122].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[123].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[123].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[124].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[124].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[125].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[125].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[126].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[126].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[127].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[127].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[128].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[128].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[130].mModelArcName = PTR_s_Vesa_80383fa0;
  ::dItem_data::item_resource[130].mIconFilename = PTR_s_bait_01_bti_80384170;
  ::dItem_data::item_resource[131].mModelArcName = PTR_s_Vhyoi_80383f9c;
  ::dItem_data::item_resource[131].mIconFilename = PTR_s_bait_02_bti_80384174;
  ::dItem_data::item_resource[140].mModelArcName = PTR_s_Vobj00_80383fb8;
  ::dItem_data::item_resource[140].mIconFilename = PTR_s_delivery_01_bti_803841c0;
  ::dItem_data::item_resource[141].mModelArcName = PTR_s_Vobj01_80383fbc;
  ::dItem_data::item_resource[141].mIconFilename = PTR_s_delivery_02_bti_803841c4;
  ::dItem_data::item_resource[142].mModelArcName = PTR_s_Vobj02_80383fc0;
  ::dItem_data::item_resource[142].mIconFilename = PTR_s_delivery_03_bti_803841c8;
  ::dItem_data::item_resource[143].mModelArcName = PTR_s_Vobj03_80383fb4;
  ::dItem_data::item_resource[143].mIconFilename = PTR_s_delivery_04_bti_803841cc;
  ::dItem_data::item_resource[144].mModelArcName = PTR_s_Vobj04_80383fb0;
  ::dItem_data::item_resource[144].mIconFilename = PTR_s_delivery_05_bti_803841d0;
  ::dItem_data::item_resource[145].mModelArcName = PTR_s_Vobj05_80383fac;
  ::dItem_data::item_resource[145].mIconFilename = PTR_s_delivery_06_bti_803841d4;
  ::dItem_data::item_resource[146].mModelArcName = PTR_s_Vobj06_80383fa8;
  ::dItem_data::item_resource[146].mIconFilename = PTR_s_delivery_07_bti_803841d8;
  ::dItem_data::item_resource[147].mModelArcName = PTR_s_Vobj07_80383fa4;
  ::dItem_data::item_resource[147].mIconFilename = PTR_s_delivery_08_bti_803841dc;
  ::dItem_data::item_resource[148].mModelArcName = PTR_s_Vobj08_80383ff4;
  ::dItem_data::item_resource[148].mIconFilename = PTR_s_delivery_09_bti_803841e0;
  ::dItem_data::item_resource[149].mModelArcName = PTR_s_Vobj09_80383ff8;
  ::dItem_data::item_resource[149].mIconFilename = PTR_s_delivery_10_bti_803841e4;
  ::dItem_data::item_resource[150].mModelArcName = PTR_s_Vobj10_80384000;
  ::dItem_data::item_resource[150].mIconFilename = PTR_s_delivery_11_bti_803841e8;
  ::dItem_data::item_resource[151].mModelArcName = PTR_s_Vobj11_80383ffc;
  ::dItem_data::item_resource[151].mIconFilename = PTR_s_delivery_12_bti_803841ec;
  ::dItem_data::item_resource[152].mModelArcName = PTR_s_VleTT_80384070;
  ::dItem_data::item_resource[152].mIconFilename = PTR_s_delivery_13_bti_803841f0;
  ::dItem_data::item_resource[153].mModelArcName = PTR_s_VleOF_80384074;
  ::dItem_data::item_resource[153].mIconFilename = PTR_s_delivery_14_bti_803841f4;
  ::dItem_data::item_resource[154].mModelArcName = PTR_s_VleMG_80384078;
  ::dItem_data::item_resource[154].mIconFilename = PTR_s_delivery_15_bti_803841f8;
  ::dItem_data::item_resource[155].mModelArcName = PTR_s_VleMO_8038407c;
  ::dItem_data::item_resource[155].mIconFilename = PTR_s_delivery_16_bti_803841fc;
  ::dItem_data::item_resource[156].mModelArcName = PTR_s_Vbeso_803840dc;
  ::dItem_data::item_resource[156].mIconFilename = PTR_s_delivery_17_bti_80384200;
  ::dItem_data::item_resource[157].mModelArcName = PTR_s_Vohom_80383fd4;
  ::dItem_data::item_resource[157].mIconFilename = PTR_s_delivery_18_bti_80384204;
  ::dItem_data::item_resource[158].mModelArcName = PTR_s_Vmant_80383fd0;
  ::dItem_data::item_resource[158].mIconFilename = PTR_s_delivery_19_bti_803842ac;
  ::dItem_data::item_resource[159].mModelArcName = PTR_s_VboxA_803840c4;
  ::dItem_data::item_resource[159].mIconFilename = PTR_s_camera_bti_803840fc;
  ::dItem_data::item_resource[160].mModelArcName = PTR_s_Vamuk_80383fe0;
  ::dItem_data::item_resource[160].mIconFilename = PTR_s_amulet_00_bti_803841b8;
  ::dItem_data::item_resource[161].mModelArcName = PTR_s_Vamuk_80383fe0;
  ::dItem_data::item_resource[161].mIconFilename = PTR_s_amulet_00_bti_803841b8;
  ::dItem_data::item_resource[162].mModelArcName = PTR_s_Vamuk_80383fe0;
  ::dItem_data::item_resource[162].mIconFilename = PTR_s_amulet_00_bti_803841b8;
  ::dItem_data::item_resource[163].mModelArcName = PTR_s_Vtin1_803840c8;
  ::dItem_data::item_resource[163].mIconFilename = PTR_s_tingle_figure_bti_803842a0;
  ::dItem_data::item_resource[164].mModelArcName = PTR_s_Vtin2_803840cc;
  ::dItem_data::item_resource[164].mIconFilename = PTR_s_tingle_figure_bti_803842a0;
  ::dItem_data::item_resource[165].mModelArcName = PTR_s_Vtin3_803840d0;
  ::dItem_data::item_resource[165].mIconFilename = PTR_s_tingle_figure_bti_803842a0;
  ::dItem_data::item_resource[166].mModelArcName = PTR_s_Vtin4_803840d4;
  ::dItem_data::item_resource[166].mIconFilename = PTR_s_tingle_figure_bti_803842a0;
  ::dItem_data::item_resource[167].mModelArcName = PTR_s_Vtin5_803840d8;
  ::dItem_data::item_resource[167].mIconFilename = PTR_s_tingle_figure_bti_803842a0;
  ::dItem_data::item_resource[170].mModelArcName = PTR_s_VswoN_8038401c;
  ::dItem_data::item_resource[171].mModelArcName = PTR_s_VsaiM_80383f50;
  ::dItem_data::item_resource[171].mIconFilename = PTR_s_big_purse_bti_8038425c;
  ::dItem_data::item_resource[172].mModelArcName = PTR_s_VsaiL_80383f54;
  ::dItem_data::item_resource[172].mIconFilename = PTR_s_max_purse_bti_80384260;
  ::dItem_data::item_resource[173].mModelArcName = PTR_s_VbomM_80383f68;
  ::dItem_data::item_resource[173].mIconFilename = PTR_s_bombpouch_1_bti_80384270;
  ::dItem_data::item_resource[174].mModelArcName = PTR_s_VbomL_80383f74;
  ::dItem_data::item_resource[174].mIconFilename = PTR_s_bombpouch_2_bti_80384274;
  ::dItem_data::item_resource[175].mModelArcName = PTR_s_VyatM_80383f58;
  ::dItem_data::item_resource[175].mIconFilename = PTR_s_arrowcase_1_bti_80384278;
  ::dItem_data::item_resource[176].mModelArcName = PTR_s_VyatL_80383f5c;
  ::dItem_data::item_resource[176].mIconFilename = PTR_s_arrowcase_2_bti_8038427c;
  ::dItem_data::item_resource[179].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[179].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[180].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[180].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[181].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[181].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[182].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[182].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[183].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[183].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[184].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[184].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[185].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[185].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[186].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[186].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[187].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[187].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[188].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[188].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[189].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[189].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[190].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[190].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[191].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[191].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[192].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[192].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[193].mModelArcName = PTR_s_Vlupy_8038406c;
  ::dItem_data::item_resource[193].mIconFilename = ::dItem_data::item_texture_tbl;
  ::dItem_data::item_resource[194].mModelArcName = PTR_s_VmapQ_80384034;
  ::dItem_data::item_resource[194].mIconFilename = PTR_s_cmap_hint2_bti_803842a8;
  ::dItem_data::item_resource[195].mModelArcName = PTR_s_VmapQ_80384034;
  ::dItem_data::item_resource[195].mIconFilename = PTR_s_cmap_hint2_bti_803842a8;
  ::dItem_data::item_resource[196].mModelArcName = PTR_s_VmapQ_80384034;
  ::dItem_data::item_resource[196].mIconFilename = PTR_s_cmap_hint2_bti_803842a8;
  ::dItem_data::item_resource[197].mModelArcName = PTR_s_VmapQ_80384034;
  ::dItem_data::item_resource[197].mIconFilename = PTR_s_cmap_hint2_bti_803842a8;
  ::dItem_data::item_resource[198].mModelArcName = PTR_s_VmapQ_80384034;
  ::dItem_data::item_resource[198].mIconFilename = PTR_s_cmap_hint2_bti_803842a8;
  ::dItem_data::item_resource[199].mModelArcName = PTR_s_VmapQ_80384034;
  ::dItem_data::item_resource[199].mIconFilename = PTR_s_cmap_hint2_bti_803842a8;
  ::dItem_data::item_resource[200].mModelArcName = PTR_s_VmapQ_80384034;
  ::dItem_data::item_resource[200].mIconFilename = PTR_s_cmap_hint2_bti_803842a8;
  ::dItem_data::item_resource[201].mModelArcName = PTR_s_VmapQ_80384034;
  ::dItem_data::item_resource[201].mIconFilename = PTR_s_cmap_hint2_bti_803842a8;
  ::dItem_data::item_resource[202].mModelArcName = PTR_s_VmapQ_80384034;
  ::dItem_data::item_resource[202].mIconFilename = PTR_s_cmap_hint2_bti_803842a8;
  ::dItem_data::item_resource[203].mModelArcName = PTR_s_VmapC_80383f4c;
  ::dItem_data::item_resource[203].mIconFilename = PTR_s_cmap_tingle2_bti_80384290;
  ::dItem_data::item_resource[204].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[204].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[205].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[205].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[206].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[206].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[207].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[207].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[208].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[208].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[209].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[209].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[210].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[210].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[211].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[211].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[212].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[212].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[213].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[213].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[214].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[214].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[215].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[215].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[216].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[216].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[217].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[217].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[218].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[218].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[219].mModelArcName = PTR_s_VmapG_803840c0;
  ::dItem_data::item_resource[219].mIconFilename = PTR_s_cmap_phantomship2_bti_8038428c;
  ::dItem_data::item_resource[220].mModelArcName = PTR_s_VmapC_80383f4c;
  ::dItem_data::item_resource[220].mIconFilename = PTR_s_cmap_tingle2_bti_80384290;
  ::dItem_data::item_resource[221].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[221].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[222].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[222].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[223].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[223].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[224].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[224].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[225].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[225].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[226].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[226].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[227].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[227].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[228].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[228].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[229].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[229].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[230].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[230].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[231].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[231].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[232].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[232].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[233].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[233].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[234].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[234].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[235].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[235].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[236].mModelArcName = PTR_s_VmapR_803840b8;
  ::dItem_data::item_resource[236].mIconFilename = PTR_s_cmap_treasure2_bti_80384288;
  ::dItem_data::item_resource[237].mModelArcName = PTR_s_VmapH_803840bc;
  ::dItem_data::item_resource[237].mIconFilename = PTR_s_cmap_treasure2_bti_80384284;
  ::dItem_data::item_resource[238].mModelArcName = PTR_s_VmapH_803840bc;
  ::dItem_data::item_resource[238].mIconFilename = PTR_s_cmap_treasure2_bti_80384284;
  ::dItem_data::item_resource[239].mModelArcName = PTR_s_VmapH_803840bc;
  ::dItem_data::item_resource[239].mIconFilename = PTR_s_cmap_treasure2_bti_80384284;
  ::dItem_data::item_resource[240].mModelArcName = PTR_s_VmapH_803840bc;
  ::dItem_data::item_resource[240].mIconFilename = PTR_s_cmap_treasure2_bti_80384284;
  ::dItem_data::item_resource[241].mModelArcName = PTR_s_VmapH_803840bc;
  ::dItem_data::item_resource[241].mIconFilename = PTR_s_cmap_treasure2_bti_80384284;
  ::dItem_data::item_resource[242].mModelArcName = PTR_s_VmapH_803840bc;
  ::dItem_data::item_resource[242].mIconFilename = PTR_s_cmap_treasure2_bti_80384284;
  ::dItem_data::item_resource[243].mModelArcName = PTR_s_VmapH_803840bc;
  ::dItem_data::item_resource[243].mIconFilename = PTR_s_cmap_treasure2_bti_80384284;
  ::dItem_data::item_resource[244].mModelArcName = PTR_s_VmapH_803840bc;
  ::dItem_data::item_resource[244].mIconFilename = PTR_s_cmap_treasure2_bti_80384284;
  ::dItem_data::item_resource[245].mModelArcName = PTR_s_VmapH_803840bc;
  ::dItem_data::item_resource[245].mIconFilename = PTR_s_cmap_treasure2_bti_80384284;
  ::dItem_data::item_resource[246].mModelArcName = PTR_s_VmapH_803840bc;
  ::dItem_data::item_resource[246].mIconFilename = PTR_s_cmap_treasure2_bti_80384284;
  ::dItem_data::item_resource[247].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[247].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[248].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[248].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[249].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[249].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[250].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[250].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[251].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[251].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[252].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[252].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[253].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[253].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::item_resource[254].mModelArcName = PTR_s_VmapT_803840b4;
  ::dItem_data::item_resource[254].mIconFilename = PTR_s_cmap_tri2_bti_80384280;
  ::dItem_data::field_item_res[0].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[1].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[2].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[3].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[4].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[5].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[6].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[7].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[8].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[9].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[10].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[11].mModelArcName = PTR_s_Link_80383f3c;
  ::dItem_data::field_item_res[12].mModelArcName = PTR_s_Link_80383f3c;
  ::dItem_data::field_item_res[13].mModelArcName = PTR_s_Link_80383f3c;
  ::dItem_data::field_item_res[14].mModelArcName = PTR_s_Link_80383f3c;
  ::dItem_data::field_item_res[15].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[16].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[17].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[18].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[21].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[22].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[30].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[31].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[52].mModelArcName = PTR_s_Vleaf_80383f8c;
  ::dItem_data::field_item_res[53].mModelArcName = PTR_s_Link_80383f3c;
  ::dItem_data::field_item_res[54].mModelArcName = PTR_s_Link_80383f3c;
  ::dItem_data::field_item_res[56].mModelArcName = PTR_s_VswoN_8038401c;
  ::dItem_data::field_item_res[59].mModelArcName = PTR_s_VshiN_80384024;
  ::dItem_data::field_item_res[61].mModelArcName = PTR_s_VswoN_8038401c;
  ::dItem_data::field_item_res[69].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[70].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[71].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[72].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[73].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[74].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[75].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[130].mModelArcName = ::dItem_data::item_arcname_tbl;
  ::dItem_data::field_item_res[131].mModelArcName = PTR_s_Vhyoi_80383f9c;
  ::dItem_data::field_item_res[140].mModelArcName = PTR_s_Fdai_80384080;
  ::dItem_data::field_item_res[141].mModelArcName = PTR_s_Fdai_80384084;
  ::dItem_data::field_item_res[142].mModelArcName = PTR_s_Fdai_8038408c;
  ::dItem_data::field_item_res[143].mModelArcName = PTR_s_Fdai_8038408c;
  ::dItem_data::field_item_res[144].mModelArcName = PTR_s_Fdai_8038408c;
  ::dItem_data::field_item_res[145].mModelArcName = PTR_s_Fdai_8038408c;
  ::dItem_data::field_item_res[146].mModelArcName = PTR_s_Fdai_80384088;
  ::dItem_data::field_item_res[147].mModelArcName = PTR_s_Fdai_8038408c;
  ::dItem_data::field_item_res[148].mModelArcName = PTR_s_Fdai_80384090;
  ::dItem_data::field_item_res[149].mModelArcName = PTR_s_Fdai_803840b0;
  ::dItem_data::field_item_res[150].mModelArcName = PTR_s_Fdai_80384088;
  ::dItem_data::field_item_res[151].mModelArcName = PTR_s_Fdai_80384088;
  return;
}

