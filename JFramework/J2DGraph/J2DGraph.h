#pragma once

#include "J2DGrafContext.h"

namespace J2DGraph {
	void J2DFillBox(TBox2<float> *param_1, TColor param_2);
	void J2DFillBox(float param_1, float param_2, float param_3, float param_4, TColor param_5);
	void J2DDrawFrame(TBox2<float> *param_1, TColor param_2, uchar param_3);
	void J2DDrawFrame(float param_1, float param_2, float param_3, float param_4, TColor param_5, char width);
}