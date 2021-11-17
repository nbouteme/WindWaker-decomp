#pragma once
#include <ctypes.h>



namespace d_a_dai_item {
//Expected size is 0x00012c
extern undefined Vobj03_pos0;

//Expected size is 0x00012c
extern undefined Vobj03_pos1;

//Expected size is 0x00012c
extern undefined Vobj04_pos0;

//Expected size is 0x00012c
extern undefined Vobj04_pos1;

//Expected size is 0x00012c
extern undefined Vobj05_pos0;

//Expected size is 0x00012c
extern undefined Vobj05_pos1;

//Expected size is 0x00012c
extern undefined Vobj07_0_pos0;

//Expected size is 0x00012c
extern undefined Vobj07_0_pos1;

//Expected size is 0x000001
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
