#include <f_pc_base.h>
#include <f_pc_layer.h>
#include <f_pc_method.h>
#include <SComponent/c_malloc.h>
#include <f_pc_base.h>
#include <f_pc_profile.h>
#include <SStandard/s_basic.h>
#include <f_pc_layer_tag.h>
#include <f_pc_line_tag.h>
#include <f_pc_delete_tag.h>
#include <f_pc_priority.h>
#include <f_pc_pause.h>


namespace f_pc_base {
undefined g_fpcBs_type;
undefined4 t_type$2169;
bool init$2170;
undefined4 process_id$2178;
undefined1 init$2179;

/* __stdcall fpcBs_Is_JustOfType(int,
                                 int) */

bool fpcBs_Is_JustOfType(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(param_1 - param_2);
  return (bool)(char)(uVar1 >> 5);
}


/* __stdcall fpcBs_MakeOfType(int *) */

int fpcBs_MakeOfType(int *param_1)

{
  if (init_2170 == false) {
    t_type_2169 = 0x9130000;
    init_2170 = true;
  }
  if (*param_1 == 0) {
    t_type_2169 = t_type_2169 + 1;
    *param_1 = t_type_2169;
  }
  return *param_1;
}


/* __stdcall fpcBs_MakeOfId(void) */

int fpcBs_MakeOfId(void)

{
  int iVar1;
  
  if (init_2179 == '\0') {
    process_id_2178 = 1;
    init_2179 = '\x01';
  }
  iVar1 = process_id_2178;
  process_id_2178 = process_id_2178 + 1;
  return iVar1;
}


/* __stdcall fpcBs_Execute(base_process_class *) */

void fpcBs_Execute(base_process_class *param_1)

{
  layer_class *plVar1;
  
  plVar1 = f_pc_layer::fpcLy_CurrentLayer();
  f_pc_layer::fpcLy_SetCurrentLayer((param_1->mLyTg).mpLayer);
  f_pc_method::fpcMtd_Execute(param_1->mpPcMtd,param_1);
  f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
  return;
}


/* __stdcall fpcBs_DeleteAppend(base_process_class *) */

void fpcBs_DeleteAppend(base_process_class *param_1)

{
  if (param_1->mpUserData != (undefined *)0x0) {
    cMl::free(param_1->mpUserData);
    param_1->mpUserData = (undefined *)0x0;
  }
  return;
}


/* __stdcall fpcBs_IsDelete(base_process_class *) */

int fpcBs_IsDelete(base_process_class *param_1)

{
  layer_class *plVar1;
  int iVar2;
  
  plVar1 = f_pc_layer::fpcLy_CurrentLayer();
  f_pc_layer::fpcLy_SetCurrentLayer((param_1->mLyTg).mpLayer);
  iVar2 = f_pc_method::fpcMtd_IsDelete(param_1->mpPcMtd,param_1);
  f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
  return iVar2;
}


/* __stdcall fpcBs_Delete(base_process_class *) */

int fpcBs_Delete(base_process_class *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_method::fpcMtd_Delete(&param_1->mpPcMtd->parent,param_1);
  if (iVar1 == 1) {
    fpcBs_DeleteAppend(param_1);
    param_1->mBsType = 0;
    cMl::free(param_1);
  }
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fpcBs_Create(short,
                          unsigned int,
                          void *) */

base_process_class * fpcBs_Create(short param_1,uint param_2,void *param_3)

{
  f_pc_profile__Profile_Actor *pProf;
  base_process_class *pBs;
  uint uVar1;
  ulong uVar2;
  
  pProf = f_pc_profile::fpcPf_Get(param_1);
  uVar2 = (pProf->parent).mSize + (pProf->parent).mSizeOther;
  pBs = (base_process_class *)cMl::memalignB(-4,uVar2);
  if (pBs == (base_process_class *)0x0) {
    pBs = (base_process_class *)0x0;
  }
  else {
    SStandard::sBs_ClearArea(pBs,uVar2);
    f_pc_layer_tag::fpcLyTg_Init(&pBs->mLyTg,(pProf->parent).mLayerID,pBs);
    f_pc_line_tag::fpcLnTg_Init(&pBs->mLnTg,pBs);
    f_pc_delete_tag::fpcDtTg_Init(&pBs->mDtTg,pBs);
    f_pc_priority::fpcPi_Init
              (&pBs->mPi,pBs,(pProf->parent).mLayerID,(pProf->parent).mListID,
               (pProf->parent).mListPrio);
    pBs->mInitState = 0;
    pBs->field_0xa = 0;
    pBs->mBsPcId = param_2;
    pBs->mBsTypeId = param_1;
    uVar1 = fpcBs_MakeOfType((int *)&g_fpcBs_type);
    pBs->mBsType = uVar1;
    pBs->mProcName = (pProf->parent).mPName;
    f_pc_pause::fpcPause_Init(pBs);
    pBs->mpPcMtd = (profile_method_class *)(pProf->parent).mpMtd0;
    pBs->mpProf = pProf;
    pBs->mpUserData = (undefined *)param_3;
    pBs->mParameters = (pProf->parent).mDefaultParameters;
  }
  return pBs;
}


/* __stdcall fpcBs_SubCreate(base_process_class *) */

undefined4 fpcBs_SubCreate(base_process_class *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_method::fpcMtd_Create(&param_1->mpPcMtd->parent,param_1);
  if (iVar1 == 3) {
    param_1->field_0xd = 3;
    return 3;
  }
  if (iVar1 < 3) {
    if (1 < iVar1) {
LAB_8003cba8:
      fpcBs_DeleteAppend(param_1);
      param_1->field_0xd = 2;
      return 2;
    }
    if (-1 < iVar1) {
      param_1->mInitState = 1;
      param_1->field_0xd = 0;
      return 0;
    }
  }
  else {
    if ((iVar1 != 5) && (iVar1 < 5)) goto LAB_8003cba8;
  }
  param_1->field_0xd = 5;
  return 5;
}

