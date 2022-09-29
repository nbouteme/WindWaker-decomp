#pragma once

#include <SComponent.h>
#include <SComponent/c_malloc.h>

#include "layer.h"

namespace f_pc_node_req {
	node_list_class l_fpcNdRq_Queue;

	void f_pc_node_req::fpcNdRq_ToRequestQ(node_create_request *param_1) {
		SComponent::cTg_Addition(&f_pc_node_req::l_fpcNdRq_Queue, param_1);
		f_pc_layer::fpcLy_ToCancelQ(param_1->mpLayer, &param_1->mpMtdTag);
		f_pc_layer::fpcLy_CreatingMesg(param_1->mpLayer);
	}

	int f_pc_node_req::fpcNdRq_DoPhase(node_create_request *param_1) {
		int iVar1;

		iVar1 = SComponent::cPhs_Handler(&param_1->mPhs, param_1->mPhsHnd, param_1);
		if (iVar1 == 2) {
			iVar1 = f_pc_node_req::fpcNdRq_DoPhase(param_1);
		}
		return iVar1;
	}

	int f_pc_node_req::fpcNdRq_Execute(node_create_request *param_1) {
		int iVar1;

		iVar1 = f_pc_node_req::fpcNdRq_DoPhase(param_1);
		if (iVar1 != 3) {
			if (iVar1 < 3) {
				if (1 < iVar1) {
					return iVar1;
				}
				if (iVar1 < 0) {
					return iVar1;
				}
				return 0;
			}
			if (iVar1 != 5) {
				if (4 < iVar1) {
					return iVar1;
				}
				return 2;
			}
		}
		return 3;
	}

	undefined4 f_pc_node_req::fpcNdRq_Handler(void) {
		int iVar1;
		node_create_request *pnVar2;
		node_list_class *pNd;

		pNd = (node_list_class *)f_pc_node_req::l_fpcNdRq_Queue.mpHead;
		do {
			while (true) {
				while (true) {
					if (pNd == (node_list_class *)0x0) {
						return 1;
					}
					pnVar2 = (node_create_request *)pNd[1].mpHead;
					iVar1 = (*pnVar2->mpSubMtd)(pnVar2);
					if (iVar1 != 4)
						break;
					if (pNd == (node_list_class *)0x0) {
						pNd = (node_list_class *)0x0;
					} else {
						pNd = (node_list_class *)pNd->mSize;
					}
					iVar1 = f_pc_node_req::fpcNdRq_Delete(pnVar2);
					if (iVar1 == 0) {
						return 0;
					}
				}
				if (3 < iVar1)
					break;
				if (2 < iVar1)
					goto LAB_8003f62c;
			LAB_8003f684:
				if (pNd == (node_list_class *)0x0) {
					pNd = (node_list_class *)0x0;
				} else {
					pNd = (node_list_class *)pNd->mSize;
				}
			}
			if (5 < iVar1)
				goto LAB_8003f684;
		LAB_8003f62c:
			if (pNd == (node_list_class *)0x0) {
				pNd = (node_list_class *)0x0;
			} else {
				pNd = (node_list_class *)pNd->mSize;
			}
			iVar1 = f_pc_node_req::fpcNdRq_Cancel(pnVar2);
			if (iVar1 == 0) {
				return 0;
			}
		} while (true);
	}

	undefined4 f_pc_node_req::fpcNdRq_IsPossibleTarget(process_node_class *param_1) {
		base_process_class *pbVar1;
		node_create_request *pRq;
		create_request *pcVar2;

		pRq = (node_create_request *)f_pc_node_req::l_fpcNdRq_Queue.mpHead;
		while (true) {
			if (pRq == (node_create_request *)0x0) {
				return 1;
			}
			pcVar2 = pRq->mpTagData;
			pbVar1 = pcVar2->mpRes;
			if ((((pbVar1 == (base_process_class *)0x2) || (pbVar1 == (base_process_class *)0x4)) ||
				 (pbVar1 == (base_process_class *)0x1)) &&
				// TODO: press X to doubt
				(pcVar2[1].mpData == (undefined *)param_1->mBsPcId))
				break;
			if (pRq == (node_create_request *)0x0) {
				pRq = (node_create_request *)0x0;
			} else {
				pRq = (node_create_request *)pRq->mpNextNode;
			}
		}
		return 0;
	}

