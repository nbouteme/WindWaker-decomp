#include <f_op_camera.h>
#include <d_meter.h>
#include <f_pc_leaf.h>
#include <f_pc_method.h>
#include <f_op_draw_tag.h>


namespace f_op_camera {

/* __stdcall fopCam_Draw(camera_class *) */

undefined4 fopCam_Draw(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  bVar1 = d_meter::dMenu_flag();
  if (bVar1 == 0) {
    uVar2 = f_pc_leaf::fpcLf_DrawMethod(*(void **)(param_1 + 0x224),param_1);
  }
  return uVar2;
}


/* __stdcall fopCam_Execute(camera_class *) */

profile_method_class * fopCam_Execute(camera_class *param_1)

{
  byte bVar1;
  profile_method_class *unaff_r31;
  
  bVar1 = d_meter::dMenu_flag();
  if ((bVar1 == 0) && (dScnPly_ply_c::pauseTimer == 0)) {
    unaff_r31 = (profile_method_class *)param_1->mpMtd;
    f_pc_method::fpcMtd_Execute(unaff_r31,param_1);
  }
  return unaff_r31;
}


/* __stdcall fopCam_IsDelete(camera_class *) */

int fopCam_IsDelete(void *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_method::fpcMtd_IsDelete(*(profile_method_class **)((int)param_1 + 0x224),param_1);
  if (iVar1 == 1) {
    f_op_draw_tag::fopDwTg_DrawQTo((int)param_1 + 0x210);
  }
  return iVar1;
}


/* __stdcall fopCam_Delete(camera_class *) */

int fopCam_Delete(void *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_method::fpcMtd_Delete(*(profile_leaf_method_class **)((int)param_1 + 0x224),param_1);
  if (iVar1 == 1) {
    f_op_draw_tag::fopDwTg_DrawQTo((int)param_1 + 0x210);
  }
  return iVar1;
}


/* __stdcall fopCam_Create(void *) */

int fopCam_Create(camera_class *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1->parent).parent.mInitState == 0) {
    param_1->mpMtd = (param_1->parent).parent.mpProf[1].parent.mpMtd0;
    f_op_draw_tag::fopDwTg_Init(&param_1->mDwTg,param_1);
    piVar1 = (int *)(param_1->parent).parent.mpUserData;
    if (piVar1 != (int *)0x0) {
      (param_1->parent).parent.mParameters = *piVar1;
    }
  }
  iVar2 = f_pc_method::fpcMtd_Create(param_1->mpMtd,param_1);
  if (iVar2 == 4) {
    iVar3 = f_pc_leaf::fpcLf_GetPriority(&param_1->parent);
    f_op_draw_tag::fopDwTg_ToDrawQ(&param_1->mDwTg,(int)(short)iVar3);
  }
  return iVar2;
}

