#include <f_op_overlap_mng.h>
#include <f_pc_executor.h>
#include <f_op_scene_pause.h>
#include <SComponent/c_request.h>
#include <f_op_overlap_req.h>
#include <JUtility/JUTAssert.h>


namespace f_op_overlap_mng {
struct overlap_request_class l_fopOvlpM_Request;

/* __stdcall fopOvlpM_SceneIsStop(void) */

undefined4 fopOvlpM_SceneIsStop(void)

{
  undefined4 uVar1;
  
  if (l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
    uVar1 = 0;
  }
  else {
    f_pc_executor::fpcEx_SearchByID(*(int *)(l_fopOvlpM_overlap->field_0x20 + 200));
    uVar1 = f_op_scene_pause::fopScnPause_Enable();
  }
  return uVar1;
}


/* __stdcall fopOvlpM_SceneIsStart(void) */

undefined4 fopOvlpM_SceneIsStart(void)

{
  undefined4 uVar1;
  
  if (l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
    uVar1 = 0;
  }
  else {
    f_pc_executor::fpcEx_SearchByID(*(int *)(l_fopOvlpM_overlap->field_0x20 + 200));
    uVar1 = f_op_scene_pause::fopScnPause_Disable();
  }
  return uVar1;
}


/* __stdcall fopOvlpM_IsOutReq(overlap_task_class *) */

uint fopOvlpM_IsOutReq(int param_1)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(2 - (*(byte *)(param_1 + 0xc4) & 0x3f));
  return uVar1 >> 5 & 0xff;
}


/* __stdcall fopOvlpM_Done(overlap_task_class *) */

void fopOvlpM_Done(int param_1)

{
  SComponent::cReq_Done((request_base_class *)(param_1 + 0xc4));
  return;
}


/* __stdcall fopOvlpM_ToldAboutID(unsigned int) */

void fopOvlpM_ToldAboutID(undefined4 param_1)

{
  if (l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
    return;
  }
  *(undefined4 *)(l_fopOvlpM_overlap->field_0x20 + 200) = param_1;
  return;
}


/* __stdcall fopOvlpM_IsPeek(void) */

undefined * fopOvlpM_IsPeek(void)

{
  if (l_fopOvlpM_overlap != (overlap_request_class *)0x0) {
    return l_fopOvlpM_overlap->mbIsPeek;
  }
  return (undefined *)0x0;
}


/* __stdcall fopOvlpM_IsDone(void) */

undefined4 fopOvlpM_IsDone(void)

{
  undefined4 uVar1;
  
  if (l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = SComponent::cReq_Is_Done(&l_fopOvlpM_overlap->parent);
  }
  return uVar1;
}


/* __stdcall fopOvlpM_IsDoingReq(void) */

int fopOvlpM_IsDoingReq(void)

{
  if ((l_fopOvlpM_overlap != (overlap_request_class *)0x0) &&
     (l_fopOvlpM_overlap->mbIsDoingReq == 1)) {
    return 1;
  }
  return 0;
}


/* __stdcall fopOvlpM_ClearOfReq(void) */

undefined4 fopOvlpM_ClearOfReq(void)

{
  undefined4 uVar1;
  
  if (l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = f_op_overlap_req::fopOvlpReq_OverlapClr(l_fopOvlpM_overlap);
  }
  return uVar1;
}


/* __stdcall fopOvlpM_Request(short,
                              unsigned short) */

void fopOvlpM_Request(short param_1,ushort param_2)

{
  overlap_request_class *poVar1;
  
  if (l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
    poVar1 = &l_fopOvlpM_Request;
    f_op_overlap_req::fopOvlpReq_Request(&l_fopOvlpM_Request,param_1,param_2);
    l_fopOvlpM_overlap = poVar1;
  }
  return;
}


/* __stdcall fopOvlpM_Management(void) */

void fopOvlpM_Management(void)

{
  int iVar1;
  
  if (((l_fopOvlpM_overlap != (overlap_request_class *)0x0) &&
      (iVar1 = f_op_overlap_req::fopOvlpReq_Handler(), iVar1 < 6)) && (2 < iVar1)) {
    l_fopOvlpM_overlap = (overlap_request_class *)0x0;
  }
  return;
}


/* __stdcall fopOvlpM_Cancel(void) */

undefined4 fopOvlpM_Cancel(void)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  
  if (l_fopOvlpM_overlap == (overlap_request_class *)0x0) {
    uVar1 = 1;
  }
  else {
    iVar2 = f_op_overlap_req::fopOvlpReq_Cancel();
    if (iVar2 == 1) {
      l_fopOvlpM_overlap = (overlap_request_class *)0x0;
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::setWarningMessage_f
                (uVar3,"f_op_overlap_mng.cpp",0x14b,"%s",(___)"fopOvlpM_Cancel SUCCESSED");
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* __stdcall fopOvlpM_Init(void) */

void fopOvlpM_Init(void)

{
  return;
}

