#pragma once

#include "J2DGrafContext.h"

void C_MTXOrtho(MTX44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f);

struct J2DOrthoGraph : public J2DGrafContext {
	TBox2<float> mOrtho;
	float mNearZ, mFarZ;

	J2DOrthoGraph();

	virtual void setLookat();
	void scissorBounds(TBox2<float> *param_1, TBox2<float> *param_2);
	J2DOrthoGraph(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6);
	virtual void setPort();
	void setOrtho(TBox2<float> *param_1, float param_2, float param_3);
	virtual J2DTypeID getGrafType();
};