#include <f_pc_create_req.h>
#include <f_pc_create_req.h>
#include <f_pc_create_iter.h>
#include <f_pc_create_tag.h>
#include <f_pc_layer.h>
#include <f_pc_method.h>
#include <SComponent/c_malloc.h>
#include <f_pc_deletor.h>
#include <f_pc_executor.h>
#include <f_pc_method_tag.h>
#include <f_pc_base.h>


namespace f_pc_create_req {

/* __stdcall fpcCtRq_isCreatingByID(create_tag *,
                                    unsigned int *) */

uint fpcCtRq_isCreatingByID(create_tag *param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(*param_2 - ((param_1->parent).mpTagData)->mBsPcId);
  return uVar1 >> 5;
}


/* __stdcall fpcCtRq_IsCreatingByID(unsigned int) */

int fpcCtRq_IsCreatingByID(int param_1)

{
  int iVar1;
  int local_8 [2];
  
  local_8[0] = param_1;
  iVar1 = f_pc_create_iter::fpcCtIt_Judge(fpcCtRq_isCreatingByID,local_8);
  return (uint)(iVar1 != 0);
}


/* __stdcall fpcCtRq_CreateQTo(create_request *) */

void fpcCtRq_CreateQTo(create_request *param_1)

{
  f_pc_create_tag::fpcCtTg_CreateQTo(&param_1->parent);
  f_pc_layer::fpcLy_CreatedMesg(param_1->mpLayer);
  f_pc_layer::fpcLy_CancelQTo(&param_1->mMtdTg);
  return;
}


/* __stdcall fpcCtRq_ToCreateQ(create_request *) */

void fpcCtRq_ToCreateQ(create_request *param_1)

{
  f_pc_layer::fpcLy_CreatingMesg(param_1->mpLayer);
  f_pc_layer::fpcLy_ToCancelQ(param_1->mpLayer,&param_1->mMtdTg);
  f_pc_create_tag::fpcCtTg_ToCreateQ(&param_1->parent);
  return;
}


/* __stdcall fpcCtRq_Delete(create_request *) */

undefined4 fpcCtRq_Delete(create_request *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  fpcCtRq_CreateQTo(param_1);
  if ((param_1->mpCtRqMtd == (create_request_method_class *)0x0) ||
     (iVar1 = f_pc_method::fpcMtd_Method(param_1->mpCtRqMtd->mpDelete,param_1), iVar1 != 0)) {
    if (param_1->mpRes != (base_process_class *)0x0) {
      param_1->mpRes->mpCtRq = (create_request *)0x0;
    }
    cMl::free(param_1);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __stdcall fpcCtRq_Cancel(create_request *) */

undefined4 fpcCtRq_Cancel(create_request *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == (create_request *)0x0) || (param_1->field_0x15 != 0)) {
    uVar2 = 1;
  }
  else {
    param_1->field_0x15 = 1;
    if ((param_1->mpRes == (base_process_class *)0x0) ||
       (iVar1 = f_pc_deletor::fpcDt_Delete(param_1->mpRes), iVar1 != 0)) {
      if ((param_1->mpCtRqMtd == (create_request_method_class *)0x0) ||
         (iVar1 = f_pc_method::fpcMtd_Method(param_1->mpCtRqMtd->mpCancel,param_1), iVar1 != 0)) {
        uVar2 = fpcCtRq_Delete(param_1);
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


/* __stdcall fpcCtRq_IsDoing(create_request *) */

int fpcCtRq_IsDoing(create_request *param_1)

{
  if (param_1 != (create_request *)0x0) {
    return (int)(char)param_1->mbIsCreating;
  }
  return 0;
}


/* __stdcall fpcCtRq_Do(create_request *) */

undefined4 fpcCtRq_Do(create_request *param_1)

{
  bool bVar2;
  undefined4 uVar1;
  int iVar3;
  code *pcVar4;
  
  iVar3 = 4;
  if ((param_1->mpCtRqMtd != (create_request_method_class *)0x0) &&
     (pcVar4 = (code *)param_1->mpCtRqMtd->mpHandler, pcVar4 != (code *)0x0)) {
    param_1->mbIsCreating = 1;
    iVar3 = (*pcVar4)();
    param_1->mbIsCreating = 0;
  }
  if (iVar3 == 4) {
    bVar2 = f_pc_executor::fpcEx_ToExecuteQ(param_1->mpRes);
    if (bVar2 == false) {
      uVar1 = fpcCtRq_Cancel(param_1);
      return uVar1;
    }
    uVar1 = fpcCtRq_Delete(param_1);
    return uVar1;
  }
  if (iVar3 < 4) {
    if (2 < iVar3) {
LAB_8003cfa0:
      uVar1 = fpcCtRq_Cancel(param_1);
      return uVar1;
    }
  }
  else {
    if (iVar3 < 6) goto LAB_8003cfa0;
  }
  return 1;
}


/* __stdcall fpcCtRq_Handler(void) */

void fpcCtRq_Handler(void)

{
  f_pc_create_iter::fpcCtIt_Method(fpcCtRq_Do,(void *)0x0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fpcCtRq_Create(layer_class *,
                            unsigned long,
                            create_request_method_class *) */

create_request *
fpcCtRq_Create
          (layer_class *param_1,ulong size,create_request_method_class *param_3)

{
  create_request *pReq;
  int iVar1;
  
  pReq = (create_request *)cMl::memalignB(-4,size);
  if (pReq != (create_request *)0x0) {
    f_pc_create_tag::fpcCtTg_Init((create_tag *)pReq,pReq);
    f_pc_method_tag::fpcMtdTg_Init(&pReq->mMtdTg,fpcCtRq_Cancel,pReq);
    pReq->mpLayer = param_1;
    pReq->mpCtRqMtd = param_3;
    iVar1 = f_pc_base::fpcBs_MakeOfId();
    pReq->mBsPcId = iVar1;
    pReq->mpRes = (base_process_class *)0x0;
    pReq->field_0x15 = 0;
    fpcCtRq_ToCreateQ(pReq);
  }
  return pReq;
}

