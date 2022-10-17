#include <SComponent/c_malloc.h>

#include <cstring>

#include "deletor.h"
#include "executor.h"
#include "layer.h"
#include "method.h"
#include "node.h"
#include "stdcreate.h"

namespace f_pc_node_req {
	node_list_class l_fpcNdRq_Queue;

	void fpcNdRq_ToRequestQ(node_create_request *param_1) {
		SComponent::cTg_Addition(&l_fpcNdRq_Queue, param_1);
		f_pc_layer::fpcLy_ToCancelQ(param_1->mpLayer, &param_1->mpMtdTag);
		f_pc_layer::fpcLy_CreatingMesg(param_1->mpLayer);
	}

	int fpcNdRq_DoPhase(node_create_request *param_1) {
		int iVar1;

		iVar1 = SComponent::cPhs_Handler(&param_1->mPhs, param_1->mPhsHnd, param_1);
		if (iVar1 == 2) {
			iVar1 = fpcNdRq_DoPhase(param_1);
		}
		return iVar1;
	}

	int fpcNdRq_Execute(node_create_request *param_1) {
		int iVar1;

		iVar1 = fpcNdRq_DoPhase(param_1);
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

	undefined4 fpcNdRq_Handler(void) {
		int iVar1;
		node_create_request *pnVar2;
		node_list_class *pNd;

		pNd = (node_list_class *)l_fpcNdRq_Queue.mpHead;
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
					iVar1 = fpcNdRq_Delete(pnVar2);
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
			iVar1 = fpcNdRq_Cancel(pnVar2);
			if (iVar1 == 0) {
				return 0;
			}
		} while (true);
	}

	undefined4 fpcNdRq_IsPossibleTarget(process_node_class *param_1) {
		int iVar1;
		node_create_request *pRq;
		node_create_request *pnVar2;

		pRq = (node_create_request *)f_pc_node_req::l_fpcNdRq_Queue.mpHead;
		while (true) {
			if (pRq == (node_create_request *)0x0) {
				return 1;
			}
			pnVar2 = pRq->mpTagData;
			iVar1 = pnVar2->mArg;
			if ((((iVar1 == 2) || (iVar1 == 4)) || (iVar1 == 1)) &&
				(pnVar2->mBsPcId == param_1->mBsPcId))
				break;
			if (pRq)
				pRq = (node_create_request *)pRq->mpNextNode;
		}
		return 0;
	}

