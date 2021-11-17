#include <f_pc_leaf.h>
#include <f_pc_draw_priority.h>
#include <f_pc_method.h>
#include <f_pc_leaf.h>
#include <f_pc_base.h>


namespace f_pc_leaf {
undefined4 g_fpcLf_type;

/* __stdcall fpcLf_GetPriority(leafdraw_class *) */

int fpcLf_GetPriority(leafdraw_class *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_draw_priority::fpcDwPi_Get(&param_1->mDwPi);
  return iVar1;
}


/* __stdcall fpcLf_DrawMethod(leafdraw_method_class *,
                              void *) */

void fpcLf_DrawMethod(void *param_1,void *param_2)

{
  f_pc_method::fpcMtd_Method(*(undefined **)((int)param_1 + 0x10),param_2);
  return;
}


/* __stdcall fpcLf_Draw(leafdraw_class *) */

undefined4 fpcLf_Draw(leafdraw_class *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1->field_0xbc == 0) {
    uVar1 = fpcLf_DrawMethod(param_1->mpSubMtd,param_1);
  }
  return uVar1;
}


/* __stdcall fpcLf_Execute(leafdraw_class *) */

void fpcLf_Execute(leafdraw_class *param_1)

{
  f_pc_method::fpcMtd_Execute((profile_method_class *)param_1->mpSubMtd,param_1);
  return;
}


/* __stdcall fpcLf_IsDelete(leafdraw_class *) */

void fpcLf_IsDelete(leafdraw_class *param_1)

{
  f_pc_method::fpcMtd_IsDelete((profile_method_class *)param_1->mpSubMtd,param_1);
  return;
}


/* __stdcall fpcLf_Delete(leafdraw_class *) */

void fpcLf_Delete(leafdraw_class *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_method::fpcMtd_Delete(param_1->mpSubMtd,param_1);
  if (iVar1 == 1) {
    (param_1->parent).mSubType = 0;
  }
  return;
}


/* __stdcall fpcLf_Create(leafdraw_class *) */

void fpcLf_Create(leafdraw_class *param_1)

{
  int iVar1;
  f_pc_profile__Profile_Actor *pfVar2;
  
  if ((param_1->parent).mInitState == 0) {
    pfVar2 = (param_1->parent).mpProf;
    param_1->mpSubMtd = &((pfVar2->parent).mpMtd1)->parent;
    iVar1 = f_pc_base::fpcBs_MakeOfType(&g_fpcLf_type);
    (param_1->parent).mSubType = iVar1;
    f_pc_draw_priority::fpcDwPi_Init(&param_1->mDwPi,pfVar2->mDrawPriority);
    param_1->field_0xbc = 0;
  }
  f_pc_method::fpcMtd_Create(param_1->mpSubMtd,param_1);
  return;
}

