#pragma once
#include <ctypes.h>



namespace SComponent {
void cPhs_Reset(request_of_phase_process_class *param_1);
void cPhs_Set(request_of_phase_process_class *param_1,void *param_2);
void cPhs_UnCompleate(request_of_phase_process_class *param_1);
PhaseState cPhs_Compleate(request_of_phase_process_class *param_1);
PhaseState cPhs_Next(request_of_phase_process_class *param_1);
PhaseState cPhs_Do(request_of_phase_process_class *param_1,void *param_2);
int cPhs_Handler(request_of_phase_process_class *param_1,cPhs__Handler *param_2,void *param_3);
}
