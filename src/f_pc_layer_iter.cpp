#include <f_pc_layer_iter.h>
#include <SComponent/c_tag_iter.h>
#include <SComponent/c_tree_iter.h>
#include <f_pc_layer.h>
#include <f_pc_layer_iter.h>


namespace f_pc_layer_iter {

/* __stdcall fpcLyIt_OnlyHere(layer_class *,
                              int *(void *,void *),
                              void *) */

void fpcLyIt_OnlyHere(layer_class *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = param_2;
  local_4 = param_3;
  SComponent::cTrIt_Method(&param_1->mNodeListTree,SComponent::cTgIt_MethodCall,&local_8);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fpcLyIt_OnlyHereLY(layer_class *,
                                int *(void *,void *),
                                void *) */

layer_class *
fpcLyIt_OnlyHereLY(layer_class *param_1,undefined4 param_2,undefined4 param_3)

{
  layer_class *plVar1;
  
  plVar1 = f_pc_layer::fpcLy_CurrentLayer();
  f_pc_layer::fpcLy_SetCurrentLayer(param_1);
  fpcLyIt_OnlyHere(param_1,param_2,param_3);
  f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
  return param_1;
}


/* __stdcall fpcLyIt_Judge(layer_class *,
                           void * *(void *,void *),
                           void *) */

void fpcLyIt_Judge(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = param_2;
  local_4 = param_3;
  SComponent::cTrIt_Judge
            ((node_lists_tree_class *)(param_1 + 0x10),SComponent::cTgIt_JudgeFilter,&local_8);
  return;
}


/* __stdcall fpcLyIt_AllJudge(void * *(void *,void *),
                              void *) */

void * fpcLyIt_AllJudge(undefined *param_1,void *param_2)

{
  layer_class *plVar1;
  void *pvVar2;
  undefined *local_18;
  void *local_14;
  
  local_18 = param_1;
  local_14 = param_2;
  plVar1 = f_pc_layer::fpcLy_RootLayer();
  while( true ) {
    if (plVar1 == (layer_class *)0x0) {
      return (void *)0x0;
    }
    pvVar2 = SComponent::cTrIt_Judge(&plVar1->mNodeListTree,SComponent::cTgIt_JudgeFilter,&local_18)
    ;
    if (pvVar2 != (void *)0x0) break;
    plVar1 = (layer_class *)(plVar1->parent).mpNextNode;
  }
  return pvVar2;
}

