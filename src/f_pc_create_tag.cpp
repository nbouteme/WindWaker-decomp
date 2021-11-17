#include <f_pc_create_tag.h>
#include <SComponent/c_tag.h>


namespace f_pc_create_tag {

/* __stdcall fpcCtTg_ToCreateQ(create_tag *) */

void fpcCtTg_ToCreateQ(create_tag *param_1)

{
  SComponent::cTg_Addition(&g_fpcCtTg_Queue,&param_1->parent);
  return;
}


/* __stdcall fpcCtTg_CreateQTo(create_tag *) */

void fpcCtTg_CreateQTo(create_tag *param_1)

{
  SComponent::cTg_SingleCut(&param_1->parent);
  return;
}


/* __stdcall fpcCtTg_Init(create_tag *,
                          void *) */

undefined4 fpcCtTg_Init(create_tag *param_1,void *param_2)

{
  SComponent::cTg_Create(&param_1->parent,param_2);
  return 1;
}

