#include <f_op_draw_tag.h>
#include <SComponent/c_tag.h>
#include <SComponent/c_tree.h>


namespace f_op_draw_tag {
undefined lists$2178;

/* __stdcall fopDwTg_ToDrawQ(create_tag_class *,
                             int) */

void fopDwTg_ToDrawQ(create_tag_class *param_1,int priority)

{
  SComponent::cTg_AdditionToTree(&g_fopDwTg_Queue,priority,param_1);
  return;
}


/* __stdcall fopDwTg_DrawQTo(create_tag_class *) */

void fopDwTg_DrawQTo(create_tag_class *param_1)

{
  SComponent::cTg_SingleCutFromTree(param_1);
  return;
}


/* __stdcall fopDwTg_Init(create_tag_class *,
                          void *) */

undefined4 fopDwTg_Init(create_tag_class *param_1,void *param_2)

{
  SComponent::cTg_Create(param_1,param_2);
  return 1;
}


/* __stdcall fopDwTg_CreateQueue(void) */

void fopDwTg_CreateQueue(void)

{
  SComponent::cTr_Create(&g_fopDwTg_Queue,(node_list_class *)&lists_2178,1000);
  return;
}

