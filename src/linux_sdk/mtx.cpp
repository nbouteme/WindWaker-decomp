#include <dolphin/mtx.h>

namespace mtx {
	void C_MTXOrtho(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f) {
		f32 tmp;

		tmp = 1.0f / (r - l);
		m[0][0] = 2.0f * tmp;
		m[0][1] = 0.0f;
		m[0][2] = 0.0f;
		m[0][3] = -(r + l) * tmp;

		tmp = 1.0f / (t - b);
		m[1][0] = 0.0f;
		m[1][1] = 2.0f * tmp;
		m[1][2] = 0.0f;
		m[1][3] = -(t + b) * tmp;

		m[2][0] = 0.0f;
		m[2][1] = 0.0f;

		tmp = 1.0f / (f - n);
#ifdef EPPC
		// scale z to (-1, 0) range for Dolphin
		m[2][2] = -(1.0f) * tmp;
		m[2][3] = -(f)*tmp;
#else
		m[2][2] = -(2.0f) * tmp;
		m[2][3] = -(f + n) * tmp;
#endif
		m[3][0] = 0.0f;
		m[3][1] = 0.0f;
		m[3][2] = 0.0f;
		m[3][3] = 1.0f;
	}

}