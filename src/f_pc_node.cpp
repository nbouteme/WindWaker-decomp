#include <f_pc_node.h>
#include <f_pc_method.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <f_pc_layer.h>
#include <f_pc_node.h>
#include <f_pc_base.h>
#include <f_pc_layer_iter.h>


namespace f_pc_node {
undefined4 g_fpcNd_type;

/* __stdcall fpcNd_DrawMethod(nodedraw_method_class *,
                              void *) */

void fpcNd_DrawMethod(int param_1,void *param_2)

{
  f_pc_method::fpcMtd_Method(*(undefined **)(param_1 + 0x10),param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fpcNd_Draw(process_node_class *) */

undefined4 fpcNd_Draw(process_node_class *param_1)

{
  layer_class *plVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1->field_0x1a8 == 0) {
    plVar1 = f_pc_layer::fpcLy_CurrentLayer();
    f_pc_layer::fpcLy_SetCurrentLayer(&param_1->mLayer);
    uVar2 = fpcNd_DrawMethod(param_1->mpMtd,param_1);
    f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
  }
  return uVar2;
}


/* __stdcall fpcNd_Execute(process_node_class *) */

profile_method_class * fpcNd_Execute(void *param_1)

{
  layer_class *plVar1;
  profile_method_class *ppVar2;
  
  plVar1 = f_pc_layer::fpcLy_CurrentLayer();
  f_pc_layer::fpcLy_SetCurrentLayer((layer_class *)((int)param_1 + 0xbc));
  ppVar2 = *(profile_method_class **)((int)param_1 + 0xb8);
  f_pc_method::fpcMtd_Execute(ppVar2,param_1);
  f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
  return ppVar2;
}


/* __stdcall fpcNd_IsCreatingFromUnder(void *) */

void * fpcNd_IsCreatingFromUnder(void *param_1)

{
  bool bVar2;
  uint uVar1;
  
  if ((param_1 == (void *)0x0) ||
     (bVar2 = f_pc_base::fpcBs_Is_JustOfType(g_fpcNd_type,*(int *)((int)param_1 + 0xb4)),
     bVar2 == false)) {
    param_1 = (void *)0x0;
  }
  else {
    uVar1 = f_pc_layer::fpcLy_IsCreatingMesg((layer_class *)((int)param_1 + 0xbc));
    if (uVar1 == 0) {
      param_1 = (void *)f_pc_layer_iter::fpcLyIt_Judge
                                  ((layer_class *)((int)param_1 + 0xbc),fpcNd_IsCreatingFromUnder,0)
      ;
    }
  }
  return param_1;
}


/* __stdcall fpcNd_IsDeleteTiming(process_node_class *) */

undefined4 fpcNd_IsDeleteTiming(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((g_fpcNd_IsCheckOfDeleteTiming == 1) &&
     (iVar1 = fpcNd_IsCreatingFromUnder(param_1), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* __stdcall fpcNd_IsDelete(process_node_class *) */

void fpcNd_IsDelete(process_node_class *param_1)

{
  f_pc_method::fpcMtd_IsDelete(param_1->mpMtd,param_1);
  return;
}


/* __stdcall fpcNd_Delete(process_node_class *) */

undefined4 fpcNd_Delete(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = f_pc_layer::fpcLy_IsDeletingMesg((layer_class *)((int)param_1 + 0xbc));
  if ((iVar1 == 0) &&
     (iVar1 = f_pc_method::fpcMtd_Delete
                        (*(profile_leaf_method_class **)((int)param_1 + 0xb8),param_1), iVar1 == 1))
  {
    *(undefined4 *)((int)param_1 + 0xb4) = 0;
    uVar2 = f_pc_layer::fpcLy_Delete((layer_class *)((int)param_1 + 0xbc));
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __stdcall fpcNd_Create(process_node_class *) */

int fpcNd_Create(process_node_class *param_1)

{
  int iVar1;
  layer_class *plVar2;
  f_pc_profile__Profile_Actor *pfVar3;
  
  if ((param_1->parent).mInitState == 0) {
    pfVar3 = (param_1->parent).mpProf;
    iVar1 = f_pc_base::fpcBs_MakeOfType(&g_fpcNd_type);
    (param_1->parent).mSubType = iVar1;
    param_1->mpMtd = (pfVar3->parent).mpMtd1;
    f_pc_layer::fpcLy_Create(&param_1->mLayer,param_1,param_1->mLayerNodeLists,0x10);
    param_1->field_0x1a8 = 0;
  }
  plVar2 = f_pc_layer::fpcLy_CurrentLayer();
  f_pc_layer::fpcLy_SetCurrentLayer(&param_1->mLayer);
  iVar1 = f_pc_method::fpcMtd_Create(&param_1->mpMtd->parent,param_1);
  f_pc_layer::fpcLy_SetCurrentLayer(plVar2);
  return iVar1;
}

