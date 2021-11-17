#include <f_op_overlap_req.h>
#include <f_pc_manager.h>
#include <SComponent/c_request.h>
#include <f_pc_executor.h>
#include <f_pc_layer.h>
#include <f_pc_stdcreate_req.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_phase.h>
#include <f_op_overlap_req.h>


namespace f_op_overlap_req {

/* __stdcall fopOvlpReq_phase_Done(overlap_request_class *) */

undefined4 fopOvlpReq_phase_Done(int param_1)

{
  base_process_class *pbVar1;
  undefined4 uVar2;
  
  pbVar1 = *(base_process_class **)(param_1 + 0x20);
  f_pc_manager::fpcM_Delete(pbVar1);
  if (pbVar1 == (base_process_class *)&DAT_00000001) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined2 *)(param_1 + 4) = 0;
    *(undefined2 *)(param_1 + 6) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __stdcall fopOvlpReq_phase_IsDone(overlap_request_class *) */

uint fopOvlpReq_phase_IsDone(request_base_class *param_1)

{
  short sVar1;
  
  SComponent::cReq_Done(param_1);
  sVar1 = param_1->field_0x2;
  param_1->field_0x2 = sVar1 + -1;
  return ((int)sVar1 | ~-(int)sVar1) >> 0x1f & 2;
}


/* __stdcall fopOvlpReq_phase_IsWaitOfFadeout(overlap_request_class *) */

undefined4 fopOvlpReq_phase_IsWaitOfFadeout(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = SComponent::cReq_Is_Done((request_base_class *)(*(int *)(param_1 + 0x20) + 0xc4));
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 8) = 0;
    uVar2 = 2;
  }
  return uVar2;
}


/* __stdcall fopOvlpReq_phase_WaitOfFadeout(overlap_request_class *) */

undefined4 fopOvlpReq_phase_WaitOfFadeout(byte *param_1)

{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 6) != 0) {
    *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + -1;
  }
  if (((*param_1 & 0x3f) == 2) && (*(short *)(param_1 + 6) == 0)) {
    SComponent::cReq_Command(*(int *)(param_1 + 0x20) + 0xc4,2);
    uVar1 = 2;
  }
  else {
    *(undefined4 *)(param_1 + 8) = 1;
    uVar1 = 0;
  }
  return uVar1;
}


/* __stdcall fopOvlpReq_phase_IsComplete(overlap_request_class *) */

undefined4 fopOvlpReq_phase_IsComplete(request_base_class *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = SComponent::cReq_Is_Done((request_base_class *)((int)param_1[8] + 0xc4));
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    SComponent::cReq_Done(param_1);
    uVar2 = 2;
  }
  return uVar2;
}


/* __stdcall fopOvlpReq_phase_IsCreated(overlap_request_class *) */

undefined4 fopOvlpReq_phase_IsCreated(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  iVar1 = f_pc_manager::fpcM_IsCreating(*(undefined4 *)(param_1 + 0x14));
  if (iVar1 == 0) {
    pvVar2 = f_pc_executor::fpcEx_SearchByID(*(int *)(param_1 + 0x14));
    if (pvVar2 == (void *)0x0) {
      uVar3 = 5;
    }
    else {
      *(void **)(param_1 + 0x20) = pvVar2;
      uVar3 = 2;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* __stdcall fopOvlpReq_phase_Create(overlap_request_class *) */

undefined4 fopOvlpReq_phase_Create(int param_1)

{
  layer_class *plVar1;
  undefined4 uVar2;
  
  f_pc_layer::fpcLy_SetCurrentLayer(*(layer_class **)(param_1 + 0x24));
  plVar1 = f_pc_layer::fpcLy_CurrentLayer();
  uVar2 = f_pc_stdcreate_req::fpcSCtRq_Request
                    (plVar1,*(short *)(param_1 + 0x10),(undefined *)0x0,(void *)0x0,(void *)0x0);
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  return 2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopOvlpReq_Request(overlap_request_class *,
                                short,
                                unsigned short) */

void fopOvlpReq_Request
               (overlap_request_class *param_1,short param_2,ushort param_3)

{
  layer_class *plVar1;
  
  if (param_1->mbIsDoingReq != 1) {
    SComponent::cReq_Command(param_1,1);
    param_1->field_0x10 = param_2;
    SComponent::cPhs_Set(&param_1->mPhs,&phaseMethod_2234);
    fopOvlpReq_SetPeektime(param_1,param_3);
    param_1->mbIsDoingReq = 1;
    (param_1->parent).field_0x2 = 1;
    param_1->field_0x20 = 0;
    param_1->mbIsPeek = (undefined *)0x0;
    param_1->field_0xc = (undefined *)0x0;
    plVar1 = f_pc_layer::fpcLy_RootLayer();
    param_1->mpLayer = plVar1;
  }
  return;
}


/* __stdcall fopOvlpReq_Handler(overlap_request_class *) */

undefined4 fopOvlpReq_Handler(void *param_1)

{
  PhaseState PVar1;
  undefined4 uVar2;
  
  PVar1 = SComponent::cPhs_Do((request_of_phase_process_class *)((int)param_1 + 0x18),param_1);
  if (PVar1 != 3) {
    if ((int)PVar1 < 3) {
      if (PVar1 == 1) {
        return 0;
      }
      if (0 < (int)PVar1) {
        uVar2 = fopOvlpReq_Handler(param_1);
        return uVar2;
      }
      if (-1 < (int)PVar1) {
        return 0;
      }
    }
    else {
      if ((PVar1 != cPhs_ERROR_e) && ((int)PVar1 < 5)) {
        return 4;
      }
    }
  }
  return 5;
}


/* __stdcall fopOvlpReq_Cancel(overlap_request_class *) */

uint fopOvlpReq_Cancel(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = fopOvlpReq_phase_Done();
  uVar1 = countLeadingZeros(2 - iVar2);
  return uVar1 >> 5;
}


/* __stdcall fopOvlpReq_Is_PeektimeLimit(overlap_request_class *) */

uint fopOvlpReq_Is_PeektimeLimit(overlap_request_class *param_1)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros((uint)(ushort)param_1->mPeektime);
  return uVar1 >> 5;
}


/* __stdcall fopOvlpReq_SetPeektime(overlap_request_class *,
                                    unsigned short) */

void fopOvlpReq_SetPeektime(overlap_request_class *param_1,ushort param_2)

{
  if (0x7fff < param_2) {
    return;
  }
  param_1->mPeektime = param_2;
  return;
}


/* __stdcall fopOvlpReq_OverlapClr(overlap_request_class *) */

undefined4 fopOvlpReq_OverlapClr(overlap_request_class *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (((char)(param_1->parent).mFlags < '\0') ||
     (uVar1 = fopOvlpReq_Is_PeektimeLimit(param_1), uVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    SComponent::cReq_Create(&param_1->parent,2);
    uVar2 = 1;
  }
  return uVar2;
}

