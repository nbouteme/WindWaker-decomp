#include <f_pc_create_iter.h>
#include <SComponent/c_tag_iter.h>
#include <SComponent/c_list_iter.h>
#include <f_pc_create_iter.h>


namespace f_pc_create_iter {

/* __stdcall fpcCtIt_Method(int *(void *,void *),
                            void *) */

void fpcCtIt_Method(undefined4 param_1,void *param_2)

{
  undefined4 local_8;
  void *local_4;
  
  local_8 = param_1;
  local_4 = param_2;
  SComponent::cLsIt_Method(&f_pc_create_tag::g_fpcCtTg_Queue,SComponent::cTgIt_MethodCall,&local_8);
  return;
}


/* __stdcall fpcCtIt_Judge(void * *(void *,void *),
                           void *) */

void fpcCtIt_Judge(undefined *param_1,void *param_2)

{
  undefined *local_8;
  void *local_4;
  
  local_8 = param_1;
  local_4 = param_2;
  SComponent::cLsIt_Judge(&f_pc_create_tag::g_fpcCtTg_Queue,SComponent::cTgIt_JudgeFilter,&local_8);
  return;
}


/* __stdcall fpcCtIt_filter_JudgeInLayer(create_tag *,
                                         fpcCtIt_jilprm_c *) */

undefined4 fpcCtIt_filter_JudgeInLayer(create_tag *param_1,uint *param_2)

{
  undefined4 uVar1;
  create_request *pcVar2;
  
  pcVar2 = (param_1->parent).mpTagData;
  if (pcVar2->mpLayer->mLayerID == *param_2) {
    uVar1 = (*(code *)param_2[1])(pcVar2->mpRes,param_2[2]);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __stdcall fpcCtIt_JudgeInLayer(unsigned int,
                                  void * *(void *,void *),
                                  void *) */

void fpcCtIt_JudgeInLayer
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = param_1;
  local_14 = param_2;
  local_10 = param_3;
  fpcCtIt_Judge(fpcCtIt_filter_JudgeInLayer,&local_18);
  return;
}

