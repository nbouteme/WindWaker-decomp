#pragma once
#include <ctypes.h>



namespace d_a_npc_fa1 {
//Expected size is 0x000094
extern undefined l_HIO;

//Expected size is 0x000004
extern undefined4 l_hio_counter;

//Expected size is 0x000004
extern undefined4 a_heap_size_tbl$4888;

//Expected size is 0x000001
extern undefined1 init$4889;

}

namespace d_a_npc_fa1 {
void CheckCreateHeap(daNpc_Fa1_c *param_1);
}

namespace d_a_npc_fa1 {
void daNpc_Fa1_Create(daNpc_Fa1_c *param_1);
void daNpc_Fa1_Delete(daNpc_Fa1_c *param_1);
void daNpc_Fa1_Execute(daNpc_Fa1_c *param_1);
void daNpc_Fa1_Draw(daNpc_Fa1_c *param_1);
undefined4 daNpc_Fa1_IsDelete(void);
}

namespace d_a_npc_fa1 {
short cLib_calcTimer(short *param_1);
int cLib_getRndValue(uint param_1,uint param_2);
int cLib_getRndValue(uint param_1,uint param_2);
void __sinit_d_a_npc_fa1_cpp(void);
}
