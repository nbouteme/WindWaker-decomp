#include <f_pc_node_req.h>
#include <f_pc_layer.h>
#include <SComponent/c_tag.h>
#include <f_pc_create_req.h>
#include <f_pc_executor.h>
#include <f_pc_stdcreate_req.h>
#include <f_pc_deletor.h>
#include <SComponent/c_phase.h>
#include <f_pc_node_req.h>
#include <f_pc_method.h>
#include <SComponent/c_malloc.h>
#include <SStandard/s_basic.h>
#include <f_pc_method_tag.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace f_pc_node_req {
undefined4 request_id$2322;
undefined1 init$2323;

/* __stdcall fpcNdRq_RequestQTo(node_create_request *) */

void fpcNdRq_RequestQTo(create_tag_class *param_1)

{
  f_pc_layer::fpcLy_CreatedMesg((layer_class *)param_1[4].parent.mpPrevNode);
  f_pc_layer::fpcLy_CancelQTo(param_1 + 1);
  SComponent::cTg_SingleCut(param_1);
  return;
}


/* __stdcall fpcNdRq_ToRequestQ(node_create_request *) */

void fpcNdRq_ToRequestQ(node_create_request *param_1)

{
  SComponent::cTg_Addition(&l_fpcNdRq_Queue,&param_1->parent);
  f_pc_layer::fpcLy_ToCancelQ(param_1->mpLayer,&param_1->mpMtdTag);
  f_pc_layer::fpcLy_CreatingMesg(param_1->mpLayer);
  return;
}


/* __stdcall fpcNdRq_phase_IsCreated(node_create_request *) */

int fpcNdRq_phase_IsCreated(int param_1)

{
  int iVar1;
  
  iVar1 = f_pc_create_req::fpcCtRq_IsCreatingByID(*(int *)(param_1 + 0x54));
  if (iVar1 == 1) {
    iVar1 = 0;
  }
  else {
    iVar1 = f_pc_executor::fpcEx_IsExist(*(undefined4 *)(param_1 + 0x54));
    iVar1 = 3 - (uint)(iVar1 == 1);
  }
  return iVar1;
}


/* __stdcall fpcNdRq_phase_Create(node_create_request *) */

int fpcNdRq_phase_Create(node_create_request *param_1)

{
  uint uVar1;
  int id;
  
  id = f_pc_stdcreate_req::fpcSCtRq_Request
                 (param_1->mpLayer,param_1->mProcName,*(undefined **)(param_1->mpSubMtd + 0xc),
                  param_1,param_1->mpUserData);
  param_1->mRqId = id;
  uVar1 = countLeadingZeros(-1 - param_1->mRqId);
  return (uVar1 >> 5) + 2;
}


/* __stdcall fpcNdRq_phase_IsDeleteTiming(node_create_request *) */

undefined4 fpcNdRq_phase_IsDeleteTiming(void)

{
  return 2;
}


/* __stdcall fpcNdRq_phase_IsDeleted(node_create_request *) */

byte fpcNdRq_phase_IsDeleted(void)

{
  int iVar1;
  
  iVar1 = f_pc_deletor::fpcDt_IsComplete();
  return ~-(iVar1 == 0) & 2;
}


/* __stdcall fpcNdRq_phase_Delete(node_create_request *) */

undefined4 fpcNdRq_phase_Delete(int param_1)

