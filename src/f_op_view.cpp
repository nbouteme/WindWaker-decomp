#include <f_op_view.h>
#include <f_pc_leaf.h>
#include <f_pc_method.h>


namespace f_op_view {

/* __stdcall fopVw_Draw(view_class *) */

void fopVw_Draw(int param_1)

{
  f_pc_leaf::fpcLf_DrawMethod(*(void **)(param_1 + 0xc0),param_1);
  return;
}


/* __stdcall fopVw_Execute(view_class *) */

void fopVw_Execute(view_class *param_1)

{
  f_pc_method::fpcMtd_Execute((profile_method_class *)param_1->mpMtd,param_1);
  return;
}


/* __stdcall fopVw_IsDelete(void *) */

void fopVw_IsDelete(void *param_1)

{
  f_pc_method::fpcMtd_IsDelete(*(profile_method_class **)((int)param_1 + 0xc0),param_1);
  return;
}


/* __stdcall fopVw_Delete(view_class *) */

void fopVw_Delete(view_class *param_1)

{
  f_pc_method::fpcMtd_Delete(param_1->mpMtd,param_1);
  return;
}


/* __stdcall fopVw_Create(void *) */

void fopVw_Create(view_class *param_1)

{
  f_pc_profile__Profile_Actor *pfVar1;
  
  pfVar1 = (param_1->parent).mpProf;
  param_1->mpMtd = &pfVar1->mpMtd2->parent;
  *(undefined *)&param_1->field_0xc4 = *(undefined *)&pfVar1->mStatus;
  f_pc_method::fpcMtd_Create(param_1->mpMtd,param_1);
  return;
}

