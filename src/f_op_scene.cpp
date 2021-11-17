#include <f_op_scene.h>
#include <f_pc_node.h>
#include <f_pc_method.h>
#include <f_op_scene_tag.h>
#include <m_Do_hostIO.h>


namespace f_op_scene {

/* __stdcall fopScn_Draw(scene_class *) */

void fopScn_Draw(int param_1)

{
  f_pc_node::fpcNd_DrawMethod(*(undefined4 *)(param_1 + 0x1ac),param_1);
  return;
}


/* __stdcall fopScn_Execute(scene_class *) */

void fopScn_Execute(void *param_1)

{
  f_pc_method::fpcMtd_Execute(*(profile_method_class **)((int)param_1 + 0x1ac),param_1);
  return;
}


/* __stdcall fopScn_IsDelete(void *) */

void fopScn_IsDelete(void *param_1)

{
  f_pc_method::fpcMtd_IsDelete(*(profile_method_class **)((int)param_1 + 0x1ac),param_1);
  return;
}


/* __stdcall fopScn_Delete(void *) */

int fopScn_Delete(void *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_method::fpcMtd_Delete(*(profile_leaf_method_class **)((int)param_1 + 0x1ac),param_1);
  if (iVar1 == 1) {
    f_op_scene_tag::fopScnTg_QueueTo((int)param_1 + 0x1b0);
  }
  mDoHIO_root_c::update((mDoHIO_root_c *)&m_Do_hostIO::mDoHIO_root);
  return iVar1;
}


/* __stdcall fopScn_Create(void *) */

void fopScn_Create(scene_class *param_1)

{
  int *piVar1;
  
  if ((param_1->parent).parent.mInitState == 0) {
                    /* This is not mDrawPriority, since it's for a scene profile, we just use the
                       Actor mProf in the base class because it's the most common */
    param_1->mpMtd = *(profile_method_class **)&((param_1->parent).parent.mpProf)->mDrawPriority;
    f_op_scene_tag::fopScnTg_Init(&param_1->mScTg,param_1);
    f_op_scene_tag::fopScnTg_ToQueue(&param_1->mScTg);
    piVar1 = (int *)(param_1->parent).parent.mpUserData;
    if (piVar1 != (int *)0x0) {
      (param_1->parent).parent.mParameters = *piVar1;
    }
  }
  f_pc_method::fpcMtd_Create(&param_1->mpMtd->parent,param_1);
  return;
}

