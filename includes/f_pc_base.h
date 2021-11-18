#pragma once
#include <ctypes.h>



namespace f_pc_base {
//[BSS] Expected size is 0x000004
extern undefined g_fpcBs_type;
//[BSS] Expected size is 0x000004
extern undefined4 t_type$2169;
//[BSS] Expected size is 0x000001
extern bool init$2170;
//[BSS] Expected size is 0x000004
extern undefined4 process_id$2178;
//[BSS] Expected size is 0x000001
extern undefined1 init$2179;
bool fpcBs_Is_JustOfType(int param_1,int param_2);
int fpcBs_MakeOfType(int *param_1);
int fpcBs_MakeOfId(void);
void fpcBs_Execute(base_process_class *param_1);
void fpcBs_DeleteAppend(base_process_class *param_1);
int fpcBs_IsDelete(base_process_class *param_1);
int fpcBs_Delete(base_process_class *param_1);
base_process_class * fpcBs_Create(short param_1,uint param_2,void *param_3);
undefined4 fpcBs_SubCreate(base_process_class *param_1);
}
