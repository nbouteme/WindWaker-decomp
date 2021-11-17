#include <f_pc_delete_tag.h>
#include <SComponent/c_tag.h>
#include <f_pc_delete_tag.h>


namespace f_pc_delete_tag {

/* __stdcall fpcDtTg_IsEmpty(void) */

uint fpcDtTg_IsEmpty(void)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(g_fpcDtTg_Queue.mSize);
  return uVar1 >> 5;
}


/* __stdcall fpcDtTg_ToDeleteQ(delete_tag_class *) */

void fpcDtTg_ToDeleteQ(delete_tag_class *param_1)

{
  param_1->mTimer = 1;
  SComponent::cTg_Addition(&g_fpcDtTg_Queue,&param_1->parent);
  return;
}


/* __stdcall fpcDtTg_DeleteQTo(delete_tag_class *) */

void fpcDtTg_DeleteQTo(create_tag_class *param_1)

{
  SComponent::cTg_SingleCut(param_1);
  return;
}


/* __stdcall fpcDtTg_Do(delete_tag_class *,
                        int *(void *)) */

undefined4 fpcDtTg_Do(delete_tag_class *param_1,undefined *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1->mTimer < 1) {
    fpcDtTg_DeleteQTo(&param_1->parent);
    iVar1 = (*(code *)param_2)((param_1->parent).mpTagData);
    if (iVar1 == 0) {
      fpcDtTg_ToDeleteQ(param_1);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    param_1->mTimer = param_1->mTimer + -1;
    uVar2 = 0;
  }
  return uVar2;
}


/* __stdcall fpcDtTg_Init(delete_tag_class *,
                          void *) */

undefined4 fpcDtTg_Init(delete_tag_class *param_1,void *param_2)

{
  SComponent::cTg_Create(&param_1->parent,param_2);
  return 1;
}

