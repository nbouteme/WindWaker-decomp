#include <JFramework/JUtility/JUTTexture.h>
#include <common/dDlst.h>
#include <machine/dolphin/graphic.h>

ResTIMG *dDlst_list_c::mToonImage;
ResTIMG *dDlst_list_c::mToonExImage;

undefined4 dDlst_peekZ_c::newData(short param_1, short param_2, u32 *param_3) {
	dDlst_peekZ_c__Entry *pdVar1;

	if (0x3f < (byte)this->mCount) {
		return 0;
	}
	pdVar1 = this->mEntries + (byte)this->mCount;
	pdVar1->mX = param_1;
	pdVar1->mY = param_2;
	pdVar1->mpDest = param_3;
	this->mCount = this->mCount + '\x01';
	return 1;
}

void dDlst_peekZ_c::peekData() {
	int iVar1;
	dDlst_peekZ_c__Entry *pdVar2;

	pdVar2 = this->mEntries;
	for (iVar1 = 0; iVar1 < this->mCount; iVar1 = iVar1 + 1) {
#ifdef DOLPHIN
		gx::GXPeekZ(pdVar2->mX, pdVar2->mY, pdVar2->mpDest);
#else
// read depth from framebuffer
#endif
		pdVar2 = pdVar2 + 1;
	}
	this->mCount = 0;
}

void dDlst_list_c::reset() {
	// TODO
}

void dDlst_list_c::set(dDlst_base_c ***pLst, dDlst_base_c ***pEnd,
					   dDlst_base_c *pPacket) {
	if (*pEnd <= *pLst) {
		return;
	}
	**pLst = pPacket;
	*pLst = *pLst + 1;
}

dDlst_2D_c::dDlst_2D_c(ResTIMG *texture, short w, short h, byte alpha) {
	picture.initiate(texture, nullptr);
	this->w = w;
	this->h = h;
	this->alpha = alpha;
}

void dDlst_2D_c::draw() {
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

void dDlst_list_c::draw(dDlst_base_c **pBegin, dDlst_base_c **pEnd) {
	while (pBegin < pEnd) {
		(*pBegin)->draw();
		pBegin++;
	}
}