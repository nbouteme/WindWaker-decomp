#include <f_pc_method.h>
#include <f_pc_method.h>


namespace f_pc_method {

/* __stdcall fpcMtd_Method(int *(void *),
                           void *) */

int fpcMtd_Method(undefined *param_1,void *param_2)

{
  int iVar1;
  
  if (param_1 == (undefined *)0x0) {
    iVar1 = 1;
  }
  else {
    iVar1 = (*(code *)param_1)(param_2);
  }
  return iVar1;
}


/* __stdcall fpcMtd_Execute(process_method_class *,
                            void *) */

void fpcMtd_Execute(profile_method_class *param_1,void *param_2)

{
  fpcMtd_Method((param_1->parent).mpExecute,param_2);
  return;
}


/* __stdcall fpcMtd_IsDelete(process_method_class *,
                             void *) */

int fpcMtd_IsDelete(profile_method_class *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = fpcMtd_Method((param_1->parent).mpIsDelete,param_2);
  return iVar1;
}


/* __stdcall fpcMtd_Delete(process_method_class *,
                           void *) */

int fpcMtd_Delete(profile_leaf_method_class *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = fpcMtd_Method(param_1->mpDelete,param_2);
  return iVar1;
}


/* __stdcall fpcMtd_Create(process_method_class *,
                           void *) */

int fpcMtd_Create(profile_leaf_method_class *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = fpcMtd_Method(param_1->mpCreate,param_2);
  return iVar1;
}

