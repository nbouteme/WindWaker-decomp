#include <f_pc_draw.h>
#include <f_pc_pause.h>
#include <f_pc_layer.h>
#include <f_pc_base.h>
#include <SComponent/c_API_graphic.h>


namespace f_pc_draw {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fpcDw_Execute(base_process_class *) */

int fpcDw_Execute(base_process_class *param_1)

{
  int iVar1;
  layer_class *plVar2;
  bool bVar3;
  fpcMtd__Method *pfVar4;
  
  iVar1 = f_pc_pause::fpcPause_IsEnable(param_1,2);
  if (iVar1 == 0) {
    plVar2 = f_pc_layer::fpcLy_CurrentLayer();
    bVar3 = f_pc_base::fpcBs_Is_JustOfType(f_pc_leaf::g_fpcLf_type,param_1->mSubType);
    if (bVar3 == false) {
      pfVar4 = (param_1->mpPcMtd->parent).mpDraw;
    }
    else {
      pfVar4 = (param_1->mpPcMtd->parent).mpDraw;
    }
    f_pc_layer::fpcLy_SetCurrentLayer((param_1->mLyTg).mpLayer);
    iVar1 = (*pfVar4)(param_1);
    f_pc_layer::fpcLy_SetCurrentLayer(plVar2);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


/* __stdcall fpcDw_Handler(int *(int *(void *,void *)),
                           int *(void *,void *)) */

undefined4 fpcDw_Handler(code *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  SComponent::cAPIGph_BeforeOfDraw();
  uVar1 = (*param_1)(param_2);
  SComponent::cAPIGph_AfterOfDraw();
  return uVar1;
}

