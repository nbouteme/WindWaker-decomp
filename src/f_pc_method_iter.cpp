#include <f_pc_method_iter.h>
#include <SComponent/c_list_iter.h>


namespace f_pc_method_iter {

/* __stdcall fpcMtdIt_Method(node_list_class *,
                             int *(void *)) */

void fpcMtdIt_Method(node_list_class *param_1,undefined4 param_2)

{
  SComponent::cLsIt_Method(param_1,param_2,0);
  return;
}

