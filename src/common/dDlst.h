#pragma once

#include <JFramework/J2D/J2DPicture.h>
#include <JFramework/J3D/J3DDrawBuffer.h>
#include <dolphin/gx.h>

struct dDlst_peekZ_c__Entry {
	short mX, mY;
	u32 *mpDest;
};

struct dDlst_peekZ_c {
	char mCount;
	dDlst_peekZ_c__Entry mEntries[50];	// apparently 64?

	undefined4 newData(short param_1, short param_2, u32 *param_3);

	void peekData();
};

struct dDlst_base_c {
	virtual void draw() {}
	virtual ~dDlst_base_c() {}
};

template <int N>
struct dDlist_bound {
	dDlst_base_c *buffer[N];
	dDlst_base_c *current;
	dDlst_base_c *end;
};

struct dDlst_list_c {
	static ResTIMG *mToonImage;
	static ResTIMG *mToonExImage;

	J3DDrawBuffer
		*mpBufSkyOpa,
		*mpBufSkyXlu,
		*mpLinkBuf,
		*linkBodyBuffOpa,
		*linkBodyBuffTranslu,
		*mpBufWorldOpa,
		*mpBufWorldXlu,
		*mpBufInvisibleModelOpa,
		*mpBufInvisibleModelXlu,
		*mpWetherFxBuffer,
		*mpBufInvisibleModelMaskOffOpa,
		*mpBufInvisibleModelMaskOffXlu,
		*mpBufDistortionOpa,
		*mpBufDistortionXlu,
		*titleScreenBuff;

	dDlist_bound<4> list_a;
	dDlist_bound<16> list_b;
	dDlist_bound<64> mp2DArr;
	dDlist_bound<32> list_c;

	dDlst_peekZ_c mPeekZ;
	dDlst_base_c **mp2DOpa;
	dDlst_base_c **mp2DOpaEnd;

	void reset();
	void draw(dDlst_base_c **pBegin, dDlst_base_c **pEnd);
	void set(dDlst_base_c ***pLst, dDlst_base_c ***pEnd, dDlst_base_c *pPacket);

	template <int N>
	void add(dDlist_bound<N> &e, dDlst_base_c *pPacket) {
		set(&e.buffer, &e.current, pPacket);
	}

	template <int N>
	void draw(dDlist_bound<N> &e) {
		draw(&e.buffer[0], &e.current);
	}
};

struct ResTIMG;

struct dDlst_2D_c : dDlst_base_c {
	J2DPicture picture;
	short w, h;
	byte alpha;

	dDlst_2D_c(ResTIMG *texture, short w, short h, byte alpha);

	void draw();
};