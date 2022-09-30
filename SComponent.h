#pragma once

#include <doltypes.h>
#include <machine/dolphin/graphic.h>

enum fopAc_ac_c__Type {
	Regular = 0x0,
	Link = 0x1,
	Enemy = 0x2,
	Wildlife_and_misc = 0x3,
	Some_NPCs = 0x4,
};

enum fopAcM__Status {
	AppearsOnMiniMap = 0x20,
	DoNotExecuteIfDidNotDraw = 0x80,
	DoNotDrawIfCulled = 0x100,
	Frozen = 0x400,
	IsBeingCarried = 0x2000,
	DoesNotPause = 0x20000,
	DoNotDrawNextFrame = 0x1000000,
	IsBossOrMiniBoss = 0x4000000,
};

struct f_pc_profile__Profile_Base {
	int mLayerID;
	ushort mListID;
	ushort mListPrio;
	ushort mPName;
	profile_leaf_method_class *mpMtd0;
	int mSize;
	int mSizeOther;
	int mDefaultParameters;
	profile_method_class *mpMtd1;
};

struct f_pc_profile__Profile_Actor : public f_pc_profile__Profile_Base {
	short mDrawPriority;
	profile_method_class *mpMtd2;
	fopAcM__Status mStatus;
	fopAc_ac_c__Type mActorType;
	byte mCullType;
};

struct node_class {
	node_class *mpPrevNode;
	void *mpData;
	node_class *mpNextNode;
};

struct node_list_class {
	node_class *mpHead, *mpTail;
	int mSize;
};

struct line_tag : public create_tag_class {
	int mLineListID;
};

struct process_priority_class : public create_tag_class {
	process_method_tag_class mMtdTg;
	uint mLayerQ;
	ushort mListIDQ, mListPrioQ;
	uint mLayerCurr;
	ushort mListIDCurr, mListPrioCurr;
};

struct delete_tag_class : public create_tag_class {
	layer_class *mpLayer;
	short mTimer;
};

struct create_tag : public create_tag_class {
};

struct process_method_tag_class : public create_tag_class {
	int (*mpFunc)(void *, process_method_tag_class *);
	void *mpUserData;
};

struct create_request_method_class {
	StepFunction<void> *mpHandler;
	StepFunction<void> *mpCancel;
	StepFunction<void> *mpDelete;
};

struct node_lists_tree_class {
	node_list_class *mpLists;
	int mNumLists;
};

using fpcMtd__Method = int(void *);

struct profile_leaf_method_class {
	fpcMtd__Method *mpCreate, *mpDelete, *mpExecute, *mpIsDelete, *mpDraw;
};

struct profile_method_class : public profile_leaf_method_class {
	fpcMtd__Method *func1, *func2, *func3;
};

struct process_node_class : public base_process_class {
	profile_method_class *mpMtd;
	layer_class mLayer;
	node_list_class mLayerNodeLists[16];
};

struct layer_class : public node_class {
	uint mLayerID;
	node_lists_tree_class mNodeListTree;
	process_node_class *mpPcNode;
	node_list_class mCancelList;
	short mCreatingCount;
	short mDeletingCount;
};

struct layer_management_tag_class : public create_tag_class {
	layer_class *mpLayer;
	short mNodeListID;
	short mNodeListIdx;
};

struct base_process_class {
	uint mBsType;	  // 0
	uint mBsPcId;	  // 4
	short mProcName;  // 8
	byte field3_0xa;  // a
	byte mPauseFlag;
	byte mInitState;
	byte unk2;
	short mBsTypeId;
	f_pc_profile__Profile_Actor *mpProf;
	create_request *mpCtRq;
	layer_management_tag_class mLyTg;
	line_tag mLnTg;
	delete_tag_class mDtTg;
	process_priority_class mPi;
	profile_method_class *mpPcMtd;
	void *mpUserData;
	int mParameters;
	int mSubType;
};

struct create_request : public create_tag {
	byte mbIsCreating;
	byte field2_0x15;
	process_method_tag_class mMtdTg;
	create_request_method_class *mpCtRqMtd;
	void *unk;
	int mBsPcId;
	base_process_class *mpRes;
	layer_class *mpLayer;
};

struct create_tag_class : public node_class {
	create_request *mpTagData;
	byte mbAdded;
};

template <typename T = void, typename U = int>
using StepFunction = U(T *);

struct request_of_phase_process_class {
	StepFunction<void> **mpTbl;
	int mStep;
};

struct node_create_request : public create_tag_class {
	process_method_tag_class mpMtdTag;
	request_of_phase_process_class mPhs;
	StepFunction<void> **mPhsHnd;
	StepFunction<void> **mpSubMtd;
	int mArg;
	int requestid;
	process_node_class *mpNodeClass;
	int mBsPcId;
	layer_class *mpLayer;
	int mRqId;
	short mProcName;
	//
	//
	void *mpUserData;
	//
};

struct request_base_class {
	byte mFlags;
	short field2_0x2;
};

enum PhaseState {
	cPhs_UNCOMPLEATE_e = 0x1,
	cPhs_COMPLEATE_e = 0x4,
	cPhs_ERROR_e = 0x5,
	cPhs_NEXT_e = 0x6
};

