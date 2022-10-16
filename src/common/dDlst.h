#pragma once

#include <JFramework/J2D/J2DPicture.h>
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

struct dDlst_list_c {
	static ResTIMG *mToonImage;
	static ResTIMG *mToonExImage;
	dDlst_peekZ_c mPeekZ;

	dDlst_base_c **mp2DOpa;
	dDlst_base_c **mp2DOpaEnd;

	void reset();

	void set(dDlst_base_c ***pLst, dDlst_base_c ***pEnd,
			 dDlst_base_c *pPacket) {
		if (*pEnd <= *pLst) {
			return;
		}
		**pLst = pPacket;
		*pLst = *pLst + 1;
	}
};

struct ResTIMG;

struct dDlst_2D_c : dDlst_base_c {
	J2DPicture picture;
	short w, h;
	byte alpha;

	dDlst_2D_c(ResTIMG *texture, short w, short h, byte alpha) {
		picture.initiate(texture, nullptr);
		this->w = w;
		this->h = h;
		this->alpha = alpha;
	}

	void draw() {
		ResTIMG *pRVar1;

		this->picture.mAlpha = this->alpha;
		if (this->picture.mNumTexture != 0) {
			pRVar1 = this->picture.mpTexture[0]->mpTIMG;
			this->picture.draw(
				this->w,
				this->h,
				pRVar1->mWidth,
				pRVar1->mHeight,
				false, false, false);
		}
	}
};