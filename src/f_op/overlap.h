#pragma once

#include <SComponent.h>
#include <f_pc/leaf.h>
#include <f_pc/stdcreate.h>

struct overlap1_class : public leafdraw_class {
	profile_method_class *methods;
	request_base_class request;
	int state, fadeinframesleft, fadeoutframesleft;
};

struct overlap_request_class : public request_base_class {
	short mbIsDoingReq;
	short mPeektime;
	int mbIsPeek;
	void *field4_0xc;	//
	short field5_0x10;	//
	int ovl_std_create_request;
	//
	request_of_phase_process_class mOvlPhs;
	overlap1_class *overlapactor;  //
	layer_class *mpLayer;
};

namespace f_op_overlap_req {
	extern StepFunction<overlap_request_class> *phaseMethod$2234[];

	uint fopOvlpReq_Is_PeektimeLimit(overlap_request_class *param_1);
	undefined4 fopOvlpReq_OverlapClr(overlap_request_class *param_1);
	undefined4 fopOvlpReq_Handler(overlap_request_class *param_1);
	uint fopOvlpReq_Cancel(overlap_request_class *param_1);
	void fopOvlpReq_SetPeektime(overlap_request_class *param_1, ushort param_2);
	int fopOvlpReq_phase_Create(overlap_request_class *param_1);
	int fopOvlpReq_phase_IsCreated(overlap_request_class *param_1);
	int fopOvlpReq_phase_IsComplete(overlap_request_class *param_1);
	int fopOvlpReq_phase_WaitOfFadeout(overlap_request_class *param_1);
	int fopOvlpReq_phase_IsWaitOfFadeout(overlap_request_class *param_1);
	int fopOvlpReq_phase_IsDone(overlap_request_class *param_1);
	void fopOvlpReq_Request(overlap_request_class *param_1, short param_2, ushort param_3);
	int fopOvlpReq_phase_Done(overlap_request_class *param_1);
}

namespace f_op_overlap_mng {
	extern overlap_request_class *l_fopOvlpM_overlap;
	extern overlap_request_class l_fopOvlpM_Request;

	void fopOvlpM_Init();
	int fopOvlpM_ClearOfReq(void);
	int fopOvlpM_IsDone(void);
	int fopOvlpM_IsDoingReq(void);
	void fopOvlpM_Management(void);
	overlap_request_class *fopOvlpM_Request(short param_1, ushort param_2);
	uint fopOvlpReq_Cancel(overlap_request_class *param_1);
	undefined4 fopOvlpM_Cancel(void);
	void fopOvlpM_ToldAboutID(uint param_1);
}