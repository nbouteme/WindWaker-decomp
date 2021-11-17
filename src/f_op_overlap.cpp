#include <f_op_overlap.h>
#include <f_pc_leaf.h>
#include <f_pc_method.h>
#include <SComponent/c_request.h>


namespace f_op_overlap {

/* __stdcall fopOvlp_Draw(void *) */

void fopOvlp_Draw(int param_1)

{
  f_pc_leaf::fpcLf_DrawMethod(*(void **)(param_1 + 0xc0),param_1);
  return;
}


/* __stdcall fopOvlp_Execute(void *) */

void fopOvlp_Execute(void *param_1)

{
  f_pc_method::fpcMtd_Execute(*(profile_method_class **)((int)param_1 + 0xc0),param_1);
  return;
}


/* __stdcall fopOvlp_IsDelete(void *) */

void fopOvlp_IsDelete(void *param_1)

{
  f_pc_method::fpcMtd_IsDelete(*(profile_method_class **)((int)param_1 + 0xc0),param_1);
  return;
}


/* __stdcall fopOvlp_Delete(void *) */

void fopOvlp_Delete(void *param_1)

{
  f_pc_method::fpcMtd_Delete(*(profile_leaf_method_class **)((int)param_1 + 0xc0),param_1);
  return;
}


/* __stdcall fopOvlp_Create(void *) */

void fopOvlp_Create(void *param_1)

{
  int iVar1;
  
  if (*(char *)((int)param_1 + 0xc) == '\0') {
    iVar1 = *(int *)((int)param_1 + 0x10);
    SComponent::cReq_Create((request_base_class *)((int)param_1 + 0xc4),1);
    *(undefined4 *)((int)param_1 + 0xc0) = *(undefined4 *)(iVar1 + 0x24);
    *(undefined4 *)((int)param_1 + 200) = 0xffffffff;
  }
  f_pc_method::fpcMtd_Create(*(profile_leaf_method_class **)((int)param_1 + 0xc0),param_1);
  return;
}

