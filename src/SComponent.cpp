#include "SComponent.h"

namespace SComponent {

	void *cTgIt_JudgeFilter(create_tag_class *param_1, judge_filter *param_2) {
		return param_2->a(param_1, param_2->b);
	}

	// Requests
	void cReq_Done(request_base_class *param_1) {
		// wut
		param_1->mFlags = param_1->mFlags & 0x7f;
		param_1->mFlags = param_1->mFlags & 0xbf | 0x40;  // mark done and not yet acknowledged?
		param_1->mFlags = param_1->mFlags & 0xc0;
	}

	undefined4 cReq_Is_Done(request_base_class *param_1) {
		if ((param_1->mFlags >> 6 & 1) == 1) {
			param_1->mFlags = param_1->mFlags & 0xbf;  // acknowledge?
			return 1;
		}
		return 0;
	}
	void cReq_Create(request_base_class *param_1, undefined4 param_2) {
		param_1->mFlags = param_1->mFlags & 0x7f | 0x80;
		param_1->mFlags = param_1->mFlags & 0xbf;
		param_1->mFlags = (byte)param_2 & 0x3f | param_1->mFlags & 0xc0;
	}

	void cReq_Command(request_base_class *param_1, undefined4 param_2) {
		cReq_Create(param_1, param_2);
	}

	// Phases

	void cPhs_Reset(request_of_phase_process_class *param_1) {
		param_1->mStep = 0;
	}

	void cPhs_Set(request_of_phase_process_class *param_1, void *param_2) {
		param_1->mpTbl = (StepFunction<void> **)param_2;
		param_1->mStep = 0;
	}

	PhaseState cPhs_Compleate(request_of_phase_process_class *param_1) {
		param_1->mpTbl = nullptr;
		return cPhs_COMPLEATE_e;
	}

	void cPhs_UnCompleate(request_of_phase_process_class *param_1) {
		param_1->mpTbl = nullptr;
		cPhs_Reset(param_1);
	}

	PhaseState cPhs_Next(request_of_phase_process_class *param_1) {
		bool bVar1;
		PhaseState PVar2;

		if (param_1->mpTbl == 0) {
			PVar2 = cPhs_COMPLEATE_e;
		} else {
			param_1->mStep = param_1->mStep + 1;
			bVar1 = param_1->mpTbl[param_1->mStep] == nullptr;
			if ((bVar1) || (bVar1)) {
				PVar2 = cPhs_Compleate(param_1);
			} else {
				PVar2 = cPhs_UNCOMPLEATE_e;
			}
		}
		return PVar2;
	}

	int cPhs_Do(request_of_phase_process_class *param_1, void *param_2) {
		PhaseState PVar1;
		int ret;

		if (!param_1->mpTbl) {
			return cPhs_Compleate(param_1);
		}
		ret = (*param_1->mpTbl[param_1->mStep])(param_2);
		if (ret == 3) {
			cPhs_UnCompleate(param_1);
			ret = 3;
		} else if (ret < 3) {
			if (ret == 1) {
				ret = cPhs_Next(param_1);
			} else if (0 < ret) {
				PVar1 = cPhs_Next(param_1);
				ret = cPhs_COMPLEATE_e;
				if (PVar1 == 1) {
					ret = 2;
				}
			}
		} else if (ret == cPhs_ERROR_e) {
			cPhs_UnCompleate(param_1);
			ret = 5;
		} else if (ret < 5) {
			ret = cPhs_Compleate(param_1);
		}

		return ret;
	}

	int cPhs_Handler(request_of_phase_process_class *param_1, StepFunction<void> **param_2, void *param_3) {
		PhaseState PVar1;

		param_1->mpTbl = param_2;
		return cPhs_Do(param_1, param_3);
	}

	// Nodes (Nd)

	void cNd_Join(node_class *param_1, node_class *param_2) {
		param_1->mpNextNode = param_2;
		param_2->mpPrevNode = param_1;
	}

	int cNd_LengthOf(node_class *param_1) {
		int iVar1;

		iVar1 = 0;
		while (param_1) {
			iVar1 = iVar1 + 1;
			if (param_1 == nullptr) {
				param_1 = nullptr;
			} else {
				param_1 = param_1->mpNextNode;
			}
		}
		return iVar1;
	}

	node_class *cNd_First(node_class *param_1) {
		node_class *pnVar1;

		pnVar1 = nullptr;
		while (param_1) {
			pnVar1 = param_1;
			if (param_1 == nullptr) {
				param_1 = nullptr;
			} else {
				param_1 = param_1->mpPrevNode;
			}
		}
		return pnVar1;
	}

