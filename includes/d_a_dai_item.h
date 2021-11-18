#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>
#include <dCcD_Cyl__vtbl.h>


namespace d_a_dai_item {
//[Data] Expected size is 0x000044
extern undefined l_cyl_src;

//[Data] Expected size is 0x000010
extern undefined * VobjFlagPosTbl;

//[Data] Expected size is 0x000090
extern undefined4 item_action_tbl;

//[Data] Expected size is 0x000024
extern undefined4 mode_proc$4891;

//[Data] Expected size is 0x000020
extern struct profile_method_class daStandItemMethodTable;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_STANDITEM;

}

namespace dCcD_Cyl {
//[Data] Expected size is 0x000088
extern struct dCcD_Cyl__vtbl __vt;

}

namespace d_a_dai_item {
//[Data] Expected size is 0x000008
extern pointer Vobj03_pos;

//[Data] Expected size is 0x000008
extern pointer Vobj04_pos;

//[Data] Expected size is 0x000008
extern pointer Vobj05_pos;

//[Data] Expected size is 0x000008
extern pointer Vobj07_0_pos;

//[BSS] Expected size is 0x00012c
extern undefined Vobj03_pos0;
//[BSS] Expected size is 0x00012c
extern undefined Vobj03_pos1;
//[BSS] Expected size is 0x00012c
extern undefined Vobj04_pos0;
//[BSS] Expected size is 0x00012c
extern undefined Vobj04_pos1;
//[BSS] Expected size is 0x00012c
extern undefined Vobj05_pos0;
//[BSS] Expected size is 0x00012c
extern undefined Vobj05_pos1;
//[BSS] Expected size is 0x00012c
extern undefined Vobj07_0_pos0;
//[BSS] Expected size is 0x00012c
extern undefined Vobj07_0_pos1;
//[BSS] Expected size is 0x000001
extern undefined1 init$4895;
undefined4 convItemNo(undefined param_1);
}

namespace d_a_dai_item {
void CheckCreateHeap(daStandItem_c *param_1);
}

namespace d_a_dai_item {
void daStandItem_Create(daStandItem_c *param_1);
undefined daStandItem_Delete(daStandItem_c *param_1);
undefined daStandItem_Draw(daStandItem_c *param_1);
undefined daStandItem_Execute(daStandItem_c *param_1);
undefined4 daStandItem_IsDelete(void);
}

namespace d_a_dai_item {
void __sinit_d_a_dai_item_cpp(void);
void __arraydtor$4071(void);
void __arraydtor$4069(void);
void __arraydtor$4067(void);
void __arraydtor$4065(void);
void __arraydtor$4063(void);
void __arraydtor$4061(void);
void __arraydtor$4059(void);
void __arraydtor$4057(void);
}
