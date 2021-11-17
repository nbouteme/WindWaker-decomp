#include <f_pc_layer.h>
#include <f_pc_method_tag.h>
#include <SComponent/c_tag.h>
#include <f_pc_layer.h>
#include <SComponent/c_list.h>
#include <f_pc_method_iter.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_node.h>
#include <SComponent/c_tree.h>


namespace f_pc_layer {
undefined4 l_fpcLy_CurrLayer_p;
undefined4 IsInitOfLayerList$2270;
undefined1 init$2271;
undefined4 layer_id$2273;
undefined1 init$2274;

/* __stdcall fpcLy_CancelQTo(process_method_tag_class *) */

void fpcLy_CancelQTo(create_tag_class *param_1)

{
  f_pc_method_tag::fpcMtdTg_MethodQTo(param_1);
  return;
}


/* __stdcall fpcLy_ToCancelQ(layer_class *,
                             process_method_tag_class *) */

int fpcLy_ToCancelQ(layer_class *param_1,process_method_tag_class *param_2)

{
  int iVar1;
  
  iVar1 = f_pc_method_tag::fpcMtdTg_ToMethodQ(&param_1->mCancelList,&param_2->parent);
  return iVar1;
}


/* __stdcall fpcLy_CancelMethod(process_method_tag_class *) */

uint fpcLy_CancelMethod(process_method_tag_class *param_1)

{
  uint uVar1;
  
  f_pc_method_tag::fpcMtdTg_Do(param_1);
  uVar1 = countLeadingZeros(1 - (int)param_1);
  return uVar1 >> 5;
}


/* __stdcall fpcLy_IntoQueue(layer_class *,
                             int,
                             create_tag_class *,
                             int) */

void fpcLy_IntoQueue
               (layer_class *param_1,int param_2,create_tag_class *param_3,int param_4)

{
  SComponent::cTg_InsertToTree(&param_1->mNodeListTree,param_2,param_3,param_4);
  return;
}


/* __stdcall fpcLy_ToQueue(layer_class *,
                           int,
                           create_tag_class *) */

void fpcLy_ToQueue(layer_class *param_1,int param_2,create_tag_class *param_3)

{
  SComponent::cTg_AdditionToTree(&param_1->mNodeListTree,param_2,param_3);
  return;
}


/* __stdcall fpcLy_QueueTo(layer_class *,
                           create_tag_class *) */

void fpcLy_QueueTo(layer_class *param_1,create_tag_class *param_2)

{
  SComponent::cTg_SingleCutFromTree(param_2);
  return;
}


/* __stdcall fpcLy_IsDeletingMesg(layer_class *) */

uint fpcLy_IsDeletingMesg(layer_class *param_1)

{
  return (uint)(-(int)param_1->mDeletingCount & ~(int)param_1->mDeletingCount) >> 0x1f;
}


/* __stdcall fpcLy_DeletingMesg(layer_class *) */

void fpcLy_DeletingMesg(layer_class *param_1)

{
  param_1->mDeletingCount = param_1->mDeletingCount + 1;
  return;
}


/* __stdcall fpcLy_DeletedMesg(layer_class *) */

void fpcLy_DeletedMesg(layer_class *param_1)

{
  if (param_1->mDeletingCount < 1) {
    return;
  }
  param_1->mDeletingCount = param_1->mDeletingCount + -1;
  return;
}


/* __stdcall fpcLy_IsCreatingMesg(layer_class *) */

uint fpcLy_IsCreatingMesg(layer_class *param_1)

{
  return (uint)(-(int)param_1->mCreatingCount & ~(int)param_1->mCreatingCount) >> 0x1f;
}


/* __stdcall fpcLy_CreatingMesg(layer_class *) */

void fpcLy_CreatingMesg(layer_class *param_1)

{
  param_1->mCreatingCount = param_1->mCreatingCount + 1;
  return;
}


/* __stdcall fpcLy_CreatedMesg(layer_class *) */

void fpcLy_CreatedMesg(layer_class *param_1)

{
  if (param_1->mCreatingCount < 1) {
    return;
  }
  param_1->mCreatingCount = param_1->mCreatingCount + -1;
  return;
}


/* __stdcall fpcLy_RootLayer(void) */

layer_class * fpcLy_RootLayer(void)

{
  return (layer_class *)l_fpcLy_LayerList.mpHead;
}


/* __stdcall fpcLy_SetCurrentLayer(layer_class *) */

void fpcLy_SetCurrentLayer(layer_class *param_1)

{
  l_fpcLy_CurrLayer_p = param_1;
  return;
}


/* __stdcall fpcLy_CurrentLayer(void) */

layer_class * fpcLy_CurrentLayer(void)

{
  return l_fpcLy_CurrLayer_p;
}


/* __stdcall fpcLy_Search(unsigned int) */

layer_class * fpcLy_Search(uint param_1)

{
  layer_class *plVar1;
  
  plVar1 = fpcLy_RootLayer();
  while( true ) {
    if (plVar1 == (layer_class *)0x0) {
      return (layer_class *)0x0;
    }
    if (plVar1->mLayerID == param_1) break;
    plVar1 = (layer_class *)(plVar1->parent).mpNextNode;
  }
  return plVar1;
}


/* __stdcall fpcLy_Layer(unsigned int) */

layer_class * fpcLy_Layer(uint param_1)

{
  layer_class *plVar1;
  
  if ((param_1 == 0) || (plVar1 = fpcLy_RootLayer(), param_1 == plVar1->mLayerID)) {
    plVar1 = fpcLy_RootLayer();
  }
  else {
    if ((param_1 == 0xfffffffd) || (plVar1 = fpcLy_CurrentLayer(), param_1 == plVar1->mLayerID)) {
      plVar1 = fpcLy_CurrentLayer();
    }
    else {
      plVar1 = fpcLy_Search(param_1);
    }
  }
  return plVar1;
}


/* __stdcall fpcLy_Regist(layer_class *) */

void fpcLy_Regist(node_class *param_1)

{
  SComponent::cLs_Addition(&l_fpcLy_LayerList,param_1);
  return;
}


/* __stdcall fpcLy_Delete(layer_class *) */

undefined4 fpcLy_Delete(layer_class *pLayer)

{
  undefined *puVar1;
  int iVar2;
  node_class *pnVar3;
  undefined4 uVar4;
  
  if ((((pLayer->mNodeListTree).mpLists)->mSize == 0) && ((pLayer->mCancelList).mSize == 0)) {
    SComponent::cLs_SingleCut(&pLayer->parent);
    puVar1 = l_fpcLy_Crear.parent.mpData;
    (pLayer->parent).mpPrevNode = l_fpcLy_Crear.parent.mpPrevNode;
    (pLayer->parent).mpData = puVar1;
    (pLayer->parent).mpNextNode = l_fpcLy_Crear.parent.mpNextNode;
    pLayer->mLayerID = l_fpcLy_Crear.mLayerID;
    iVar2 = l_fpcLy_Crear.mNodeListTree.mNumLists;
    (pLayer->mNodeListTree).mpLists = l_fpcLy_Crear.mNodeListTree.mpLists;
    (pLayer->mNodeListTree).mNumLists = iVar2;
    pLayer->mpPcNode = l_fpcLy_Crear.mpPcNode;
    pnVar3 = l_fpcLy_Crear.mCancelList.mpTail;
    (pLayer->mCancelList).mpHead = l_fpcLy_Crear.mCancelList.mpHead;
    (pLayer->mCancelList).mpTail = pnVar3;
    (pLayer->mCancelList).mSize = l_fpcLy_Crear.mCancelList.mSize;
    *(undefined4 *)&pLayer->mCreatingCount = l_fpcLy_Crear._40_4_;
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* __stdcall fpcLy_Cancel(layer_class *) */

void fpcLy_Cancel(layer_class *param_1)

{
  f_pc_method_iter::fpcMtdIt_Method(&param_1->mCancelList,fpcLy_CancelMethod);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fpcLy_Create(layer_class *,
                          void *,
                          node_list_class *,
                          int) */

void fpcLy_Create
               (layer_class *pLayer,void *param_2,node_list_class *param_3,int param_4)

{
  undefined *puVar1;
  node_class *pnVar2;
  int iVar3;
  
  puVar1 = l_fpcLy_Crear.parent.mpData;
  if (init_2271 == '\0') {
    IsInitOfLayerList_2270 = 1;
    init_2271 = '\x01';
  }
  if (init_2274 == '\0') {
    layer_id_2273 = 0;
    init_2274 = '\x01';
  }
  (pLayer->parent).mpPrevNode = l_fpcLy_Crear.parent.mpPrevNode;
  (pLayer->parent).mpData = puVar1;
  (pLayer->parent).mpNextNode = l_fpcLy_Crear.parent.mpNextNode;
  pLayer->mLayerID = l_fpcLy_Crear.mLayerID;
  iVar3 = l_fpcLy_Crear.mNodeListTree.mNumLists;
  (pLayer->mNodeListTree).mpLists = l_fpcLy_Crear.mNodeListTree.mpLists;
  (pLayer->mNodeListTree).mNumLists = iVar3;
  pLayer->mpPcNode = l_fpcLy_Crear.mpPcNode;
  pnVar2 = l_fpcLy_Crear.mCancelList.mpTail;
  (pLayer->mCancelList).mpHead = l_fpcLy_Crear.mCancelList.mpHead;
  (pLayer->mCancelList).mpTail = pnVar2;
  (pLayer->mCancelList).mSize = l_fpcLy_Crear.mCancelList.mSize;
  *(undefined4 *)&pLayer->mCreatingCount = l_fpcLy_Crear._40_4_;
  SComponent::cNd_Create(&pLayer->parent,(void *)0x0);
  iVar3 = layer_id_2273 + 1;
  pLayer->mLayerID = layer_id_2273;
  layer_id_2273 = iVar3;
  pLayer->mpPcNode = (process_node_class *)param_2;
  if (IsInitOfLayerList_2270 == 1) {
    IsInitOfLayerList_2270 = 0;
    SComponent::cLs_Create(&l_fpcLy_LayerList);
    fpcLy_SetCurrentLayer(pLayer);
  }
  (pLayer->mNodeListTree).mpLists = param_3;
  (pLayer->mNodeListTree).mNumLists = param_4;
  SComponent::cTr_Create
            (&pLayer->mNodeListTree,(pLayer->mNodeListTree).mpLists,
             (pLayer->mNodeListTree).mNumLists);
  fpcLy_Regist(pLayer);
  return;
}

