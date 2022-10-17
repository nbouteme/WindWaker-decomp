#pragma once

#include <doltypes.h>

struct J3DTransformInfo {
	TVec3<float> mScale;
	TVec3<short> mRot;
	TVec3<float> mTranslation;
};

struct J3DAnmBase {
	byte mLoopMode;
	short mDuration;
	float mCurrentTime;
	virtual ~J3DAnmBase() {}
};

struct J3DAnmTransform : J3DAnmBase {
	virtual ~J3DAnmTransform() {}
};

struct J3DAnmTransformKey : J3DAnmTransform {
	virtual void calcTransform(float param_1, ushort param_2, J3DTransformInfo *param_3) {
	}

	virtual void getTransform(ushort p1, J3DTransformInfo *p2) {
		calcTransform(mCurrentTime, p1, p2);
	}
	virtual ~J3DAnmTransformKey() {}
};
