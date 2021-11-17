#include <d_com_lib_game.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_phase.h>
#include <d_com_lib_game.h>


namespace d_com_lib_game {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dComLbG_PhaseHandler(request_of_phase_process_class *,
                                  int **(void *),
                                  void *) */

void dComLbG_PhaseHandler
               (request_of_phase_process_class *param_1,cPhs__Handler *param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = SComponent::cPhs_Handler(param_1,param_2,param_3);
  if (iVar1 == 2) {
    dComLbG_PhaseHandler(param_1,param_2,param_3);
  }
  return;
}

