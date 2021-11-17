#include <f_pc_stdcreate_req.h>
#include <f_pc_load.h>
#include <f_pc_layer.h>
#include <f_pc_base.h>
#include <SComponent/c_phase.h>
#include <f_pc_stdcreate_req.h>
#include <f_pc_create_req.h>


namespace f_pc_stdcreate_req {

/* __stdcall fpcSCtRq_phase_Load(standard_create_request_class *) */

undefined4 fpcSCtRq_phase_Load(standard_create_request_class *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = f_pc_load::fpcLd_Load(param_1->mProcName);
  if (iVar1 == 4) {
    uVar2 = 2;
  }
  else {
    if ((iVar1 < 4) && (iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 5;
    }
  }
  return uVar2;
}


/* __stdcall fpcSCtRq_phase_CreateProcess(standard_create_request_class *) */

undefined4 fpcSCtRq_phase_CreateProcess(standard_create_request_class *pReq)

{
  base_process_class *pBs;
  base_process_class *pBs_;
  undefined4 uVar1;
  char *pcVar2;
  
  f_pc_layer::fpcLy_SetCurrentLayer((pReq->parent).mpLayer);
  pcVar2 = (char *)(pReq->parent).mBsPcId;
  pBs = f_pc_base::fpcBs_Create(pReq->mProcName,(uint)pcVar2,pReq->mpUserData);
  (pReq->parent).mpRes = pBs;
  pBs_ = (pReq->parent).mpRes;
  if (pBs_ == (base_process_class *)0x0) {
    f_pc_load::fpcLd_Free(pReq->mProcName,pcVar2);
    uVar1 = 5;
  }
  else {
    pBs_->mpCtRq = &pReq->parent;
    uVar1 = 2;
  }
  return uVar1;
}


/* __stdcall fpcSCtRq_phase_SubCreateProcess(standard_create_request_class *) */

void fpcSCtRq_phase_SubCreateProcess(standard_create_request_class *param_1)

{
  f_pc_layer::fpcLy_SetCurrentLayer((param_1->parent).mpLayer);
  f_pc_base::fpcBs_SubCreate((param_1->parent).mpRes);
  return;
}


/* __stdcall fpcSCtRq_phase_IsComplete(standard_create_request_class *) */

int fpcSCtRq_phase_IsComplete(standard_create_request_class *param_1)

{
  bool bVar3;
  uint uVar1;
  int iVar2;
  base_process_class *pBs;
  
  pBs = (param_1->parent).mpRes;
  bVar3 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type,pBs->mSubType);
  if ((bVar3 == true) &&
     (uVar1 = f_pc_layer::fpcLy_IsCreatingMesg((layer_class *)&pBs[1].mBsPcId), uVar1 == 1)) {
    iVar2 = 0;
  }
  else {
    iVar2 = 2;
  }
  return iVar2;
}


/* __stdcall fpcSCtRq_phase_PostMethod(standard_create_request_class *) */

undefined4 fpcSCtRq_phase_PostMethod(standard_create_request_class *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((code *)param_1->mpCallback == (code *)0x0) ||
     (iVar1 = (*(code *)param_1->mpCallback)((param_1->parent).mpRes,param_1->mpCallbackUserData),
     iVar1 != 0)) {
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __stdcall fpcSCtRq_phase_Done(standard_create_request_class *) */

undefined4 fpcSCtRq_phase_Done(void)

{
  return 2;
}


/* __stdcall fpcSCtRq_Handler(standard_create_request_class *) */

void fpcSCtRq_Handler(standard_create_request_class *param_1)

{
  PhaseState PVar1;
  
  PVar1 = SComponent::cPhs_Do(&param_1->mPhase,param_1);
  if ((((PVar1 != 3) && ((int)PVar1 < 3)) && (PVar1 != 1)) && (0 < (int)PVar1)) {
    fpcSCtRq_Handler(param_1);
  }
  return;
}


/* __stdcall fpcSCtRq_Delete(standard_create_request_class *) */

undefined4 fpcSCtRq_Delete(void)

{
  return 1;
}


/* __stdcall fpcSCtRq_Cancel(standard_create_request_class *) */

undefined4 fpcSCtRq_Cancel(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fpcSCtRq_Request(layer_class *,
                              short,
                              int *(void *,void *),
                              void *,
                              void *) */

int fpcSCtRq_Request
              (layer_class *param_1,short param_2,undefined *param_3,void *param_4,void *param_5)

{
  int iVar1;
  standard_create_request_class *pReq;
  
  if (param_2 < 0x7fff) {
    pReq = (standard_create_request_class *)
           f_pc_create_req::fpcCtRq_Create(param_1,0x60,&submethod_2223);
    if (pReq == (standard_create_request_class *)0x0) {
      iVar1 = -1;
    }
    else {
      SComponent::cPhs_Set(&pReq->mPhase,&method_2224);
      pReq->mProcName = param_2;
      pReq->mpCallback = param_3;
      pReq->mpCallbackUserData = (undefined *)param_4;
      pReq->mpUserData = param_5;
      iVar1 = (pReq->parent).mBsPcId;
    }
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

