#pragma once

#include <SComponent.h>

struct f_pc_profile__Profile_Base {
	int mLayerID;
	ushort mListID;
	ushort mListPrio;
	ushort mPName;
	profile_leaf_method_class *mpMtd0;
	// above here was probably its own struct, and below is specialized for leafs
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

struct f_pc_profile__Profile_Scene : f_pc_profile__Profile_Base {
	profile_leaf_method_class *mpMtd15;
};

#define MAKE_SCENE(id, type, layer, list, prio) \
	f_pc_profile__Profile_Scene {               \
		layer, list, prio, id,                  \
			&f_pc_node::g_fpcNd_Method,         \
			sizeof(type), 0, 0,                 \
			&f_op_scene::g_fopScn_Method,       \
			&type::methods                      \
	}

#define MAKE_PROFILE_METHODS(name)                     \
	{                                          \
		(fpcMtd__Method *)name##_Create,       \
			(fpcMtd__Method *)name##_Delete,   \
			(fpcMtd__Method *)name##_Execute,  \
			(fpcMtd__Method *)name##_IsDelete, \
			(fpcMtd__Method *)name##_Draw      \
	}

namespace f_pc_profile {
	extern f_pc_profile__Profile_Base **g_fpcPf_ProfileList_p;
	f_pc_profile__Profile_Base *fpcPf_Get(short param_1);
}