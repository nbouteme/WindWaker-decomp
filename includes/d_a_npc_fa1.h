#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <fopNpc_npc_c__vtbl.h>
#include <mDoExt_McaMorfCallBack1_c__vtbl.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_npc_fa1 {
//[Data] Expected size is 0x000044
extern undefined l_cyl_src;

//[Data] Expected size is 0x00006c
extern undefined4 moveProc;

//[Data] Expected size is 0x000030
extern undefined4 moveSubProc;

//[Data] Expected size is 0x000024
extern undefined4 bottleMoveSubProc;

//[Data] Expected size is 0x000018
extern undefined4 bottleBabaSubProc;

//[Data] Expected size is 0x000020
extern struct profile_method_class l_daNpc_Fa1_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_NPC_FA1;

}
//[Data] Expected size is 0x000014
extern undefined1 daNpc_Fa1_c;

//[Data] Expected size is 0x000014
extern struct fopNpc_npc_c__vtbl fopNpc_npc_c;

//[Data] Expected size is 0x000010
extern struct mDoExt_McaMorfCallBack1_c__vtbl daNpc_Fa1_McaMorfCallBack1_c;

//[Data] Expected size is 0x00000c
extern undefined1 daNpc_Fa1_HIO_c;

//[Data] Expected size is 0x00000c
extern undefined1 daNpc_Fa1_HIO2_c;

//[Data] Expected size is 0x00000c
extern undefined1 daNpc_Fa1_HIO3_c;


namespace d_a_npc_fa1 {
//[BSS] Expected size is 0x000094
extern undefined l_HIO;
//[BSS] Expected size is 0x000004
extern undefined4 l_hio_counter;
//[BSS] Expected size is 0x000004
extern undefined4 a_heap_size_tbl$4888;
//[BSS] Expected size is 0x000001
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
