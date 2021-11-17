#include <f_op_scene_iter.h>
#include <SComponent/c_tag_iter.h>
#include <SComponent/c_list_iter.h>


namespace f_op_scene_iter {

/* __stdcall fopScnIt_Judge(void * *(void *,void *),
                            void *) */

scene_class * fopScnIt_Judge(undefined *param_1,void *param_2)

{
  scene_class *psVar1;
  undefined *local_8;
  void *local_4;
  
  local_8 = param_1;
  local_4 = param_2;
  psVar1 = (scene_class *)
           SComponent::cLsIt_Judge
                     ((node_list_class *)&f_op_scene_tag::g_fopScnTg_SceneList,
                      SComponent::cTgIt_JudgeFilter,&local_8);
  return psVar1;
}

