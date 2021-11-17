#include <f_op_scene_req.h>
#include <f_op_overlap_mng.h>
#include <f_pc_node_req.h>
#include <f_pc_executor.h>
#include <f_op_scene_pause.h>
#include <SComponent/c_phase.h>
#include <f_op_scene_req.h>


namespace f_op_scene_req {
undefined4 l_fopScnRq_IsUsingOfOverlap;

/* __stdcall fopScnRq_phase_ClearOverlap(scene_request_class *) */

undefined4 fopScnRq_phase_ClearOverlap(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = f_op_overlap_mng::fopOvlpM_ClearOfReq();
  uVar2 = 0;
  if (iVar1 == 1) {
    uVar2 = 2;
  }
  return uVar2;
}


/* __stdcall fopScnRq_phase_Execute(scene_request_class *) */

void fopScnRq_phase_Execute(node_create_request *param_1)

{
  f_pc_node_req::fpcNdRq_Execute(param_1);
  return;
}


/* __stdcall fopScnRq_phase_IsDoingOverlap(scene_request_class *) */

int fopScnRq_phase_IsDoingOverlap(scene_request_class *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
  iVar2 = 0;
  if (iVar1 == 1) {
    iVar2 = 2;
  }
  return iVar2;
}


/* __stdcall fopScnRq_phase_IsDoneOverlap(scene_request_class *) */

int fopScnRq_phase_IsDoneOverlap(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = f_op_overlap_mng::fopOvlpM_IsDone();
  iVar2 = 0;
  if (iVar1 == 1) {
    iVar2 = 2;
  }
  return iVar2;
}


/* __stdcall fopScnRq_phase_Done(scene_request_class *) */

undefined4 fopScnRq_phase_Done(scene_request_class *param_1)

{
  if ((param_1->parent).mArg != 1) {
    f_pc_executor::fpcEx_SearchByID((param_1->parent).mRqId);
    f_op_scene_pause::fopScnPause_Disable();
  }
  l_fopScnRq_IsUsingOfOverlap = 0;
  return 2;
}


/* __stdcall fopScnRq_Execute(scene_request_class *) */

void fopScnRq_Execute(void *param_1)

{
  PhaseState PVar1;
  
  PVar1 = SComponent::cPhs_Do((request_of_phase_process_class *)((int)param_1 + 0x68),param_1);
  if (PVar1 == 2) {
    fopScnRq_Execute(param_1);
  }
  return;
}


/* __stdcall fopScnRq_PostMethod(void *,
                                 scene_request_class *) */

undefined4 fopScnRq_PostMethod(int param_1,int param_2)

{
  f_op_scene_pause::fopScnPause_Enable();
  if (*(int *)(param_2 + 100) != 0) {
    f_op_overlap_mng::fopOvlpM_ToldAboutID(*(undefined4 *)(param_1 + 4));
  }
  return 1;
}


/* __stdcall fopScnRq_Cancel(scene_request_class *) */

undefined4 fopScnRq_Cancel(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 100) == 0) || (iVar1 = f_op_overlap_mng::fopOvlpM_Cancel(), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __stdcall fopScnRq_FadeRequest(short,
                                  unsigned short) */

int fopScnRq_FadeRequest(short param_1,ushort param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if ((l_fopScnRq_IsUsingOfOverlap == 0) &&
     (iVar1 = f_op_overlap_mng::fopOvlpM_Request(param_1,param_2), iVar1 != 0)) {
    l_fopScnRq_IsUsingOfOverlap = 1;
  }
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall fopScnRq_Request(int,
                              scene_class *,
                              short,
                              void *,
                              short,
                              unsigned short) */

undefined *
fopScnRq_Request
          (int param_1,scene_class *param_2,short procName,void *param_4,short fadeTime,
          ushort param_6)

{
  scene_request_class *pReq;
  undefined *puVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  ppuVar2 = &noFadeFase_2249;
  pReq = (scene_request_class *)
         f_pc_node_req::fpcNdRq_Request
                   (0x74,param_1,&param_2->parent,procName,param_4,&submethod_2248);
  if (pReq == (scene_request_class *)0x0) {
    puVar1 = &DAT_ffffffff;
  }
  else {
    if (fadeTime != 0x7fff) {
      ppuVar2 = &fadeFase_2250;
      iVar3 = fopScnRq_FadeRequest(fadeTime,param_6);
      if (iVar3 == 0) {
        f_pc_node_req::fpcNdRq_Delete((node_create_request *)pReq);
        return &DAT_ffffffff;
      }
    }
    pReq->field_0x64 = iVar3;
    SComponent::cPhs_Set(&pReq->mPhs,ppuVar2);
    puVar1 = (pReq->parent).field_0x44;
  }
  return puVar1;
}


/* __stdcall fopScnRq_ReRequest(unsigned int,
                                short,
                                void *) */

void fopScnRq_ReRequest(void)

{
  f_pc_node_req::fpcNdRq_ReRequest();
  return;
}


/* __stdcall fopScnRq_Handler(void) */

void fopScnRq_Handler(void)

{
  f_pc_node_req::fpcNdRq_Handler();
  return;
}

