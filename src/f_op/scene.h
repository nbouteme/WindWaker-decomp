#pragma once

#include <SComponent.h>
#include <doltypes.h>

#include "../f_pc/node.h"
#include "overlap.h"

struct scene_tag_class : public create_tag_class {
};

struct scene_class : public process_node_class {
	profile_method_class *mpSceneMtd;
	scene_tag_class mScTg;
};

struct scene_request_class : public node_create_request {
	int field1_0x64;
	request_of_phase_process_class mScenePhs;
	//
};

using SceneStepFunction = StepFunction<scene_request_class>;

namespace f_op_scene_pause {
	bool fopScnPause_Enable(scene_class *param_1);
	undefined4 fopScnPause_Disable(scene_class *param_1);
}

namespace f_op_scene_req {
	extern SceneStepFunction *submethod$2248[];
	extern SceneStepFunction *noFadeFase$2249[];
	extern SceneStepFunction *fadeFase$2250[];
	extern int l_fopScnRq_IsUsingOfOverlap;

	int fopScnRq_Execute(scene_request_class *param_1);
	int fopScnRq_Handler(void);
	int fopScnRq_Cancel(scene_request_class *param_1);
	int fopScnRq_phase_Execute(scene_request_class *param_1);
	int fopScnRq_phase_Done(scene_request_class *param_1);
	int fopScnRq_phase_IsDoingOverlap(scene_request_class *param_1);
	int fopScnRq_phase_IsDoneOverlap(scene_request_class *);
	int fopScnRq_phase_ClearOverlap(scene_request_class *);
	int fopScnRq_Request(int mode, scene_class *param_2, short procName, void *param_4, short fadeTime, ushort param_6);
	overlap_request_class *fopScnRq_FadeRequest(short param_1, ushort param_2);
	int fopScnRq_PostMethod(scene_class *param_1, scene_request_class *param_2);
}

namespace f_op_scene_mng {
	void fopScnM_Init();
	int fopScnM_CreateReq(short procname, short fadeTime, ushort param_3, void *param_4);
	void fopScnM_Management(void);
}