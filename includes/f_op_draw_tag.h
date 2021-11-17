#pragma once
#include <ctypes.h>



namespace f_op_draw_tag {
//Expected size is 0x002ee0
extern undefined lists$2178;

void fopDwTg_ToDrawQ(create_tag_class *param_1,int priority);
void fopDwTg_DrawQTo(create_tag_class *param_1);
undefined4 fopDwTg_Init(create_tag_class *param_1,void *param_2);
void fopDwTg_CreateQueue(void);
}
