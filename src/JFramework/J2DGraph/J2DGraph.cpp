#include "J2DGraph.h"
#include "J2DOrthoGraph.h"

namespace J2DGraph {
	void J2DFillBox(TBox2<float> *param_1, TColor param_2) {
		struct J2DOrthoGraph local_e4;
		local_e4.setColor(param_2, param_2, param_2, param_2);
		local_e4.fillBox(param_1);
	}

	void J2DFillBox(float param_1, float param_2, float param_3, float param_4, TColor param_5) {
		TBox2<float> box;

		box.mTL[0] = param_1;
		box.mTL[1] = param_2;
		box.mBR[0] = (param_1 + param_3);
		box.mBR[1] = (param_2 + param_4);
		J2DFillBox(&box, param_5);
	}

	void J2DDrawFrame(TBox2<float> *param_1, TColor param_2, uchar param_3) {
		struct J2DOrthoGraph local_e4;
		local_e4.setColor(param_2, param_2, param_2, param_2);
		local_e4.setLineWidth(param_3);
		local_e4.drawFrame(param_1);
	}

	void J2DDrawFrame(float param_1, float param_2, float param_3, float param_4, TColor param_5, char width) {
		TBox2<float> box;

		box.mTL[0] = param_1;
		box.mTL[1] = param_2;
		box.mBR[0] = (param_1 + param_3);
		box.mBR[1] = (param_2 + param_4);
		J2DDrawFrame(&box, param_5, width);
	}
}