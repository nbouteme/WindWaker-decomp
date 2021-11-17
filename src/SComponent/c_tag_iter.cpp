#include <SComponent/c_tag_iter.h>


namespace SComponent {

/* __stdcall cTgIt_MethodCall(create_tag_class *,
                              method_filter *) */

int cTgIt_MethodCall(create_tag_class *param_1,undefined *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)param_2)(param_1->mpTagData,*(undefined4 *)(param_2 + 4));
  return iVar1;
}


/* __stdcall cTgIt_JudgeFilter(create_tag_class *,
                               judge_filter *) */

void cTgIt_JudgeFilter(create_tag_class *param_1,code **param_2)

{
  (**param_2)(param_1->mpTagData,param_2[1]);
  return;
}

