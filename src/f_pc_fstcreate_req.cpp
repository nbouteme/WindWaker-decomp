#include <f_pc_fstcreate_req.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <f_pc_load.h>
#include <f_pc_create_req.h>
#include <f_pc_layer.h>
#include <f_pc_base.h>


namespace f_pc_fstcreate_req {

/* __stdcall fpcFCtRq_Do(fast_create_request *) */

undefined4 fpcFCtRq_Do(fast_create_request *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((code *)param_1->mpCallback == (code *)0x0) ||
     (iVar1 = (*(code *)param_1->mpCallback)((param_1->parent).mpRes,param_1->mpUserData),
     iVar1 != 0)) {
    uVar2 = 4;
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}


/* __stdcall fpcFCtRq_Delete(fast_create_request *) */

undefined4 fpcFCtRq_Delete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fpcFCtRq_Request(layer_class *,
                              short,
                              int *(void *,void *),
                              void *,
                              void *) */

void * fpcFCtRq_Request
                 (layer_class *param_1,short param_2,undefined *param_3,void *param_4,void *param_5)

{
  int iVar1;
  fast_create_request *pRq;
  uint uVar2;
  base_process_class *pbVar3;
  
  iVar1 = f_pc_load::fpcLd_Use(param_2);
  if ((iVar1 != 0) &&
     (pRq = (fast_create_request *)
            f_pc_create_req::fpcCtRq_Create
                      (param_1,0x50,(create_request_method_class *)&submethod_2176),
     pRq != (fast_create_request *)0x0)) {
    f_pc_layer::fpcLy_SetCurrentLayer(param_1);
    uVar2 = f_pc_base::fpcBs_MakeOfId();
    pbVar3 = f_pc_base::fpcBs_Create(param_2,uVar2,param_5);
    if (pbVar3 != (base_process_class *)0x0) {
      pbVar3->mpCtRq = (create_request *)pRq;
      (pRq->parent).mpRes = pbVar3;
      (pRq->parent).mBsPcId = pbVar3->mBsPcId;
      iVar1 = f_pc_base::fpcBs_SubCreate(pbVar3);
      if (iVar1 == 2) {
        pRq->mpCallback = param_3;
        pRq->mpUserData = (undefined *)param_4;
        return pbVar3;
      }
    }
    f_pc_create_req::fpcCtRq_Cancel((create_request *)pRq);
  }
  return (base_process_class *)0x0;
}

