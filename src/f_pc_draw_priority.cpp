#include <f_pc_draw_priority.h>
#include <f_pc_draw_priority.h>


namespace f_pc_draw_priority {

/* __stdcall fpcDwPi_Get(draw_priority_class *) */

int fpcDwPi_Get(draw_priority_class *param_1)

{
  return (int)param_1->mPriority;
}


/* __stdcall fpcDwPi_Set(draw_priority_class *,
                         short) */

void fpcDwPi_Set(draw_priority_class *param_1,short param_2)

{
  param_1->mPriority = param_2;
  return;
}


/* __stdcall fpcDwPi_Init(draw_priority_class *,
                          short) */

void fpcDwPi_Init(draw_priority_class *param_1,short param_2)

{
  fpcDwPi_Set(param_1,param_2);
  return;
}