	node_class *cNd_Last(node_class *param_1) {
		node_class *pnVar1;

		pnVar1 = nullptr;
		while (param_1) {
			pnVar1 = param_1;
			if (param_1 == nullptr) {
				param_1 = nullptr;
			} else {
				param_1 = param_1->mpNextNode;
			}
		}
		return pnVar1;
	}

	node_class *cNd_Order(node_class *param_1, int param_2) {
		node_class *pnVar1;
		int iVar2;

		iVar2 = 0;
		pnVar1 = nullptr;
		while ((iVar2 < param_2 && (param_1))) {
			iVar2 = iVar2 + 1;
			pnVar1 = param_1;
			if (param_1 == nullptr) {
				param_1 = nullptr;
			} else {
				param_1 = param_1->mpNextNode;
			}
		}
		if (iVar2 < param_2) {
			return pnVar1;
		}
		return nullptr;
	}

	void cNd_SingleCut(node_class *param_1) {
		node_class *pnVar1;

		pnVar1 = param_1->mpNextNode;
		if (param_1->mpPrevNode) {
			param_1->mpPrevNode->mpNextNode = pnVar1;
		}
		if (pnVar1) {
			pnVar1->mpPrevNode = param_1->mpPrevNode;
		}
		param_1->mpPrevNode = nullptr;
		param_1->mpNextNode = nullptr;
	}

	void cNd_Cut(node_class *param_1) {
		if (param_1->mpPrevNode) {
			param_1->mpPrevNode->mpNextNode = nullptr;
		}
		param_1->mpPrevNode = nullptr;
	}

	void cNd_Addition(node_class *param_1, node_class *param_2) {
		node_class *pnVar1;

		pnVar1 = cNd_Last(param_1);
		cNd_Join(pnVar1, param_2);
	}

	void cNd_Insert(node_class *param_1, node_class *param_2) {
		node_class *pnVar1;

		pnVar1 = param_1->mpPrevNode;
		if (pnVar1 == nullptr) {
			cNd_Addition(param_2, param_1);
		} else {
			cNd_Cut(param_1);
			cNd_Addition(pnVar1, param_2);
			cNd_Addition(param_2, param_1);
		}
	}

	void cNd_SetObject(node_class *param_1, void *param_2) {
		while (param_1) {
			param_1->mpData = (undefined *)param_2;
			if (param_1 == nullptr) {
				param_1 = nullptr;
			} else {
				param_1 = param_1->mpNextNode;
			}
		}
	}

	void cNd_ClearObject(node_class *param_1) {
		cNd_SetObject(param_1, (void *)0x0);
	}

	void cNd_Create(node_class *param_1, void *param_2) {
		param_1->mpPrevNode = nullptr;
		param_1->mpNextNode = nullptr;
		param_1->mpData = (undefined *)param_2;
	}

	// evaluates a function on each node, returns 1 if end reached without issue or 0 if an issue occured. an issue occurs if param_2 return 0
	int cNdIt_Method(node_class *param_1, Method *param_2, void *param_3) {
		int iVar1;
		node_class *pnVar2;
		undefined4 uVar3;

		uVar3 = 1;
		if (param_1 == (node_class *)0x0) {
			pnVar2 = (node_class *)0x0;
		} else {
			pnVar2 = param_1->mpNextNode;
		}
		while (param_1 != (node_class *)0x0) {
			iVar1 = (*param_2)(param_1, param_3);
			if (iVar1 == 0) {
				uVar3 = 0;
			}
			param_1 = pnVar2;
			if (pnVar2 == (node_class *)0x0) {
				pnVar2 = (node_class *)0x0;
			} else {
				pnVar2 = pnVar2->mpNextNode;
			}
		}
		return uVar3;
	}

	// evaluates a function on each node, the first non-null evaluated value, could be used to return pointers hence void*
	void *cNdIt_Judge(node_class *param_1, Judge *param_2, void *param_3) {
		void *iVar1;
		node_class *pnVar2;

		if (param_1 == nullptr) {
			pnVar2 = nullptr;
		} else {
			pnVar2 = param_1->mpNextNode;
		}
		while (true) {
			if (param_1 == nullptr) {
				return 0;
			}
			iVar1 = param_2(param_1, param_3);
			if (iVar1 != 0)
				break;
			param_1 = pnVar2;
			if (pnVar2 == nullptr) {
				pnVar2 = nullptr;
			} else {
				pnVar2 = pnVar2->mpNextNode;
			}
		}
		return iVar1;
	}

	// List (Ls)

	void cLs_Init(node_list_class *param_1) {
		param_1->mpHead = nullptr;
		param_1->mpTail = nullptr;
		param_1->mSize = 0;
	}

	void *cLs_Create(node_list_class *param_1) {
		cLs_Init(param_1);
		return param_1;
	}

