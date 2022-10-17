#include "base.h"

#include <cstring>

#include <SComponent.h>
#include <SComponent/c_malloc.h>

#include "base.h"
#include "deletor.h"
#include "layer.h"
#include "line.h"
#include "pause.h"
#include "priority.h"
#include "profile.h"

namespace f_pc_base {
	char init$2179;
	int process_id$2178;
	int g_fpcBs_type;

	int fpcBs_MakeOfType(int *param_1) {
		static int t_type = 0x9130000;

		if (*param_1 == 0) {
			*param_1 = ++t_type;
		}
		return *param_1;
	}

	int fpcBs_SubCreate(base_process_class *param_1) {
		int iVar1;

		iVar1 = f_pc_method::fpcMtd_Create(param_1->mpPcMtd, param_1);
		if (iVar1 == 3) {
			param_1->creation_status = 3;
			return 3;
		}
		if (iVar1 < 3) {
			if (1 < iVar1) {
			LAB_8003cba8:
				f_pc_base::fpcBs_DeleteAppend(param_1);
				param_1->creation_status = 2;
				return 2;
			}
			if (-1 < iVar1) {
				param_1->mInitState = 1;
				param_1->creation_status = 0;
				return 0;
			}
		} else if ((iVar1 != 5) && (iVar1 < 5))
			goto LAB_8003cba8;
		param_1->creation_status = 5;
		return 5;
	}

	base_process_class *fpcBs_Create(short param_1, uint param_2, void *param_3) {
		f_pc_profile__Profile_Base *pProf;
		base_process_class *pBs;
		uint uVar1;
		ulong uVar2;

		pProf = f_pc_profile::fpcPf_Get(param_1);
		uVar2 = pProf->mSize + pProf->mSizeOther;
		pBs = (base_process_class *)cMl::memalignB(-4, uVar2);
		if (pBs == (base_process_class *)0x0) {
			pBs = (base_process_class *)0x0;
		} else {
			//SStandard::sBs_ClearArea(pBs, uVar2);
			memset(pBs, 0, uVar2);
			f_pc_layer_tag::fpcLyTg_Init(&pBs->mLyTg, pProf->mLayerID, pBs);
			f_pc_line_tag::fpcLnTg_Init(&pBs->mLnTg, pBs);
			f_pc_delete_tag::fpcDtTg_Init(&pBs->mDtTg, pBs);
			f_pc_priority::fpcPi_Init(&pBs->mPi, pBs, pProf->mLayerID, pProf->mListID, pProf->mListPrio);
			pBs->mInitState = 0;
			pBs->field3_0xa = 0;
			pBs->mBsPcId = param_2;
			pBs->mBsTypeId = param_1;
			// TODO: doesn't make sense, will always return 1?
			uVar1 = f_pc_base::fpcBs_MakeOfType(&f_pc_base::g_fpcBs_type);
			pBs->mBsType = uVar1;
			pBs->mProcName = pProf->mPName;
			f_pc_pause::fpcPause_Init(pBs);
			pBs->mpPcMtd = (profile_method_class *)pProf->mpMtd0;
			pBs->mpProf = pProf;
			pBs->mpUserData = (undefined *)param_3;
			pBs->mParameters = pProf->mDefaultParameters;
		}
		return pBs;
	}

	void fpcBs_Execute(base_process_class *param_1) {
		layer_class *plVar1;

		plVar1 = f_pc_layer::fpcLy_CurrentLayer();
		f_pc_layer::fpcLy_SetCurrentLayer((param_1->mLyTg).mpLayer);
		f_pc_method::fpcMtd_Execute(param_1->mpPcMtd, param_1);
		f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
		return;
	}

	int fpcBs_MakeOfId(void) {
		int iVar1;

		if (init$2179 == '\0') {
			process_id$2178 = 1;
			init$2179 = '\x01';
		}
		iVar1 = process_id$2178;
		process_id$2178 = process_id$2178 + 1;
		return iVar1;
	}

	void fpcBs_DeleteAppend(base_process_class *param_1) {
		if (param_1->mpUserData != (undefined *)0x0) {
			cMl::free(param_1->mpUserData);
			param_1->mpUserData = (undefined *)0x0;
		}
		return;
	}

	int fpcBs_Delete(base_process_class *param_1) {
		int iVar1;

		iVar1 = f_pc_method::fpcMtd_Delete(param_1->mpPcMtd, param_1);
		if (iVar1 == 1) {
			fpcBs_DeleteAppend(param_1);
			param_1->mBsType = 0;
			cMl::free(param_1);
		}
		return iVar1;
	}

	bool fpcBs_Is_JustOfType(int param_1, int param_2) {
		return (param_1 == param_2);
	}

	int fpcBs_IsDelete(base_process_class *param_1) {
		layer_class *plVar1;
		int iVar2;

		plVar1 = f_pc_layer::fpcLy_CurrentLayer();
		f_pc_layer::fpcLy_SetCurrentLayer((param_1->mLyTg).mpLayer);
		iVar2 = f_pc_method::fpcMtd_IsDelete(param_1->mpPcMtd, param_1);
		f_pc_layer::fpcLy_SetCurrentLayer(plVar1);
		return iVar2;
	}
}