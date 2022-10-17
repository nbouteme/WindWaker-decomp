#include "scene.h"

#include <f_pc/profile.h>
#include <machine/dolphin/HIO.h>

#include <f_pc/method.h>

namespace f_op_scene {
	int fopScn_Create(scene_class *param_1) {
		int *piVar1;

		if (param_1->mInitState == 0) {
			/* This is not mDrawPriority, since it's for a scene profile, we just use the
                       Actor mProf in the base class because it's the most common */
			param_1->mpSceneMtd = ((f_pc_profile__Profile_Scene*)param_1->mpProf)->mpMtd15;
			f_op_scene_tag::fopScnTg_Init(&param_1->mScTg, param_1);
			f_op_scene_tag::fopScnTg_ToQueue(&param_1->mScTg);
			piVar1 = (int *)param_1->mpUserData;
			if (piVar1) {
				param_1->mParameters = *piVar1;
			}
		}
		return f_pc_method::fpcMtd_Create(param_1->mpSceneMtd, param_1);
	}

	int fopScn_Delete(scene_class *param_1) {
		int iVar1;

		iVar1 = f_pc_method::fpcMtd_Delete(param_1->mpSceneMtd, param_1);
		if (iVar1 == 1) {
			f_op_scene_tag::fopScnTg_QueueTo(&param_1->mScTg);
		}
		m_Do_hostIO::mDoHIO_root.update();
		return iVar1;
	}

	int fopScn_Execute(scene_class *param_1) {
		return f_pc_method::fpcMtd_Execute(param_1->mpSceneMtd, param_1);
	}

	int fopScn_IsDelete(scene_class *param_1) {
		return f_pc_method::fpcMtd_IsDelete(param_1->mpSceneMtd, param_1);
	}

	int fopScn_Draw(scene_class *param_1) {
		return f_pc_node::fpcNd_DrawMethod(param_1->mpSceneMtd, param_1);
	}

	profile_method_class g_fopScn_Method = MAKE_PROFILE_METHODS(fopScn);
}