	undefined4 cLsIt_Method(node_list_class *param_1, Method *param_2, void *param_3) {
		undefined4 uVar1;

		if (param_1->mSize < 1) {
			uVar1 = 1;
		} else {
			uVar1 = cNdIt_Method(param_1->mpHead, param_2, param_3);
		}
		return uVar1;
	}

	void *cLsIt_Judge(node_list_class *param_1, Judge *param_2, void *param_3) {
		void *pvVar1;

		if (param_1->mSize < 1) {
			pvVar1 = (void *)0x0;
		} else {
			pvVar1 = (void *)cNdIt_Judge(param_1->mpHead, param_2, param_3);
		}
		return pvVar1;
	}

	void cLs_SingleCut(node_class *param_1) {
		uint uVar1;
		node_list_class *pnVar2;

		pnVar2 = (node_list_class *)param_1->mpData;
		if (param_1 == pnVar2->mpHead) {
			pnVar2->mpHead = param_1->mpNextNode;
		}
		if (param_1 == pnVar2->mpTail) {
			pnVar2->mpTail = param_1->mpPrevNode;
		}
		cNd_SingleCut(param_1);
		cNd_ClearObject(param_1);
		uVar1 = pnVar2->mSize - 1;
		pnVar2->mSize = uVar1;
	}

	node_class *cLs_GetFirst(node_list_class *pList) {
		node_class *pnVar1;

		if (pList->mSize == 0) {
			pnVar1 = nullptr;
		} else {
			pnVar1 = pList->mpHead;
			cLs_SingleCut(pnVar1);
		}
		return pnVar1;
	}

	create_tag_class *cTg_GetFirst(node_list_class *param_1) {
		create_tag_class *pTag;

		pTag = (create_tag_class *)cLs_GetFirst(param_1);
		if (pTag == (create_tag_class *)0x0) {
			pTag = (create_tag_class *)0x0;
		} else {
			pTag->mbAdded = 0;
		}
		return pTag;
	}

	int cTr_Addition(node_lists_tree_class *param_1, int param_2, node_class *param_3)

	{
		int iVar1;

		if (param_2 < param_1->mNumLists) {
			iVar1 = cLs_Addition(param_1->mpLists + param_2, param_3);
		} else {
			iVar1 = 0;
		}
		return iVar1;
	}

	int cTr_Insert(node_lists_tree_class *param_1, int param_2, node_class *param_3, int param_4)

	{
		int iVar1;

		if (param_2 < param_1->mNumLists) {
			iVar1 = cLs_Insert(param_1->mpLists + param_2, param_4, param_3);
		} else {
			iVar1 = 0;
		}
		return iVar1;
	}

	int cTg_InsertToTree(node_lists_tree_class *param_1, int param_2, create_tag_class *param_3, int param_4)

	{
		int iVar1;

		if ((param_3->mbAdded == 0) &&
			(iVar1 = cTr_Insert(param_1, param_2, param_3, param_4), iVar1 != 0)) {
			param_3->mbAdded = 1;
		} else {
			iVar1 = 0;
		}
		return iVar1;
	}

	int cTg_AdditionToTree(node_lists_tree_class *param_1, int param_2, create_tag_class *param_3)

	{
		int iVar1;

		if ((param_3->mbAdded == 0) &&
			(iVar1 = cTr_Addition(param_1, param_2, param_3), iVar1 != 0)) {
			param_3->mbAdded = 1;
		} else {
			iVar1 = 0;
		}
		return iVar1;
	}

	int cTg_Addition(node_list_class *param_1, create_tag_class *param_2) {
		int iVar1;

		if ((param_2->mbAdded == 0) &&
			(iVar1 = cLs_Addition(param_1, param_2), iVar1 != 0)) {
			param_2->mbAdded = 1;
		} else {
			iVar1 = 0;
		}
		return iVar1;
	}

	void cTr_Create(node_lists_tree_class *param_1, node_list_class *param_2, int param_3) {
		bool bVar1;

		param_1->mpLists = param_2;
		param_1->mNumLists = param_3;
		while (bVar1 = 0 < param_3, param_3 = param_3 + -1, bVar1) {
			cLs_Create(param_2);
			param_2 = param_2 + 1;
		}
		return;
	}

	int cLs_Addition(node_list_class *param_1, node_class *param_2) {
		node_class *pnVar1;
		int iVar2;

		if (param_1->mpTail == nullptr) {
			param_1->mpHead = param_2;
		} else {
			cNd_Addition(param_1->mpTail, param_2);
		}
		pnVar1 = cNd_Last(param_2);
		param_1->mpTail = pnVar1;
		cNd_SetObject(param_2, param_1);
		iVar2 = cNd_LengthOf(param_1->mpHead);
		param_1->mSize = iVar2;
		return param_1->mSize;
	}

