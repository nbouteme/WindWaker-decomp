#include <dolphin/mtx.h>

#include <cmath>

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

	void MTXCopy(const Mtx src, Mtx dst) {
		ASSERTMSG((src != 0), MTX_COPY_1);
		ASSERTMSG((dst != 0), MTX_COPY_2);

		if (src == dst) {
			return;
		}

		dst[0][0] = src[0][0];
		dst[0][1] = src[0][1];
		dst[0][2] = src[0][2];
		dst[0][3] = src[0][3];

		dst[1][0] = src[1][0];
		dst[1][1] = src[1][1];
		dst[1][2] = src[1][2];
		dst[1][3] = src[1][3];

		dst[2][0] = src[2][0];
		dst[2][1] = src[2][1];
		dst[2][2] = src[2][2];
		dst[2][3] = src[2][3];
	}

	void MTXRotRad(Mtx m, char axis, f32 rad) {
		f32 sinA, cosA;

		ASSERTMSG((m != 0), MTX_ROTDEG_1);

		// verification of "axis" will occur in MTXRotTrig

		sinA = sinf(rad);
		cosA = cosf(rad);

		MTXRotTrig(m, axis, sinA, cosA);
	}

	void MTXRotTrig(Mtx m, char axis, f32 sinA, f32 cosA) {
		ASSERTMSG((m != 0), MTX_ROTTRIG_1);

		switch (axis) {
		case 'x':
		case 'X':
			m[0][0] = 1.0f;
			m[0][1] = 0.0f;
			m[0][2] = 0.0f;
			m[0][3] = 0.0f;
			m[1][0] = 0.0f;
			m[1][1] = cosA;
			m[1][2] = -sinA;
			m[1][3] = 0.0f;
			m[2][0] = 0.0f;
			m[2][1] = sinA;
			m[2][2] = cosA;
			m[2][3] = 0.0f;
			break;

		case 'y':
		case 'Y':
			m[0][0] = cosA;
			m[0][1] = 0.0f;
			m[0][2] = sinA;
			m[0][3] = 0.0f;
			m[1][0] = 0.0f;
			m[1][1] = 1.0f;
			m[1][2] = 0.0f;
			m[1][3] = 0.0f;
			m[2][0] = -sinA;
			m[2][1] = 0.0f;
			m[2][2] = cosA;
			m[2][3] = 0.0f;
			break;

		case 'z':
		case 'Z':
			m[0][0] = cosA;
			m[0][1] = -sinA;
			m[0][2] = 0.0f;
			m[0][3] = 0.0f;
			m[1][0] = sinA;
			m[1][1] = cosA;
			m[1][2] = 0.0f;
			m[1][3] = 0.0f;
			m[2][0] = 0.0f;
			m[2][1] = 0.0f;
			m[2][2] = 1.0f;
			m[2][3] = 0.0f;
			break;

		default:
			ASSERTMSG(0, MTX_ROTTRIG_2);
			break;
		}
	}

	void MTXIdentity(Mtx m) {
		ASSERTMSG((m != 0), MTX_IDENTITY_1);

		m[0][0] = 1.0f;
		m[0][1] = 0.0f;
		m[0][2] = 0.0f;
		m[0][3] = 0.0f;

		m[1][0] = 0.0f;
		m[1][1] = 1.0f;
		m[1][2] = 0.0f;
		m[1][3] = 0.0f;

		m[2][0] = 0.0f;
		m[2][1] = 0.0f;
		m[2][2] = 1.0f;
		m[2][3] = 0.0f;
	}

	void MTXConcat(const Mtx a, const Mtx b, Mtx ab) {
		Mtx mTmp;
		MtxPtr m;

		ASSERTMSG((a != 0), MTX_CONCAT_1);
		ASSERTMSG((b != 0), MTX_CONCAT_2);
		ASSERTMSG((ab != 0), MTX_CONCAT_3);

		if ((ab == a) || (ab == b)) {
			m = mTmp;
		}

		else {
			m = ab;
		}

		// compute (a x b) -> m

		m[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0];
		m[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1];
		m[0][2] = a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2];
		m[0][3] = a[0][0] * b[0][3] + a[0][1] * b[1][3] + a[0][2] * b[2][3] + a[0][3];

		m[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0];
		m[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1];
		m[1][2] = a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2];
		m[1][3] = a[1][0] * b[0][3] + a[1][1] * b[1][3] + a[1][2] * b[2][3] + a[1][3];

		m[2][0] = a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0];
		m[2][1] = a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1];
		m[2][2] = a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2];
		m[2][3] = a[2][0] * b[0][3] + a[2][1] * b[1][3] + a[2][2] * b[2][3] + a[2][3];

		// overwrite a or b if needed
		if (m == mTmp) {
			MTXCopy(mTmp, ab);
		}
	}

	void MTXTrans(Mtx m, f32 xT, f32 yT, f32 zT) {
		ASSERTMSG((m != 0), MTX_TRANS_1);

		m[0][0] = 1.0f;
		m[0][1] = 0.0f;
		m[0][2] = 0.0f;
		m[0][3] = xT;
		m[1][0] = 0.0f;
		m[1][1] = 1.0f;
		m[1][2] = 0.0f;
		m[1][3] = yT;
		m[2][0] = 0.0f;
		m[2][1] = 0.0f;
		m[2][2] = 1.0f;
		m[2][3] = zT;
	}

}