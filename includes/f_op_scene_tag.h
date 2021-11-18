#pragma once
#include <ctypes.h>



namespace f_op_scene_tag {
//[Data] Expected size is 0x00000c
extern pointer g_fopScnTg_SceneList;

void fopScnTg_QueueTo(create_tag_class *param_1);
void fopScnTg_ToQueue(create_tag_class *param_1);
void fopScnTg_Init(scene_tag_class *param_1,void *param_2);
}
