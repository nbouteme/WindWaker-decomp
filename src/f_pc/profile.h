#pragma once

#include <SComponent.h>

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

namespace f_pc_profile {
	extern f_pc_profile__Profile_Base *g_fpcPf_ProfileList_p[];

	f_pc_profile__Profile_Base *fpcPf_Get(short param_1);
}