	undefined4 f_pc_node_req::fpcNdRq_IsIng(process_node_class *param_1) {
		node_create_request *pReq;

		pReq = (node_create_request *)f_pc_node_req::l_fpcNdRq_Queue.mpHead;
		while (true) {
			if (pReq == (node_create_request *)0x0) {
				return 0;
			}
			// TODO: DOUBT
			if (pReq->mpTagData[1].mpTagData == (create_request *)param_1->mBsPcId)
				break;
			if (pReq == (node_create_request *)0x0) {
				pReq = (node_create_request *)0x0;	// truly enterprise
			} else {
				pReq = (node_create_request *)pReq->mpNextNode;
			}
		}
		return 1;
	}

	byte init$2323;
	int request_id$2322;

	byte clear$2321[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00};

	int fpcNdRq_Cancel(node_create_request *param_1) {
		int iVar1;

		if ((!param_1->mpSubMtd) ||
			(iVar1 = f_pc_method::fpcMtd_Method(param_1->mpSubMtd[1], param_1), iVar1 != 0)) {
			iVar1 = f_pc_node_req::fpcNdRq_Delete(param_1);
		} else {
			iVar1 = 0;
		}
		return iVar1;
	}

	node_create_request *fpcNdRq_Create(int param_1) {
		byte *pbVar1;
		int *piVar2;
		byte *pbVar3;
		undefined **ppuVar4;
		undefined *puVar5;
		undefined4 uVar6;
		node_create_request *pRq;
		int *piVar7;
		byte *pbVar8;
		undefined **ppuVar9;
		byte *pbVar10;
		int iVar11;

		pRq = (node_create_request *)cMl::memalignB(-4, param_1);
		if (pRq) {
			if (f_pc_node_req::init$2323 == 0) {
				f_pc_node_req::request_id$2322 = 0;
				f_pc_node_req::init$2323 = 1;
			}
			// SStandard::sBs_ClearArea(pRq, param_1);
			memset(pRq, 0, param_1);
			*pRq = *(node_create_request *)f_pc_node_req::clear$2321;
			SComponent::cTg_Create((create_tag_class *)pRq, pRq);
			f_pc_method_tag::fpcMtdTg_Init(&pRq->mpMtdTag, f_pc_node_req::fpcNdRq_Cancel, pRq);
			pRq->requestid = f_pc_node_req::request_id$2322++;
		}
		return pRq;
	}

	StepFunction<void> *methods$2338[] = {
		fpcNdRq_phase_IsDeleteTiming,
		fpcNdRq_phase_Delete,
		fpcNdRq_phase_IsDeleted,
		fpcNdRq_phase_Create,
		fpcNdRq_phase_IsCreated,
		nullptr

	};

	StepFunction<void> *methods$2348[] = {
		fpcNdRq_phase_IsDeleteTiming,
		fpcNdRq_phase_Delete,
		fpcNdRq_phase_IsDeleted,
		nullptr};

	node_create_request *fpcNdRq_ChangeNode(ulong param_1, process_node_class *param_2, short param_3, void *param_4) {
		int iVar1;
		node_create_request *pRq;

		iVar1 = f_pc_node_req::fpcNdRq_IsPossibleTarget(param_2);
		if ((iVar1 == 1) && (iVar1 = f_pc_node_req::fpcNdRq_IsIng(param_2), iVar1 == 0)) {
			pRq = f_pc_node_req::fpcNdRq_Create(param_1);
			if (pRq) {
				pRq->mPhsHnd = &f_pc_node_req::methods$2338;
				pRq->mpNodeClass = param_2;
				pRq->mBsPcId = param_2->mBsPcId;
				pRq->mpLayer = param_2->mLyTg.mpLayer;
				pRq->mProcName = param_3;
				pRq->mpUserData = (undefined *)param_4;
			}
		} else {
			pRq = (node_create_request *)0x0;
		}
		return pRq;
	}

	node_create_request *fpcNdRq_DeleteNode(int param_1, process_node_class *param_2) {
		int iVar1;
		node_create_request *pnVar2;

		iVar1 = f_pc_node_req::fpcNdRq_IsPossibleTarget(param_2);
		if ((iVar1 == 1) && (iVar1 = f_pc_node_req::fpcNdRq_IsIng(param_2), iVar1 == 0)) {
			pnVar2 = f_pc_node_req::fpcNdRq_Create(param_1);
			if (pnVar2) {
				pnVar2->mPhsHnd = &f_pc_node_req::methods$2348;
				pnVar2->mpNodeClass = param_2;
				pnVar2->mBsPcId = param_2->mBsPcId;
				pnVar2->mpLayer = param_2->mLyTg.mpLayer;
			}
		} else {
			pnVar2 = (node_create_request *)0x0;
		}
		return pnVar2;
	}

