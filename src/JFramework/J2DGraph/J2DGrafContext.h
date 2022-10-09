#pragma once

#include "../../dolphin/gx.h"

union Color {
	unsigned int rgba;
	struct {
		byte r, g, b, a;
	};
};

using TColor = Color *;

template <typename T>
struct TBox2 {
	T mTL[2];
	T mBR[2];
};

struct cXy {
	float x, y;
};

using MTX44 = float[4][4];
using MTX34 = float[3][4];

enum J2DTypeID {
	J2DGrafContext,
	J2DOrthoGraph
};

void C_MTXIdentity(MTX34 m);

struct J2DGrafContext {
	TBox2<float> mViewport;
	TBox2<float> mScissor;
	gx::GXColor mColorTL, mColorTR, mColorBR, mColorBL;
	byte mLineWidth;
	cXy mLastPoint;
	MTX44 mProj;
	MTX34 mMtx;
	byte a, b, c;
	byte mLineBlendMode, mLineBlendSrc, mLineBlendDst;
	gx::GXBlendMode mBoxBlendMode;
	gx::GXBlendFactor mBoxBlendSrc, mBoxBlendDst;
	byte d, e, f;

	virtual void setScissor();
	virtual void setup2D();
	virtual void setPort();
	virtual void place(TBox2<float> *pPos);
	virtual void place(float param_1, float param_2, float param_3, float param_4);
	virtual J2DTypeID getGrafType();
	virtual void setLookat();
	void fillBox(TBox2<float> *param_1);
	void setColor(TColor param_1, TColor param_2, TColor param_3, TColor param_4);
	void setLineWidth(byte param_1);
	void drawFrame(TBox2<float> *param_1);
	void scissor(TBox2<float> *param_1);
	J2DGrafContext(float param_1, float param_2, float param_3, float param_4);
};