#include <f_pc_method_tag.h>
#include <SComponent/c_tag.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace f_pc_method_tag {

/* __stdcall fpcMtdTg_Do(process_method_tag_class *) */

void fpcMtdTg_Do(process_method_tag_class *param_1)

{
  (*(code *)param_1->mpFunc)(param_1->mpUserData);
  return;
}


/* __stdcall fpcMtdTg_ToMethodQ(node_list_class *,
                                process_method_tag_class *) */

int fpcMtdTg_ToMethodQ(node_list_class *param_1,create_tag_class *param_2)

{
  int iVar1;
  
  iVar1 = SComponent::cTg_Addition(param_1,param_2);
  return iVar1;
}


/* __stdcall fpcMtdTg_MethodQTo(process_method_tag_class *) */

void fpcMtdTg_MethodQTo(create_tag_class *param_1)

{
  SComponent::cTg_SingleCut(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fpcMtdTg_Init(process_method_tag_class *,
                           int *(void *),
                           void *) */

int fpcMtdTg_Init(process_method_tag_class *param_1,void *param_2,void *param_3)

{
  SComponent::cTg_Create(&param_1->parent,param_1);
  param_1->mpFunc = (undefined *)param_2;
  param_1->mpUserData = (undefined *)param_3;
  return 1;
}

