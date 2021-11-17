#include <f_op_msg.h>
#include <f_pc_leaf.h>
#include <f_pc_method.h>
#include <f_op_draw_tag.h>
#include <f_pc_base.h>
#include <f_op_msg_mng.h>


namespace f_op_msg {
int fopMsg_MSG_TYPE;

/* __stdcall fopMsg_Draw(void *) */

void fopMsg_Draw(msg_class *param_1)

{
  f_pc_leaf::fpcLf_DrawMethod(param_1->mSubMtd,param_1);
  return;
}


/* __stdcall fopMsg_Execute(void *) */

void fopMsg_Execute(msg_class *this)

{
  if (dScnPly_ply_c::pauseTimer == 0) {
    f_pc_method::fpcMtd_Execute(this->mSubMtd,this);
  }
  return;
}


/* __stdcall fopMsg_IsDelete(void *) */

int fopMsg_IsDelete(msg_class *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_method::fpcMtd_IsDelete(param_1->mSubMtd,param_1);
  if (iVar1 == 1) {
    f_op_draw_tag::fopDwTg_DrawQTo(&param_1->mDwTg);
  }
  return iVar1;
}


/* __stdcall fopMsg_Delete(void *) */

int fopMsg_Delete(msg_class *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_method::fpcMtd_Delete(&param_1->mSubMtd->parent,param_1);
  f_op_draw_tag::fopDwTg_DrawQTo(&param_1->mDwTg);
  return iVar1;
}


/* __stdcall fopMsg_Create(void *) */

int fopMsg_Create(msg_class *this)

{
  int iVar1;
  fopMsgM_prm_class *pAppend;
  int iVar2;
  f_pc_profile__Profile_Actor *pProf;
  
  if ((this->parent).parent.mInitState == 0) {
    pProf = (this->parent).parent.mpProf;
    iVar1 = f_pc_base::fpcBs_MakeOfType(&fopMsg_MSG_TYPE);
    this->mMsgType = iVar1;
    this->mSubMtd = pProf->mpMtd2;
    f_op_draw_tag::fopDwTg_Init(&this->mDwTg,this);
    pAppend = f_op_msg_mng::fopMsgM_GetAppend(this);
    if (pAppend != (fopMsgM_prm_class *)0x0) {
      this->mpActor = pAppend->mpActor;
      (this->mPos).x = (pAppend->mPos).x;
      (this->mPos).y = (pAppend->mPos).y;
      (this->mPos).z = (pAppend->mPos).z;
      this->field_0xec = pAppend->field_0x10;
      this->field_0xf0 = pAppend->field_0x14;
      this->field_0xf4 = pAppend->field_0x18;
    }
  }
  iVar1 = f_pc_method::fpcMtd_Create(&this->mSubMtd->parent,this);
  if (iVar1 == 4) {
    iVar2 = f_pc_leaf::fpcLf_GetPriority(&this->parent);
    f_op_draw_tag::fopDwTg_ToDrawQ(&this->mDwTg,(int)(short)iVar2);
  }
  return iVar1;
}

