#include <f_pc_line_iter.h>
#include <f_pc_layer.h>
#include <SComponent/c_tag_iter.h>
#include <f_pc_line_iter.h>
#include <SComponent/c_tree_iter.h>


namespace f_pc_line_iter {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fpcLnIt_MethodCall(create_tag_class *,
                                method_filter *) */

int fpcLnIt_MethodCall(create_tag_class *param_1,undefined *param_2)

{
  layer_class *plVar1;
  int iVar2;
  layer_class *plVar3;
  
  plVar3 = (layer_class *)(param_1->mpTagData->mMtdTg).mpFunc;
  plVar1 = f_pc_layer::fpcLy_CurrentLayer();
  f_pc_layer::fpcLy_SetCurrentLayer(plVar3);
  iVar2 = SComponent::cTgIt_MethodCall(param_1,param_2);
  f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
  return iVar2;
}


/* __stdcall fpcLnIt_Queue(int *(void *,void *)) */

void fpcLnIt_Queue(undefined4 param_1)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0;
  local_8 = param_1;
  SComponent::cTrIt_Method(&f_pc_line::g_fpcLn_Queue,fpcLnIt_MethodCall,&local_8);
  return;
}

