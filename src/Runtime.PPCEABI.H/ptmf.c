#include <Runtime.PPCEABI.H/ptmf.h>


namespace Runtime.PPCEABI.H {

bool __ptmf_test(PTMF *param_1)

{
  if (param_1->this_delta != 0) {
    return true;
  }
  if (param_1->vtbl_offset != 0) {
    return true;
  }
  if (param_1->func != (undefined *)0x0) {
    return true;
  }
  return false;
}


bool __ptmf_cmpr(PTMF *ptmf1,PTMF *ptmf2)

{
  if (ptmf1->this_delta != ptmf2->this_delta) {
    return true;
  }
  if (ptmf1->vtbl_offset != ptmf2->vtbl_offset) {
    return true;
  }
  if (ptmf1->func != ptmf2->func) {
    return true;
  }
  return false;
}


void __ptmf_scall(PTMF *ptmf,void *this,void *param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = (code *)ptmf->func;
  if (-1 < ptmf->vtbl_offset) {
    UNRECOVERED_JUMPTABLE =
         *(code **)(*(int *)(UNRECOVERED_JUMPTABLE + (int)this + ptmf->this_delta) +
                   ptmf->vtbl_offset);
  }
                    /* WARNING: Could not recover jumptable at 0x80328e0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

