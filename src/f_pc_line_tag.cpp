#include <f_pc_line_tag.h>
#include <f_pc_line_tag.h>
#include <SComponent/c_tag.h>


namespace f_pc_line_tag {

/* __stdcall fpcLnTg_Move(line_tag *,
                          int) */

uint fpcLnTg_Move(line_tag *param_1,int param_2)

{
  uint uVar1;
  
  if (param_1->mLineListID == param_2) {
    uVar1 = 1;
  }
  else {
    fpcLnTg_QueueTo(param_1);
    uVar1 = fpcLnTg_ToQueue(param_1,param_2);
  }
  return uVar1;
}


/* __stdcall fpcLnTg_QueueTo(line_tag *) */

void fpcLnTg_QueueTo(line_tag *param_1)

{
  SComponent::cTg_SingleCutFromTree(&param_1->parent);
  param_1->mLineListID = -1;
  return;
}


/* __stdcall fpcLnTg_ToQueue(line_tag *,
                             int) */

uint fpcLnTg_ToQueue(line_tag *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = SComponent::cTg_AdditionToTree(&f_pc_line::g_fpcLn_Queue,param_2,&param_1->parent);
  if (iVar1 != 0) {
    param_1->mLineListID = param_2;
  }
  return (uint)(iVar1 != 0);
}


/* __stdcall fpcLnTg_Init(line_tag *,
                          void *) */

void fpcLnTg_Init(line_tag *param_1,void *param_2)

{
  SComponent::cTg_Create(&param_1->parent,param_2);
  param_1->mLineListID = -1;
  return;
}