namespace SComponent {
	using Judge = void *(node_class *, void *);
	using Method = int(node_class *, void *);
	struct judge_filter {
		Judge *a;
		void *b;
	};

	struct method_filter {
		Method *a;
		void *b;
	};

	extern int g_Counter, g_DiffCounter;
	extern MTX34 mtx;
	extern MTX34 *calc_mtx;
	using DrawCallback = void(void);
	extern DrawCallback *drawmethods[];
	extern auto PTR_mDoGph_BeforeOfDraw_803950e0 = m_Do_graphic::mDoGph_BeforeOfDraw;
	extern auto PTR_mDoGph_AfterOfDraw_803950e4 = m_Do_graphic::mDoGph_AfterOfDraw;

	void *cTgIt_JudgeFilter(create_tag_class *param_1, judge_filter *param_2);

	// Requests
	void cReq_Done(request_base_class *param_1);
	undefined4 cReq_Is_Done(request_base_class *param_1);
	void cReq_Create(request_base_class *param_1, undefined4 param_2);
	void cReq_Command(request_base_class *param_1, undefined4 param_2);

	// Phases
	void cPhs_Reset(request_of_phase_process_class *param_1);
	void cPhs_Set(request_of_phase_process_class *param_1, void *param_2);
	PhaseState cPhs_Compleate(request_of_phase_process_class *param_1);
	void cPhs_UnCompleate(request_of_phase_process_class *param_1);
	PhaseState cPhs_Next(request_of_phase_process_class *param_1);
	int cPhs_Do(request_of_phase_process_class *param_1, void *param_2);
	int cPhs_Handler(request_of_phase_process_class *param_1, StepFunction<void> **param_2, void *param_3);

	// Nodes (Nd)
	void cNd_Join(node_class *param_1, node_class *param_2);
	int cNd_LengthOf(node_class *param_1);
	node_class *cNd_First(node_class *param_1);
	node_class *cNd_Last(node_class *param_1);
	node_class *cNd_Order(node_class *param_1, int param_2);
	void cNd_SingleCut(node_class *param_1);
	void cNd_Cut(node_class *param_1);
	void cNd_Addition(node_class *param_1, node_class *param_2);
	void cNd_Insert(node_class *param_1, node_class *param_2);
	void cNd_SetObject(node_class *param_1, void *param_2);
	void cNd_ClearObject(node_class *param_1);
	void cNd_Create(node_class *param_1, void *param_2);
	// evaluates a function on each node, returns 1 if end reached without issue or 0 if an issue occured. an issue occurs if param_2 return 0
	int cNdIt_Method(node_class *param_1, Method *param_2, void *param_3);
	// evaluates a function on each node, the first non-null evaluated value, could be used to return pointers hence void*
	void *cNdIt_Judge(node_class *param_1, Judge *param_2, void *param_3);

	// List (Ls)

	void cLs_Init(node_list_class *param_1);
	void *cLs_Create(node_list_class *param_1);
	undefined4 cLsIt_Method(node_list_class *param_1, Method *param_2, void *param_3);
	void *cLsIt_Judge(node_list_class *param_1, Judge *param_2, void *param_3);
	void cLs_SingleCut(node_class *param_1);
	node_class *cLs_GetFirst(node_list_class *pList);
	create_tag_class *cTg_GetFirst(node_list_class *param_1);
	int cTr_Addition(node_lists_tree_class *param_1, int param_2, node_class *param_3);
	int cTr_Insert(node_lists_tree_class *param_1, int param_2, node_class *param_3, int param_4);
	int cTg_InsertToTree(node_lists_tree_class *param_1, int param_2, create_tag_class *param_3, int param_4);
	int cTg_AdditionToTree(node_lists_tree_class *param_1, int param_2, create_tag_class *param_3);
	int cTg_Addition(node_list_class *param_1, create_tag_class *param_2);
	void cTr_Create(node_lists_tree_class *param_1, node_list_class *param_2, int param_3);
	int cLs_Addition(node_list_class *param_1, node_class *param_2);
	int cLs_Insert(node_list_class *param_1, int param_2, node_class *param_3);
	void cNd_ForcedClear(node_class *s);

	// createTag
	void cTg_Create(create_tag_class *param_1, void *param_2);
	int cTg_SingleCut(create_tag_class *param_1);
	int cTg_IsUse(create_tag_class *param_1);

	// Trees
	void *cTrIt_Judge(node_lists_tree_class *pTree, Judge *param_2, void *param_3);
	undefined4 cTrIt_Method(node_lists_tree_class *param_1, Method param_2, void *param_3);
	int cTgIt_MethodCall(create_tag_class *param_1, method_filter *param_2);
	void cCt_Counter(int param_1);
	void cTr_SingleCut(node_class *param_1);
	bool cTg_SingleCutFromTree(create_tag_class *param_1);
	void MtxInit(void);

	void cAPIGph_Painter(void);
	void cAPIGph_BeforeOfDraw(void);
	void cAPIGph_AfterOfDraw(void);
}