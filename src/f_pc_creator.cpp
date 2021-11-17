#include <f_pc_creator.h>
#include <f_pc_create_req.h>


namespace f_pc_creator {

/* __stdcall fpcCt_IsCreatingByID(unsigned int) */

void fpcCt_IsCreatingByID(int param_1)

{
  f_pc_create_req::fpcCtRq_IsCreatingByID(param_1);
  return;
}


/* __stdcall fpcCt_IsDoing(base_process_class *) */

int fpcCt_IsDoing(base_process_class *param_1)

{
  int iVar1;
  
  iVar1 = f_pc_create_req::fpcCtRq_IsDoing(param_1->mpCtRq);
  return iVar1;
}


/* __stdcall fpcCt_Abort(base_process_class *) */

void fpcCt_Abort(base_process_class *param_1)

{
  f_pc_create_req::fpcCtRq_Cancel(param_1->mpCtRq);
  return;
}


/* __stdcall fpcCt_Handler(void) */

void fpcCt_Handler(void)

{
  f_pc_create_req::fpcCtRq_Handler();
  return;
}

