#include "scene.h"

namespace f_op_scene_tag {
	node_list_class g_fopScnTg_SceneList;

	void fopScnTg_Init(scene_tag_class *param_1, scene_class *param_2) {
		SComponent::cTg_Create(param_1, param_2);
	}

	void fopScnTg_ToQueue(scene_tag_class *param_1) {
		SComponent::cTg_Addition(&g_fopScnTg_SceneList, param_1);
	}

	void fopScnTg_QueueTo(scene_tag_class *param_1) {
		SComponent::cTg_SingleCut(param_1);
	}
}
