#include <f_op_kankyo.h>
#include <d_meter.h>
#include <f_pc_leaf.h>
#include <f_pc_method.h>
#include <f_op_draw_tag.h>
#include <f_pc_base.h>


namespace f_op_kankyo {
int fopKy_KANKYO_TYPE;

/* __stdcall fopKy_Draw(void *) */

undefined4 fopKy_Draw(int param_1)

{
  byte bVar1;
  undefined4 unaff_r31;
  
  bVar1 = d_meter::dMenu_flag();
  if (bVar1 == 0) {
    unaff_r31 = f_pc_leaf::fpcLf_DrawMethod(*(void **)(param_1 + 0xd8),param_1);
  }
  return unaff_r31;
}


/* __stdcall fopKy_Execute(void *) */

profile_method_class * fopKy_Execute(kankyo_class *param_1)

{
  short sVar1;
  byte bVar2;
  profile_method_class *unaff_r31;
  
  if ((dScnPly_ply_c::pauseTimer == 0) &&
     (((bVar2 = d_meter::dMenu_flag(), bVar2 == 0 ||
       (sVar1 = (param_1->parent).parent.mProcName, sVar1 == 0x17)) || (sVar1 == 0x1a)))) {
    unaff_r31 = param_1->mpMtd;
    f_pc_method::fpcMtd_Execute(unaff_r31,param_1);
  }
  return unaff_r31;
}


/* __stdcall fopKy_IsDelete(void *) */

int fopKy_IsDelete(void *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_method::fpcMtd_IsDelete(*(profile_method_class **)((int)param_1 + 0xd8),param_1);
  if (iVar1 == 1) {
    f_op_draw_tag::fopDwTg_DrawQTo((int)param_1 + 0xc4);
  }
  return iVar1;
}


/* __stdcall fopKy_Delete(void *) */

int fopKy_Delete(void *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_method::fpcMtd_Delete(*(profile_leaf_method_class **)((int)param_1 + 0xd8),param_1);
  f_op_draw_tag::fopDwTg_DrawQTo((int)param_1 + 0xc4);
  return iVar1;
}


/* __stdcall fopKy_Create(void *) */

int fopKy_Create(kankyo_class *param_1)

{
  int iVar1;
  fopKyM_prm_class *pPrm;
  int iVar2;
  f_pc_profile__Profile_Actor *pfVar3;
  
  if ((param_1->parent).parent.mInitState == 0) {
    pfVar3 = (param_1->parent).parent.mpProf;
    iVar1 = f_pc_base::fpcBs_MakeOfType(&fopKy_KANKYO_TYPE);
    param_1->mBsType = iVar1;
    param_1->mpMtd = pfVar3->mpMtd2;
    f_op_draw_tag::fopDwTg_Init(&param_1->mDwTg,param_1);
    pPrm = (fopKyM_prm_class *)(param_1->parent).parent.mpUserData;
    if (pPrm != (fopKyM_prm_class *)0x0) {
      (param_1->mPos).x = (pPrm->mPos).x;
      (param_1->mPos).y = (pPrm->mPos).y;
      (param_1->mPos).z = (pPrm->mPos).z;
      (param_1->mScale).x = (pPrm->mScale).x;
      (param_1->mScale).y = (pPrm->mScale).y;
      (param_1->mScale).z = (pPrm->mScale).z;
      param_1->mParameter = pPrm->mParameter;
    }
  }
  iVar1 = f_pc_method::fpcMtd_Create(&param_1->mpMtd->parent,param_1);
  if (iVar1 == 4) {
    iVar2 = f_pc_leaf::fpcLf_GetPriority(&param_1->parent);
    f_op_draw_tag::fopDwTg_ToDrawQ(&param_1->mDwTg,(int)(short)iVar2);
  }
  return iVar1;
}