{
  int iVar1;
  
  if (*(base_process_class **)(param_1 + 0x48) != (base_process_class *)0x0) {
    iVar1 = f_pc_deletor::fpcDt_Delete(*(base_process_class **)(param_1 + 0x48));
    if (iVar1 == 0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  return 2;
}


/* __stdcall fpcNdRq_DoPhase(node_create_request *) */

void fpcNdRq_DoPhase(node_create_request *param_1)

{
  int iVar1;
  
  iVar1 = SComponent::cPhs_Handler(&param_1->mPhs,param_1->mPhsHnd,param_1);
  if (iVar1 == 2) {
    fpcNdRq_DoPhase(param_1);
  }
  return;
}


/* __stdcall fpcNdRq_Execute(node_create_request *) */

int fpcNdRq_Execute(node_create_request *param_1)

{
  fpcNdRq_DoPhase(param_1);
  if (param_1 != (node_create_request *)&DAT_00000003) {
    if ((int)param_1 < 3) {
      if (1 < (int)param_1) {
        return (int)param_1;
      }
      if ((int)param_1 < 0) {
        return (int)param_1;
      }
      return (int)(node_create_request *)0x0;
    }
    if (param_1 != (node_create_request *)0x5) {
      if (4 < (int)param_1) {
        return (int)param_1;
      }
      return (int)(node_create_request *)&DAT_00000002;
    }
  }
  return (int)(node_create_request *)&DAT_00000003;
}


/* __stdcall fpcNdRq_Delete(node_create_request *) */

undefined4 fpcNdRq_Delete(node_create_request *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  fpcNdRq_RequestQTo();
  if (((param_1->mpSubMtd == (undefined *)0x0) ||
      (puVar1 = *(undefined **)(param_1->mpSubMtd + 8), puVar1 == (undefined *)0x0)) ||
     (iVar2 = f_pc_method::fpcMtd_Method(puVar1,param_1), iVar2 != 0)) {
    cMl::free(param_1);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* __stdcall fpcNdRq_Cancel(node_create_request *) */

undefined4 fpcNdRq_Cancel(node_create_request *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1->mpSubMtd == (undefined *)0x0) ||
     (iVar1 = f_pc_method::fpcMtd_Method(*(undefined **)(param_1->mpSubMtd + 4),param_1), iVar1 != 0
     )) {
    uVar2 = fpcNdRq_Delete(param_1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __stdcall fpcNdRq_Handler(void) */

undefined4 fpcNdRq_Handler(void)

{
  int iVar1;
  node_create_request *pnVar2;
  node_list_class *pNd;
  
  pNd = (node_list_class *)l_fpcNdRq_Queue.mpHead;
  do {
    while( true ) {
      while( true ) {
        if (pNd == (node_list_class *)0x0) {
          return 1;
        }
        pnVar2 = (node_create_request *)pNd[1].mpHead;
        iVar1 = (**(code **)pnVar2->mpSubMtd)(pnVar2);
        if (iVar1 != 4) break;
        if (pNd == (node_list_class *)0x0) {
          pNd = (node_list_class *)0x0;
        }
        else {
          pNd = (node_list_class *)pNd->mSize;
        }
        iVar1 = fpcNdRq_Delete(pnVar2);
        if (iVar1 == 0) {
          return 0;
        }
      }
      if (3 < iVar1) break;
      if (2 < iVar1) goto LAB_8003f62c;
LAB_8003f684:
      if (pNd == (node_list_class *)0x0) {
        pNd = (node_list_class *)0x0;
      }
      else {
        pNd = (node_list_class *)pNd->mSize;
      }
    }
    if (5 < iVar1) goto LAB_8003f684;
LAB_8003f62c:
    if (pNd == (node_list_class *)0x0) {
      pNd = (node_list_class *)0x0;
    }
    else {
      pNd = (node_list_class *)pNd->mSize;
    }
    iVar1 = fpcNdRq_Cancel(pnVar2);
    if (iVar1 == 0) {
      return 0;
    }
  } while( true );
}


/* WARNING: Type propagation algorithm not settling */
/* __stdcall fpcNdRq_IsPossibleTarget(process_node_class *) */

undefined4 fpcNdRq_IsPossibleTarget(process_node_class *param_1)

{
  base_process_class *pbVar1;
  node_create_request *pRq;
  create_request *pcVar2;
  
  pRq = (node_create_request *)l_fpcNdRq_Queue.mpHead;
  while( true ) {
    if (pRq == (node_create_request *)0x0) {
      return 1;
    }
    pcVar2 = (pRq->parent).mpTagData;
    pbVar1 = pcVar2->mpRes;
    if ((((pbVar1 == (base_process_class *)0x2) || (pbVar1 == (base_process_class *)0x4)) ||
        (pbVar1 == (base_process_class *)0x1)) &&
       (pcVar2[1].parent.parent.parent.mpData == (undefined *)(param_1->parent).mBsPcId)) break;
    if (pRq == (node_create_request *)0x0) {
      pRq = (node_create_request *)0x0;
    }
    else {
      pRq = (node_create_request *)(pRq->parent).parent.mpNextNode;
    }
  }
  return 0;
}


/* __stdcall fpcNdRq_IsIng(process_node_class *) */

undefined4 fpcNdRq_IsIng(process_node_class *param_1)

{
  node_create_request *pReq;
  
  pReq = (node_create_request *)l_fpcNdRq_Queue.mpHead;
  while( true ) {
    if (pReq == (node_create_request *)0x0) {
      return 0;
    }
    if ((pReq->parent).mpTagData[1].parent.parent.mpTagData ==
        (create_request *)(param_1->parent).mBsPcId) break;
    if (pReq == (node_create_request *)0x0) {
      pReq = (node_create_request *)0x0;
    }
    else {
      pReq = (node_create_request *)(pReq->parent).parent.mpNextNode;
    }
  }
  return 1;
}


/* __stdcall fpcNdRq_Create(unsigned long) */

node_create_request * fpcNdRq_Create(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined **ppuVar4;
  undefined *puVar5;
  undefined4 uVar6;
  node_create_request *pRq;
  int *piVar7;
  undefined4 *puVar8;
  undefined **ppuVar9;
  undefined4 *puVar10;
  int iVar11;
  
  pRq = (node_create_request *)cMl::memalignB(-4,param_1);
  if (pRq != (node_create_request *)0x0) {
    if (init_2323 == '\0') {
      request_id_2322 = (undefined *)0x0;
      init_2323 = '\x01';
    }
    SStandard::sBs_ClearArea(pRq,param_1);
    iVar11 = 2;
    piVar2 = &l_fpcNdRq_Queue.mSize;
    ppuVar4 = &pRq[-1].field_0x60;
    do {
      ppuVar9 = ppuVar4;
      piVar7 = piVar2;
      puVar5 = (undefined *)piVar7[2];
      ppuVar9[1] = (undefined *)piVar7[1];
      ppuVar9[2] = puVar5;
      iVar11 = iVar11 + -1;
      piVar2 = piVar7 + 2;
      ppuVar4 = ppuVar9 + 2;
    } while (iVar11 != 0);
    ppuVar9[3] = (undefined *)piVar7[3];
    iVar11 = 3;
    puVar1 = (undefined4 *)0x80372754;
    puVar3 = (undefined4 *)&(pRq->parent).mbAdded;
    do {
      puVar10 = puVar3;
      puVar8 = puVar1;
      uVar6 = puVar8[2];
      puVar10[1] = puVar8[1];
      puVar10[2] = uVar6;
      iVar11 = iVar11 + -1;
      puVar1 = puVar8 + 2;
      puVar3 = puVar10 + 2;
    } while (iVar11 != 0);
    puVar10[3] = puVar8[3];
    iVar11 = DAT_80372778;
    (pRq->mPhs).mpTbl = DAT_80372774;
    (pRq->mPhs).mStep = iVar11;
    pRq->mPhsHnd = DAT_8037277c;
    pRq->mpSubMtd = DAT_80372780;
    pRq->mArg = DAT_80372784;
    pRq->field_0x44 = DAT_80372788;
    iVar11 = DAT_80372790;
    pRq->mpNodeClass = DAT_8037278c;
    pRq->mBsPcId = iVar11;
    pRq->mpLayer = DAT_80372794;
    pRq->mRqId = DAT_80372798;
    pRq->mProcName = DAT_8037279c;
    pRq->mpUserData = DAT_803727a0;
    *(undefined2 *)&pRq->field_0x60 = DAT_803727a4;
    SComponent::cTg_Create((create_tag_class *)pRq,pRq);
    f_pc_method_tag::fpcMtdTg_Init(&pRq->mpMtdTag,fpcNdRq_Cancel,pRq);
    puVar5 = request_id_2322 + 1;
    pRq->field_0x44 = request_id_2322;
    request_id_2322 = puVar5;
  }
  return pRq;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fpcNdRq_ChangeNode(unsigned long,
                                process_node_class *,
                                short,
                                void *) */

node_create_request *
fpcNdRq_ChangeNode
          (ulong param_1,process_node_class *param_2,short param_3,void *param_4)

{
  int iVar1;
  node_create_request *pRq;
  
  iVar1 = fpcNdRq_IsPossibleTarget(param_2);
  if ((iVar1 == 1) && (iVar1 = fpcNdRq_IsIng(param_2), iVar1 == 0)) {
    pRq = fpcNdRq_Create(param_1);
    if (pRq != (node_create_request *)0x0) {
      pRq->mPhsHnd = (cPhs__Handler *)&methods_2338;
      pRq->mpNodeClass = param_2;
      pRq->mBsPcId = (param_2->parent).mBsPcId;
      pRq->mpLayer = (param_2->parent).mLyTg.mpLayer;
      pRq->mProcName = param_3;
      pRq->mpUserData = (undefined *)param_4;
    }
  }
  else {
    pRq = (node_create_request *)0x0;
  }
  return pRq;
}


/* __stdcall fpcNdRq_DeleteNode(unsigned long,
                                process_node_class *) */

node_create_request * fpcNdRq_DeleteNode(int param_1,process_node_class *param_2)

{
  int iVar1;
  node_create_request *pnVar2;
  
  iVar1 = fpcNdRq_IsPossibleTarget(param_2);
  if ((iVar1 == 1) && (iVar1 = fpcNdRq_IsIng(param_2), iVar1 == 0)) {
    pnVar2 = fpcNdRq_Create(param_1);
    if (pnVar2 != (node_create_request *)0x0) {
      pnVar2->mPhsHnd = (cPhs__Handler *)&methods_2348;
      pnVar2->mpNodeClass = param_2;
      pnVar2->mBsPcId = (param_2->parent).mBsPcId;
      pnVar2->mpLayer = (param_2->parent).mLyTg.mpLayer;
    }
  }
  else {
    pnVar2 = (node_create_request *)0x0;
  }
  return pnVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fpcNdRq_CreateNode(unsigned long,
                                short,
                                void *) */

node_create_request * fpcNdRq_CreateNode(ulong param_1,short param_2,void *param_3)

{
  layer_class *pLy;
  int iVar1;
  node_create_request *pnVar2;
  
  pLy = f_pc_layer::fpcLy_CurrentLayer();
  if ((pLy->mLayerID == 0) || (iVar1 = fpcNdRq_IsPossibleTarget(pLy->mpPcNode), iVar1 != 0)) {
    pnVar2 = fpcNdRq_Create(param_1);
    if (pnVar2 != (node_create_request *)0x0) {
      pnVar2->mPhsHnd = (cPhs__Handler *)&methods_2359;
      if (pLy->mLayerID != 0) {
        pnVar2->mpNodeClass = pLy->mpPcNode;
        pnVar2->mBsPcId = (pLy->mpPcNode->parent).mBsPcId;
      }
      pnVar2->mpLayer = pLy;
      pnVar2->mProcName = param_2;
      pnVar2->mpUserData = (undefined *)param_3;
    }
  }
  else {
    pnVar2 = (node_create_request *)0x0;
  }
  return pnVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fpcNdRq_Request(unsigned long,
                             int,
                             process_node_class *,
                             short,
                             void *,
                             node_create_request_method_class *) */

node_create_request *
fpcNdRq_Request
          (ulong size,int mode,process_node_class *param_3,short procName,void *param_5,
          undefined *param_6)

{
  node_create_request *pReq;
  
  if (mode == 2) {
    pReq = fpcNdRq_ChangeNode(size,param_3,procName,param_5);
  }
  else {
    if (mode < 2) {
      if (mode == 0) {
        pReq = fpcNdRq_CreateNode(size,procName,param_5);
      }
      else {
        if (-1 < mode) {
          pReq = (node_create_request *)fpcNdRq_DeleteNode(size,param_3);
        }
      }
    }
  }
  if (pReq != (node_create_request *)0x0) {
    pReq->mArg = mode;
    pReq->mpSubMtd = param_6;
    fpcNdRq_ToRequestQ(pReq);
  }
  return pReq;
}


/* __stdcall fpcNdRq_ReChangeNode(unsigned int,
                                  short,
                                  void *) */

undefined4
fpcNdRq_ReChangeNode(node_class *param_1,undefined2 param_2,node_class *param_3)

{
  node_class *pnVar1;
  node_class *pnVar2;
  
  pnVar1 = l_fpcNdRq_Queue.mpHead;
  while( true ) {
    if (pnVar1 == (node_class *)0x0) {
      return 0;
    }
    pnVar2 = pnVar1[1].mpPrevNode;
    if ((pnVar2[5].mpData == (undefined *)0x2) && (pnVar2[5].mpNextNode == param_1)) break;
    if (pnVar1 == (node_class *)0x0) {
      pnVar1 = (node_class *)0x0;
    }
    else {
      pnVar1 = pnVar1->mpNextNode;
    }
  }
  if (pnVar2[7].mpPrevNode == (node_class *)0xfffffffe) {
    *(undefined2 *)&pnVar2[7].mpData = param_2;
    pnVar2[7].mpNextNode = param_3;
    return 1;
  }
  return 0;
}


/* __stdcall fpcNdRq_ReRequest(unsigned int,
                               short,
                               void *) */

void fpcNdRq_ReRequest(void)

{
  fpcNdRq_ReChangeNode();
  return;
}

