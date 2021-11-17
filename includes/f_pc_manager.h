#pragma once
#include <ctypes.h>

#include <layer_class.h>


namespace f_pc_manager {
//Expected size is 0x00002c
extern struct layer_class rootlayer$4264;

//Expected size is 0x000078
extern struct node_list_class queue$4265[10];

//Expected size is 0x000004
extern undefined4 l_dvdError$4230;

//Expected size is 0x000001
extern undefined1 init$4231;

void fpcM_Draw(void *param_1);
void fpcM_DrawIterater(undefined4 param_1);
void fpcM_Execute(void *param_1);
void fpcM_Delete(base_process_class *param_1);
void fpcM_IsCreating(void);
void messageSet(int param_1);
void drawDvdCondition(... param_1);
int checkDvdCondition(void);
void fpcM_Management(code *param_1,code *param_2);
void fpcM_Init(void);
void fpcM_FastCreate(short param_1,undefined *param_2,void *param_3,void *param_4);
void fpcM_IsPause(base_process_class *param_1,undefined1 param_2);
void fpcM_PauseEnable(process_node_class *param_1,byte param_2);
void fpcM_PauseDisable(base_process_class *param_1,byte param_2);
int fpcM_JudgeInLayer(uint param_1,undefined4 param_2,undefined4 param_3);
}
