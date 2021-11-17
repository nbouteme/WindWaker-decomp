#include <f_op_actor_tag.h>
#include <SComponent/c_tag.h>


namespace f_op_actor_tag {

/* __stdcall fopAcTg_ToActorQ(create_tag_class *) */

void fopAcTg_ToActorQ(create_tag_class *param_1)

{
  SComponent::cTg_Addition(&g_fopAcTg_Queue,param_1);
  return;
}


/* __stdcall fopAcTg_ActorQTo(create_tag_class *) */

void fopAcTg_ActorQTo(create_tag_class *param_1)

{
  SComponent::cTg_SingleCutFromTree(param_1);
  return;
}


/* __stdcall fopAcTg_Init(create_tag_class *,
                          void *) */

undefined4 fopAcTg_Init(create_tag_class *param_1,void *param_2)

{
  SComponent::cTg_Create(param_1,param_2);
  return 1;
}

