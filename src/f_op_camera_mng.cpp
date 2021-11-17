#include <f_op_camera_mng.h>
#include <f_pc_layer.h>
#include <f_pc_stdcreate_req.h>


namespace f_op_camera_mng {
undefined l_fopCamM_id;

/* __stdcall fopCamM_GetParam(camera_class *) */

int fopCamM_GetParam(camera_class *param_1)

{
  return (param_1->parent).parent.mParameters;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopCamM_Create(int,
                            short,
                            void *) */

undefined4 fopCamM_Create(int param_1,short param_2,void *param_3)

{
  layer_class *plVar1;
  undefined4 uVar2;
  
  plVar1 = f_pc_layer::fpcLy_CurrentLayer();
  uVar2 = f_pc_stdcreate_req::fpcSCtRq_Request(plVar1,param_2,(undefined *)0x0,(void *)0x0,param_3);
  *(undefined4 *)(&l_fopCamM_id + param_1 * 4) = uVar2;
  return *(undefined4 *)(&l_fopCamM_id + param_1 * 4);
}


/* __stdcall fopCamM_Management(void) */

void fopCamM_Management(void)

{
  return;
}


/* __stdcall fopCamM_Init(void) */

void fopCamM_Init(void)

{
  return;
}