	undefined4 fpcNdRq_IsIng(process_node_class *param_1) {
		node_create_request *pReq;

		pReq = (node_create_request *)f_pc_node_req::l_fpcNdRq_Queue.mpHead;
		while (true) {
			if (pReq == (node_create_request *)0x0) {
				return 0;
			}
			if ((pReq->mpTagData)->mRqId == param_1->mBsPcId)
				break;
			if (pReq == (node_create_request *)0x0) {
				pReq = (node_create_request *)0x0;
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
			iVar1 = fpcNdRq_Delete(param_1);
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
			if (init$2323 == 0) {
				request_id$2322 = 0;
				init$2323 = 1;
			}
			// SStandard::sBs_ClearArea(pRq, param_1);
			memset(pRq, 0, param_1);
			*pRq = *(node_create_request *)clear$2321;
			SComponent::cTg_Create((create_tag_class *)pRq, pRq);
			f_pc_method_tag::fpcMtdTg_Init(&pRq->mpMtdTag, fpcNdRq_Cancel, pRq);
			pRq->requestid = request_id$2322++;
		}
		return pRq;
	}

	int fpcNdRq_phase_IsDeleteTiming(node_create_request *) {
		return 2;
	}

	int fpcNdRq_phase_Delete(node_create_request *param_1) {
		int iVar1;

		if (param_1->mpNodeClass != (process_node_class *)0x0) {
			iVar1 = f_pc_deletor::fpcDt_Delete(param_1->mpNodeClass);
			if (iVar1 == 0) {
				return 0;
			}
			param_1->mpNodeClass = (process_node_class *)0x0;
		}
		return 2;
	}

	int fpcNdRq_phase_IsDeleted(node_create_request *param_1) {
		int iVar1;

		iVar1 = f_pc_deletor::fpcDt_IsComplete();
		return ~-(iVar1 == 0) & 2;	// wut
	}

	int fpcNdRq_phase_Create(node_create_request *param_1) {
		uint uVar1;
		int id;

		id = f_pc_stdcreate_req::fpcSCtRq_Request(param_1->mpLayer, param_1->mProcName, *(undefined **)(param_1->mpSubMtd + 0xc),
												  param_1, param_1->mpUserData);
		param_1->mRqId = id;
		uVar1 = __builtin_clz(-1 - param_1->mRqId);
		return (uVar1 >> 5) + 2;
	}

	int fpcNdRq_phase_IsCreated(node_create_request *param_1) {
		int iVar1;

		iVar1 = f_pc_create_req::fpcCtRq_IsCreatingByID(param_1->mRqId);
		if (iVar1 == 1) {
			iVar1 = 0;
		} else {
			iVar1 = f_pc_executor::fpcEx_IsExist(param_1->mRqId);
			iVar1 = 3 - (uint)(iVar1 == 1);
		}
		return iVar1;
	}

	StepFunction<node_create_request> *methods$2338[] = {
		fpcNdRq_phase_IsDeleteTiming,
		fpcNdRq_phase_Delete,
		fpcNdRq_phase_IsDeleted,
		fpcNdRq_phase_Create,
		fpcNdRq_phase_IsCreated,
		nullptr

	};

	StepFunction<node_create_request> *methods$2348[] = {
		fpcNdRq_phase_IsDeleteTiming,
		fpcNdRq_phase_Delete,
		fpcNdRq_phase_IsDeleted,
		nullptr};

	node_create_request *fpcNdRq_ChangeNode(ulong param_1, process_node_class *param_2, short param_3, void *param_4) {
		int iVar1;
		node_create_request *pRq;

		iVar1 = fpcNdRq_IsPossibleTarget(param_2);
		if ((iVar1 == 1) && (iVar1 = fpcNdRq_IsIng(param_2), iVar1 == 0)) {
			pRq = fpcNdRq_Create(param_1);
			if (pRq) {
				pRq->mPhsHnd = (int (**)(void *)) & methods$2338;
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

		iVar1 = fpcNdRq_IsPossibleTarget(param_2);
		if ((iVar1 == 1) && (iVar1 = fpcNdRq_IsIng(param_2), iVar1 == 0)) {
			pnVar2 = fpcNdRq_Create(param_1);
			if (pnVar2) {
				pnVar2->mPhsHnd = (int (**)(void *)) & methods$2348;
				pnVar2->mpNodeClass = param_2;
				pnVar2->mBsPcId = param_2->mBsPcId;
				pnVar2->mpLayer = param_2->mLyTg.mpLayer;
			}
		} else {
			pnVar2 = (node_create_request *)0x0;
		}
		return pnVar2;
	}

	StepFunction<node_create_request> *methods$2359[] = {
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
				pnVar2->mPhsHnd = (int (**)(void *)) & methods$2359;
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

	int fpcNdRq_ReChangeNode(uint param_1, short param_2, void *param_3) {
		create_tag_class *pnVar1;
		node_create_request *pcVar1;

		pnVar1 = (create_tag_class *)f_pc_node_req::l_fpcNdRq_Queue.mpHead;
		while (true) {
			if (pnVar1 == (create_tag_class *)0x0) {
				return 0;
			}
			pcVar1 = pnVar1->mpTagData;
			if ((pcVar1->mArg == 2) && (pcVar1->requestid == param_1))
				break;
			if (pnVar1 == (create_tag_class *)0x0) {
				pnVar1 = (create_tag_class *)0x0;
			} else {
				pnVar1 = (create_tag_class *)pnVar1->mpNextNode;
			}
		}
		if (pcVar1->mRqId == -2) {
			pcVar1->mProcName = param_2;
			pcVar1->mpUserData = (undefined *)param_3;
			return 1;
		}
		return 0;
	}

	int fpcNdRq_ReRequest(uint param_1, short param_2, void *param_3) {
		return fpcNdRq_ReChangeNode(param_1, param_2, param_3);
	}
}
