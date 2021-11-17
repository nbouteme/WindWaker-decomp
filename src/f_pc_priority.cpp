#include <f_pc_priority.h>
#include <SComponent/c_tag.h>
#include <f_pc_layer.h>
#include <f_pc_priority.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <f_pc_layer_tag.h>
#include <f_pc_line_tag.h>
#include <f_pc_method_tag.h>


namespace f_pc_priority {
struct node_list_class l_fpcPi_Queue;

/* __stdcall fpcPi_IsInQueue(process_priority_class *) */

void fpcPi_IsInQueue(create_tag_class *param_1)

{
  SComponent::cTg_IsUse(param_1);
  return;
}


/* __stdcall fpcPi_QueueTo(process_priority_class *) */

undefined4 fpcPi_QueueTo(process_priority_class *param_1)

{
  SComponent::cTg_SingleCut(&param_1->parent);
  f_pc_layer::fpcLy_CancelQTo(&param_1->mMtdTg);
  return 1;
}


/* __stdcall fpcPi_ToQueue(process_priority_class *) */

undefined4 fpcPi_ToQueue(process_priority_class *param_1)

{
  int iVar1;
  layer_class *pLayer;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_1->mLayerQ;
  iVar1 = SComponent::cTg_Addition(&l_fpcPi_Queue,&param_1->parent);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if (uVar3 != 0xfffffffd) {
      pLayer = f_pc_layer::fpcLy_Layer(uVar3);
      iVar1 = f_pc_layer::fpcLy_ToCancelQ(pLayer,&param_1->mMtdTg);
      if (iVar1 == 0) {
        SComponent::cTg_SingleCut(&param_1->parent);
        return 0;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}


/* __stdcall fpcPi_GetFromQueue(void) */

process_priority_class * fpcPi_GetFromQueue(void)

{
  process_priority_class *pPrio;
  base_process_class *pcVar1;
  process_priority_class *ppVar2;
  
  pPrio = (process_priority_class *)SComponent::cTg_GetFirst(&l_fpcPi_Queue);
  if (pPrio == (process_priority_class *)0x0) {
    ppVar2 = (process_priority_class *)0x0;
  }
  else {
    pcVar1 = (base_process_class *)(pPrio->parent).mpTagData;
    ppVar2 = &pcVar1->mPi;
    f_pc_layer::fpcLy_CancelQTo(&(pcVar1->mPi).mMtdTg);
  }
  return ppVar2;
}


/* __stdcall fpcPi_Delete(process_priority_class *) */

undefined4 fpcPi_Delete(process_priority_class *param_1)

{
  fpcPi_QueueTo(param_1);
  param_1->mLayerQ = crear_2186;
  param_1->mListIDQ = uRam803f6194;
  param_1->mListPrioQ = uRam803f6196;
  return 1;
}


/* __stdcall fpcPi_IsNormal(unsigned int,
                            unsigned short,
                            unsigned short) */

bool fpcPi_IsNormal(uint param_1,ushort param_2,ushort param_3)

{
  if (((param_1 < 0xfffffffe) && (param_2 < 0xfffe)) && (param_3 < 0xfffe)) {
    return true;
  }
  return false;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fpcPi_Change(process_priority_class *,
                          unsigned int,
                          unsigned short,
                          unsigned short) */

int fpcPi_Change
              (process_priority_class *param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  base_process_class *pProc;
  
  pProc = (base_process_class *)(param_1->parent).mpTagData;
  bVar1 = false;
  if (pProc->mInitState == 3) {
    iVar2 = 0;
  }
  else {
    bVar3 = fpcPi_IsNormal(param_2,(ushort)param_3,(ushort)param_4);
    if (bVar3 == false) {
      iVar2 = 0;
    }
    else {
      param_1->mLayerQ = param_1->mLayerCurr;
      param_1->mListIDQ = param_1->mListIDCurr;
      param_1->mListPrioQ = param_1->mListPrioCurr;
      if ((param_2 != 0xfffffffd) && (param_1->mLayerCurr != param_2)) {
        param_1->mLayerQ = param_2;
        bVar1 = true;
      }
      if (((param_3 & 0xffff) != 0xfffd) && ((uint)param_1->mListIDCurr != (param_3 & 0xffff))) {
        param_1->mListIDQ = (ushort)param_3;
        bVar1 = true;
      }
      if ((param_4 & 0xffff) != 0xfffd) {
        if ((uint)param_1->mListPrioCurr != (param_4 & 0xffff)) {
          param_1->mListPrioQ = (ushort)param_4;
          bVar1 = true;
        }
      }
      if ((pProc->mInitState == 0) || (pProc->mInitState == 1)) {
        param_1->mLayerCurr = param_1->mLayerQ;
        param_1->mListIDCurr = param_1->mListIDQ;
        param_1->mListPrioCurr = param_1->mListPrioQ;
        iVar2 = 1;
      }
      else {
        if (bVar1) {
          iVar2 = fpcPi_ToQueue(param_1);
        }
        else {
          iVar2 = 0;
        }
      }
    }
  }
  return iVar2;
}


/* __stdcall fpcPi_Handler(void) */

int fpcPi_Handler(void)

{
  base_process_class *pProc;
  int iVar1;
  process_priority_class *ppVar2;
  
  while( true ) {
    ppVar2 = fpcPi_GetFromQueue();
    if (ppVar2 == (process_priority_class *)0x0) {
      return 1;
    }
    pProc = (base_process_class *)(ppVar2->parent).mpTagData;
    iVar1 = f_pc_layer_tag::fpcLyTg_Move
                      (&pProc->mLyTg,ppVar2->mLayerQ,ppVar2->mListIDQ,ppVar2->mListPrioQ);
    if (iVar1 != 1) break;
    f_pc_line_tag::fpcLnTg_Move(&pProc->mLnTg,ppVar2->mListIDCurr);
    ppVar2->mLayerCurr = ppVar2->mLayerQ;
    ppVar2->mListIDCurr = ppVar2->mListIDQ;
    ppVar2->mListPrioCurr = ppVar2->mListPrioQ;
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fpcPi_Init(process_priority_class *,
                        void *,
                        unsigned int,
                        unsigned short,
                        unsigned short) */

uint fpcPi_Init
               (process_priority_class *param_1,void *param_2,uint param_3,ushort param_4,
               ushort param_5)

{
  bool bVar1;
  
  bVar1 = fpcPi_IsNormal(param_3,param_4,param_5);
  if (bVar1 != false) {
    param_1->mLayerQ = param_3;
    param_1->mListIDQ = param_4;
    param_1->mListPrioQ = param_5;
    param_1->mLayerCurr = param_1->mLayerQ;
    param_1->mListIDCurr = param_1->mListIDQ;
    param_1->mListPrioCurr = param_1->mListPrioQ;
    SComponent::cTg_Create(&param_1->parent,param_2);
    f_pc_method_tag::fpcMtdTg_Init(&param_1->mMtdTg,fpcPi_Delete,param_1);
  }
  return (uint)(bVar1 != false);
}

