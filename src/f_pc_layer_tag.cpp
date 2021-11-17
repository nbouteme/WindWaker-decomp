#include <f_pc_layer_tag.h>
#include <f_pc_layer.h>
#include <f_pc_layer_tag.h>
#include <SComponent/c_tag.h>


namespace f_pc_layer_tag {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fpcLyTg_ToQueue(layer_management_tag_class *,
                             unsigned int,
                             unsigned short,
                             unsigned short) */

undefined4
fpcLyTg_ToQueue
          (layer_management_tag_class *param_1,uint layerID,ushort param_3,ushort param_4)

{
  layer_class *plVar1;
  
  if ((param_1->mpLayer != (layer_class *)0x0) || (layerID != 0xffffffff)) {
    if ((layerID != 0xffffffff) &&
       ((layerID != 0xfffffffd && (param_1->mpLayer->mLayerID != layerID)))) {
      plVar1 = f_pc_layer::fpcLy_Layer(layerID);
      param_1->mpLayer = plVar1;
    }
    if ((layerID == 0xffffffff) || (layerID == 0xfffffffd)) {
      plVar1 = param_1->mpLayer;
      f_pc_layer::fpcLy_ToQueue(plVar1,(uint)param_3,&param_1->parent);
      if (plVar1 != (layer_class *)0x0) {
        param_1->mNodeListID = param_3;
        param_1->mNodeListIdx = (short)plVar1 + -1;
        return 1;
      }
    }
    else {
      plVar1 = param_1->mpLayer;
      f_pc_layer::fpcLy_IntoQueue(plVar1,(uint)param_3,&param_1->parent,(uint)param_4);
      if (plVar1 != (layer_class *)0x0) {
        param_1->mNodeListID = param_3;
        param_1->mNodeListIdx = param_4;
        return 1;
      }
    }
  }
  return 0;
}


/* __stdcall fpcLyTg_QueueTo(layer_management_tag_class *) */

bool fpcLyTg_QueueTo(layer_management_tag_class *param_1)

{
  layer_class *plVar1;
  
  plVar1 = param_1->mpLayer;
  f_pc_layer::fpcLy_QueueTo(plVar1,&param_1->parent);
  if (plVar1 == (layer_class *)&DAT_00000001) {
    param_1->mpLayer = (layer_class *)0x0;
    param_1->mNodeListID = -1;
    param_1->mNodeListIdx = -1;
  }
  return plVar1 == (layer_class *)&DAT_00000001;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fpcLyTg_Move(layer_management_tag_class *,
                          unsigned int,
                          unsigned short,
                          unsigned short) */

undefined4
fpcLyTg_Move
          (layer_management_tag_class *param_1,uint param_2,ushort param_3,ushort param_4)

{
  layer_class *plVar1;
  undefined4 uVar2;
  int iVar3;
  
  plVar1 = f_pc_layer::fpcLy_Layer(param_2);
  if (plVar1 == (layer_class *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar3 = fpcLyTg_QueueTo(param_1);
    if (iVar3 == 1) {
      param_1->mpLayer = plVar1;
      uVar2 = fpcLyTg_ToQueue(param_1,param_2,param_3,param_4);
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


/* __stdcall fpcLyTg_Init(layer_management_tag_class *,
                          unsigned int,
                          void *) */

uint fpcLyTg_Init(layer_management_tag_class *param_1,uint layerID,void *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  layer_class *plVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  iVar7 = 2;
  puVar1 = (undefined4 *)0x803726fc;
  puVar2 = (undefined4 *)&param_1[-1].mNodeListID;
  do {
    puVar6 = puVar2;
    puVar5 = puVar1;
    uVar3 = puVar5[2];
    puVar6[1] = puVar5[1];
    puVar6[2] = uVar3;
    iVar7 = iVar7 + -1;
    puVar1 = puVar5 + 2;
    puVar2 = puVar6 + 2;
  } while (iVar7 != 0);
  puVar6[3] = puVar5[3];
  param_1->mpLayer = crear_2201.mpLayer;
  param_1->mNodeListID = crear_2201.mNodeListID;
  param_1->mNodeListIdx = crear_2201.mNodeListIdx;
  SComponent::cTg_Create(&param_1->parent,param_3);
  plVar4 = f_pc_layer::fpcLy_Layer(layerID);
  if (plVar4 != (layer_class *)0x0) {
    param_1->mpLayer = plVar4;
  }
  return (uint)(plVar4 != (layer_class *)0x0);
}

