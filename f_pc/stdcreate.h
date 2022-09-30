#pragma once

#include <SComponent.h>

#include "creator.h"

struct standard_create_request_class : public create_request {
	request_of_phase_process_class mPhase;
	short mProcName;
	void *mpUserData;
	void *mpCallback;
	void *mpCallbackUserData;
};

namespace f_pc_stdcreate_req {
	extern StepFunction<standard_create_request_class> *submethod$2223[];
	extern StepFunction<standard_create_request_class> *method$2224[];

	int fpcSCtRq_Request(layer_class *param_1, short procname, undefined *param_3, void *param_4, void *param_5);
}