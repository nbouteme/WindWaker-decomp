#pragma once
#include <ctypes.h>



namespace f_op_draw_iter {
//[BSS] Expected size is 0x000004
extern undefined4 l_fopDwTg_id;
node_class * fopDwIt_GetTag(void);
void fopDwIt_Begin(void);
node_class * fopDwIt_Next(create_tag_class *param_1);
}
