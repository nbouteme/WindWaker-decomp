#include <SComponent/c_phase.h>
#include <SComponent/c_phase.h>


namespace SComponent {

/* __stdcall cPhs_Reset(request_of_phase_process_class *) */

void cPhs_Reset(request_of_phase_process_class *param_1)

{
  param_1->mStep = 0;
  return;
}


/* __stdcall cPhs_Set(request_of_phase_process_class *,
                      int **(void *)) */

void cPhs_Set(request_of_phase_process_class *param_1,void *param_2)

{
  param_1->mpTbl = (cPhs__Handler **)param_2;
  param_1->mStep = 0;
  return;
}


/* __stdcall cPhs_UnCompleate(request_of_phase_process_class *) */

void cPhs_UnCompleate(request_of_phase_process_class *param_1)

{
  param_1->mpTbl = (cPhs__Handler **)0x0;
  cPhs_Reset(param_1);
  return;
}


/* __stdcall cPhs_Compleate(request_of_phase_process_class *) */

PhaseState cPhs_Compleate(request_of_phase_process_class *param_1)

{
  param_1->mpTbl = (cPhs__Handler **)0x0;
  return cPhs_COMPLEATE_e;
}


/* __stdcall cPhs_Next(request_of_phase_process_class *) */

PhaseState cPhs_Next(request_of_phase_process_class *param_1)

{
  bool bVar1;
  PhaseState PVar2;
  
  if (param_1->mpTbl == (cPhs__Handler **)0x0) {
    PVar2 = cPhs_COMPLEATE_e;
  }
  else {
    param_1->mStep = param_1->mStep + 1;
    bVar1 = param_1->mpTbl[param_1->mStep] == (cPhs__Handler *)0x0;
    if ((bVar1) || (bVar1)) {
      PVar2 = cPhs_Compleate(param_1);
    }
    else {
      PVar2 = 1;
    }
  }
  return PVar2;
}


/* __stdcall cPhs_Do(request_of_phase_process_class *,
                     void *) */

PhaseState cPhs_Do(request_of_phase_process_class *param_1,void *param_2)

{
  PhaseState PVar1;
  int ret;
  
  if (param_1->mpTbl == (cPhs__Handler **)0x0) {
    ret = cPhs_Compleate(param_1);
  }
  else {
    ret = (*param_1->mpTbl[param_1->mStep])(param_2);
    if (ret == 3) {
      cPhs_UnCompleate(param_1);
      ret = 3;
    }
    else {
      if (ret < 3) {
        if (ret == 1) {
          ret = cPhs_Next(param_1);
        }
        else {
          if (0 < ret) {
            PVar1 = cPhs_Next(param_1);
            ret = cPhs_COMPLEATE_e;
            if (PVar1 == 1) {
              ret = 2;
            }
          }
        }
      }
      else {
        if (ret == cPhs_ERROR_e) {
          cPhs_UnCompleate(param_1);
          ret = 5;
        }
        else {
          if (ret < 5) {
            ret = cPhs_Compleate(param_1);
          }
        }
      }
    }
  }
  return ret;
}


/* __stdcall cPhs_Handler(request_of_phase_process_class *,
                          int **(void *),
                          void *) */

int cPhs_Handler
              (request_of_phase_process_class *param_1,cPhs__Handler *param_2,void *param_3)

{
  PhaseState PVar1;
  
  param_1->mpTbl = (cPhs__Handler **)param_2;
  PVar1 = cPhs_Do(param_1,param_3);
  return PVar1;
}