	StepFunction<void> *methods$2359[] = {
		fpcNdRq_phase_Create,
		fpcNdRq_phase_IsCreated,
		nullptr, nullptr};

	node_create_request *fpcNdRq_CreateNode(ulong size, short procname, void *param_3) {
		layer_class *pLy;
		int iVar1;
		node_create_request *pnVar2;

		pLy = f_pc_layer::fpcLy_CurrentLayer();
		if ((pLy->mLayerID == 0) ||
			(iVar1 = fpcNdRq_IsPossibleTarget(pLy->mpPcNode), iVar1 != 0)) {
			pnVar2 = fpcNdRq_Create(size);
			if (pnVar2) {
				pnVar2->mPhsHnd = &methods$2359;
				if (pLy->mLayerID != 0) {
					pnVar2->mpNodeClass = pLy->mpPcNode;
					pnVar2->mBsPcId = pLy->mpPcNode->mBsPcId;
				}
				pnVar2->mpLayer = pLy;
				pnVar2->mProcName = procname;
				pnVar2->mpUserData = (undefined *)param_3;
			}
		} else {
			pnVar2 = (node_create_request *)0x0;
		}
		return pnVar2;
	}

	node_create_request *fpcNdRq_Request(ulong size, int mode, process_node_class *param_3, short procName, void *param_5, undefined *param_6) {
		node_create_request *pReq;

		if (mode == 2) {
			pReq = fpcNdRq_ChangeNode(size, param_3, procName, param_5);
		} else if (mode < 2) {
			if (mode == 0) {
				pReq = fpcNdRq_CreateNode(size, procName, param_5);
			} else if (-1 < mode) {
				pReq = fpcNdRq_DeleteNode(size, param_3);
			}
		}
		if (pReq) {
			pReq->mArg = mode;
			pReq->mpSubMtd = (StepFunction<void> **)param_6;
			fpcNdRq_ToRequestQ(pReq);
		}
		return pReq;
	}

	void fpcNdRq_RequestQTo(node_create_request *param_1) {
		f_pc_layer::fpcLy_CreatedMesg(param_1->mpLayer);
		f_pc_layer::fpcLy_CancelQTo(&param_1->mpMtdTag);
		SComponent::cTg_SingleCut(param_1);
	}

	int fpcNdRq_Delete(node_create_request *param_1) {
		StepFunction<void> *puVar1;
		int iVar2;

		fpcNdRq_RequestQTo(param_1);
		if (((!param_1->mpSubMtd) ||
			 (puVar1 = param_1->mpSubMtd[2], !puVar1)) ||
			(iVar2 = f_pc_method::fpcMtd_Method(puVar1, param_1), iVar2 != 0)) {
			cMl::free(param_1);
			iVar2 = 1;
		} else {
			iVar2 = 0;
		}
		return iVar2;
	}

}

namespace f_pc_node {
	int g_fpcNd_type;

	int g_fpcNd_IsCheckOfDeleteTiming = 1;

	process_node_class *f_pc_node::fpcNd_IsCreatingFromUnder(void *p1) {
		auto param_1 = (process_node_class *)p1;
		bool bVar2;
		uint uVar1;

		if ((param_1 == nullptr) ||
			(bVar2 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type, param_1->mSubType), bVar2)) {
			param_1 = nullptr;
		} else {
			uVar1 = f_pc_layer::fpcLy_IsCreatingMesg(&param_1->mLayer);
			if (uVar1 == 0) {
				param_1 = (process_node_class *)f_pc_layer_iter::fpcLyIt_Judge(&param_1->mLayer, (SComponent::Judge *)f_pc_node::fpcNd_IsCreatingFromUnder, 0);
			}
		}
		return param_1;
	}

	undefined4 fpcNd_IsDeleteTiming(void *param_1) {
		int iVar1;
		undefined4 uVar2;

		if ((f_pc_node::g_fpcNd_IsCheckOfDeleteTiming == 1) &&
			(f_pc_node::fpcNd_IsCreatingFromUnder(param_1))) {
			uVar2 = 0;
		} else {
			uVar2 = 1;
		}
		return uVar2;
	}
}