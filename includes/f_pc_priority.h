#pragma once
#include <ctypes.h>

#include <node_list_class.h>


namespace f_pc_priority {
//Expected size is 0x00000c
extern struct node_list_class l_fpcPi_Queue;

void fpcPi_IsInQueue(create_tag_class *param_1);
undefined4 fpcPi_QueueTo(process_priority_class *param_1);
undefined4 fpcPi_ToQueue(process_priority_class *param_1);
process_priority_class * fpcPi_GetFromQueue(void);
undefined4 fpcPi_Delete(process_priority_class *param_1);
bool fpcPi_IsNormal(uint param_1,ushort param_2,ushort param_3);
int fpcPi_Change(process_priority_class *param_1,uint param_2,uint param_3,uint param_4);
int fpcPi_Handler(void);
uint fpcPi_Init(process_priority_class *param_1,void *param_2,uint param_3,ushort param_4,ushort param_5);
}