	int cLs_Insert(node_list_class *param_1, int param_2, node_class *param_3) {
		node_class *pnVar1;
		int iVar2;

		pnVar1 = cNd_Order(param_1->mpHead, param_2);
		if (pnVar1 == nullptr) {
			iVar2 = cLs_Addition(param_1, param_3);
		} else {
			cNd_SetObject(param_3, param_1);
			cNd_Insert(pnVar1, param_3);
			pnVar1 = cNd_First(param_3);
			param_1->mpHead = pnVar1;
			iVar2 = cNd_LengthOf(param_1->mpHead);
			param_1->mSize = iVar2;
			iVar2 = param_1->mSize;
		}
		return iVar2;
	}

	void cNd_ForcedClear(node_class *s) {
		s->mpNextNode = s->mpPrevNode = nullptr;
		s->mpData = nullptr;
	}

	// createTag
	void cTg_Create(create_tag_class *param_1, void *param_2) {
		cNd_Create(param_1, (void *)0x0);
		param_1->mpTagData = (create_request *)param_2;
		param_1->mbAdded = 0;
	}

	int cTg_SingleCut(create_tag_class *param_1) {
		bool bVar1;

		bVar1 = param_1->mbAdded == 1;
		if (bVar1) {
			param_1->mbAdded = 0;
			cLs_SingleCut(param_1);
		}
		return (uint)bVar1;
	}

	int cTg_IsUse(create_tag_class *param_1) {
		return (int)param_1->mbAdded;
	}

	// Trees
	void *cTrIt_Judge(node_lists_tree_class *pTree, Judge *param_2, void *param_3) {
		bool bVar1;
		void *pvVar2;
		int iVar3;
		node_list_class *pnVar4;

		iVar3 = pTree->mNumLists;
		pnVar4 = pTree->mpLists;
		do {
			bVar1 = iVar3 < 1;
			iVar3 = iVar3 + -1;
			if (bVar1) {
				return (void *)0x0;
			}
			pvVar2 = cLsIt_Judge(pnVar4, param_2, param_3);
			pnVar4 = pnVar4 + 1;
		} while (pvVar2 == (void *)0x0);
		return pvVar2;
	}

	undefined4 cTrIt_Method(node_lists_tree_class *param_1, Method param_2, void *param_3) {
		bool bVar1;
		int iVar2;
		undefined4 uVar3;
		int iVar4;
		node_list_class *pnVar5;
		node_list_class *pnVar6;

		iVar4 = param_1->mNumLists;
		uVar3 = 1;
		pnVar6 = param_1->mpLists;
		while (bVar1 = 0 < iVar4, iVar4 = iVar4 + -1, bVar1) {
			pnVar5 = pnVar6 + 1;
			iVar2 = cLsIt_Method(pnVar6, param_2, param_3);
			pnVar6 = pnVar5;
			if (iVar2 == 0) {
				uVar3 = 0;
			}
		}
		return uVar3;
	}

	int cTgIt_MethodCall(create_tag_class *param_1, method_filter *param_2) {
		return param_2->a(param_1->mpTagData, param_2->b);
	}

	int g_Counter, g_DiffCounter;

	void cCt_Counter(int param_1) {
		if (param_1 == 1) {
			g_DiffCounter = 0;
		} else {
			g_DiffCounter++;
		}
		g_Counter++;
	}

	void cTr_SingleCut(node_class *param_1) {
		cLs_SingleCut(param_1);
	}

	bool cTg_SingleCutFromTree(create_tag_class *param_1) {
		bool bVar1;

		bVar1 = param_1->mbAdded == 1;
		if (bVar1) {
			param_1->mbAdded = 0;
			cTr_SingleCut(param_1);
		}
		return bVar1;
	}

	MTX34 mtx;
	MTX34 *calc_mtx;

	void MtxInit(void) {
		calc_mtx = &mtx;
	}

	// my guess is that they had some kind of build time abstraction layer

	using DrawCallback = void(void);
	DrawCallback *drawmethods[] = {
		m_Do_graphic::mDoGph_Painter,
		m_Do_graphic::mDoGph_BlankingON,
		m_Do_graphic::mDoGph_BlankingOFF,
	};

	void cAPIGph_Painter(void) {
		drawmethods[0]();
	}

	undefined4 (*PTR_mDoGph_BeforeOfDraw_803950e0)() = m_Do_graphic::mDoGph_BeforeOfDraw;
	undefined4 (*PTR_mDoGph_AfterOfDraw_803950e4)() = m_Do_graphic::mDoGph_AfterOfDraw;

	void cAPIGph_BeforeOfDraw(void) {
		(*PTR_mDoGph_BeforeOfDraw_803950e0)();
	}

	void cAPIGph_AfterOfDraw(void) {
		(*PTR_mDoGph_AfterOfDraw_803950e4)();
	}
}