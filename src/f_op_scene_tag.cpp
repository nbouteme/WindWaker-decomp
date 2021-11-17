#include <f_op_scene_tag.h>
#include <SComponent/c_tag.h>


namespace f_op_scene_tag {

/* __stdcall fopScnTg_QueueTo(scene_tag_class *) */

void fopScnTg_QueueTo(create_tag_class *param_1)

{
  SComponent::cTg_SingleCut(param_1);
  return;
}


/* __stdcall fopScnTg_ToQueue(scene_tag_class *) */

void fopScnTg_ToQueue(create_tag_class *param_1)

{
  SComponent::cTg_Addition((node_list_class *)&g_fopScnTg_SceneList,param_1);
  return;
}


/* __stdcall fopScnTg_Init(scene_tag_class *,
                           void *) */

void fopScnTg_Init(scene_tag_class *param_1,void *param_2)

{
  SComponent::cTg_Create(&param_1->parent,param_2);
  return;
}

