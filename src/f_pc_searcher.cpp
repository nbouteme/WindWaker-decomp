#include <f_pc_searcher.h>


namespace f_pc_searcher {

/* __stdcall fpcSch_JudgeForPName(void *,
                                  void *) */

int fpcSch_JudgeForPName(base_process_class *param_1,short *param_2)

{
  if (param_1->mProcName == *param_2) {
    return (int)param_1;
  }
  return (int)(base_process_class *)0x0;
}


/* __stdcall fpcSch_JudgeByID(void *,
                              void *) */

int fpcSch_JudgeByID(base_process_class *param_1,int *param_2)

{
  if (param_1->mBsPcId == *param_2) {
    return (int)param_1;
  }
  return (int)(base_process_class *)0x0;
}

