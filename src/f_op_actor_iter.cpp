#include <f_op_actor_iter.h>
#include <SComponent/c_tag_iter.h>
#include <SComponent/c_list_iter.h>


namespace f_op_actor_iter {

/* __stdcall fopAcIt_Executor(int *(void *,void *),
                              void *) */

void fopAcIt_Executor(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = param_1;
  local_4 = param_2;
  SComponent::cLsIt_Method(&f_op_actor_tag::g_fopAcTg_Queue,SComponent::cTgIt_MethodCall,&local_8);
  return;
}


/* __stdcall fopAcIt_Judge(void * *(void *,void *),
                           void *) */

fopAc_ac_c * fopAcIt_Judge(undefined *param_1,void *param_2)

{
  fopAc_ac_c *pfVar1;
  undefined *local_8;
  void *local_4;
  
  local_8 = param_1;
  local_4 = param_2;
  pfVar1 = (fopAc_ac_c *)
           SComponent::cLsIt_Judge
                     (&f_op_actor_tag::g_fopAcTg_Queue,SComponent::cTgIt_JudgeFilter,&local_8);
  return pfVar1;
}

