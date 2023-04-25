#include "J2DPane.h"

#include <JFramework/JSupport/JSUIosBase.h>
#include <dolphin/mtx.h>

#include "../J2DGraph/J2DOrthoGraph.h"

void J2DPane::update() {}
void J2DPane::drawSelf(float, float) {}
void J2DPane::drawSelf(MTX34, float, float) {}
int J2DPane::getTypeID() { return 0x10; }
void J2DPane::setConnectParent(bool) {
	mConnectParent = 0;
}
void J2DPane::resize(float xd, float yd) {
	this->mPos.mBR[0] = this->mPos.mTL[0] + xd;
	this->mPos.mBR[1] = this->mPos.mTL[1] + yd;
}

void J2DPane::add(float a, float b) {
	move(mPos.mTL[0] + a, mPos.mTL[1] + b);
}

void J2DPane::calcMtx() {
	if (!mParentLink.mpList)
		return;
	makeMatrix(mPos.mTL[0], mPos.mTL[1]);
}

void J2DPane::initiate() {
	(this->mBasePosition).x = 0.0;
	(this->mBasePosition).y = 0.0;
	this->mRotationAxis = 'z';
	this->mRotation = 0.0;
	this->mCullMode = 0;
	this->mAlpha = 0xff;
	this->mBlendMode = 1;
	this->mDrawAlpha = 0xff;
	this->mConnectParent = 0;
	calcMtx();
}

void J2DPane::move(float param_1, float param_2) {
	float fVar1;
	float fVar2;
	float fVar3;
	float fVar4;

	fVar1 = this->mPos.mBR[0];
	fVar2 = this->mPos.mTL[0];
	fVar3 = this->mPos.mBR[1];
	fVar4 = this->mPos.mTL[1];
	this->mPos.mTL[0] = param_1;
	this->mPos.mTL[1] = param_2;
	this->mPos.mBR[0] = param_1 + (fVar1 - fVar2);
	this->mPos.mBR[1] = param_2 + (fVar3 - fVar4);
	calcMtx();
}

void J2DPane::clip(TBox2<float> *param_1) {
	float fVar1;
	float fVar2;
	float fVar3;
	float fVar4;

	fVar1 = this->mScreenPos.mTL[0];
	fVar2 = this->mScreenPos.mTL[1];
	fVar3 = param_1->mTL[0] + fVar1;
	fVar4 = param_1->mTL[1] + fVar2;
	fVar1 = param_1->mBR[0] + fVar1;
	fVar2 = param_1->mBR[1] + fVar2;
	if (this->mBox.mTL[0] <= fVar3) {
		this->mBox.mTL[0] = fVar3;
	}
	if (this->mBox.mTL[1] <= fVar4) {
		this->mBox.mTL[1] = fVar4;
	}
	if (fVar1 <= this->mBox.mBR[0]) {
		this->mBox.mBR[0] = fVar1;
	}
	if (this->mBox.mBR[1] >= fVar2) {
		this->mBox.mBR[1] = fVar2;
	}
}

J2DPane::J2DPane() : mParentLink(this) {
	this->mChildList.initiate();
	this->mMagic = 0x50414e31;
	this->mbDraw = 1;
	this->mName = 0;
	this->mPos.mTL[0] = 0.0;
	this->mPos.mTL[1] = 0.0;
	this->mPos.mBR[0] = 0.0;
	this->mPos.mBR[1] = 0.0;
	initiate();
}

J2DPane::J2DPane(ulong param_1, TBox2<float> *param_2) : mParentLink(this) {
	this->mChildList.initiate();
	this->mMagic = 0x50414e31;
	this->mbDraw = 1;
	this->mName = param_1;
	this->mPos = *param_2;
	initiate();
}

uint J2DPane::insertChild(J2DPane *param_1, J2DPane *param_2) {
	uint uVar1;
	JSUPtrLink *pJVar2;
	JSUPtrLink *pJVar3;

	if ((!param_1) || (!param_2)) {
		uVar1 = 0;
	} else {
		pJVar3 = (JSUPtrLink *)&param_2->mChildList;
		if (pJVar3) {
			pJVar3 = &param_2->mParentLink;
		}
		if (!param_1) {
			pJVar2 = nullptr;
		} else {
			pJVar2 = (JSUPtrLink *)&param_1->mChildList;
		}
		if (pJVar2) {
			pJVar2 = pJVar2->mpNext;
		}
		uVar1 = this->mChildList.insert(pJVar2, pJVar3);
		if ((uVar1 & 0xff) != 0) {
			param_2->calcMtx();
		}
	}
	return uVar1;
}

J2DPane::J2DPane(J2DPane *pParentPane, JSURandomInputStream *pStream) : mParentLink(this) {
	int iVar1;
	int local_18[2];

	this->mChildList.initiate();
	iVar1 = pStream->getPosition();
	pStream->read(local_18, 8);
	this->mMagic = local_18[0];
	makePaneStream(pParentPane, pStream);
	pStream->seekPos(iVar1 + local_18[1], 0);
}

J2DPane::J2DPane(J2DPane *param_1, bool param_2, ulong param_3, TBox2<float> *param_4) : mParentLink(this) {
	JSUPtrLink *pLink;

	this->mChildList.initiate();
	this->mMagic = 0x50414e31;
	this->mbDraw = param_2;
	this->mName = param_3;
	mPos = *param_4;
	if (param_1) {
		pLink = (JSUPtrLink *)&this->mChildList;
		if (pLink) {
			pLink = &this->mParentLink;
		}
		param_1->mChildList.append(pLink);
	}
	initiate();
}

void J2DPane::setBasePosition(J2DBasePosition param_1) {
	this->m2DBasePosition = (byte)param_1;
	if ((int)param_1 % 3 == 0) {
		(this->mBasePosition).x = 0.0;
	} else if ((int)param_1 % 3 == 1) {
		(this->mBasePosition).x = ((this->mPos.mBR)[0] - (this->mPos.mTL)[0]) * 0.5;
	} else {
		(this->mBasePosition).x = (this->mPos.mBR)[0] - (this->mPos.mTL)[0];
	}
	if ((int)param_1 / 3 == 0) {
		(this->mBasePosition).y = 0.0;
	} else if ((int)param_1 / 3 == 1) {
		(this->mBasePosition).y = ((this->mPos.mBR)[1] - (this->mPos.mTL)[1]) * 0.5;
	} else {
		(this->mBasePosition).y = (this->mPos.mBR)[1] - (this->mPos.mTL)[1];
	}
	this->mRotationAxis = 'z';
	calcMtx();
}

J2DPane::~J2DPane() {
	// TODO: delete children?
}

void J2DPane::makeMatrix(float x, float y) {
	float fVar1;
	undefined4 uVar2;
	double dVar3;
	double dVar4;
	undefined8 in_f30;
	undefined8 in_f31;
	MTX34 MStack184;
	MTX34 MStack136;
	MTX34 MStack88;
	undefined auStack24[16];
	undefined auStack8[8];

	dVar4 = (double)y;
	dVar3 = (double)x;
	uVar2 = 0;

	if (this->mRotation == 0.0) {
		mtx::MTXTrans(this->mMtx, dVar3, dVar4, 0.0);
	} else {
		mtx::MTXTrans(MStack88, -(double)(this->mBasePosition).x, -(double)(this->mBasePosition).y, 0.0);
		if (this->mRotationAxis == 'z') {
			fVar1 = -this->mRotation;
		} else {
			fVar1 = this->mRotation;
		}
		mtx::MTXRotRad(MStack136, this->mRotationAxis, fVar1 * 0.01745329);
		mtx::MTXTrans(MStack184, (double)(float)((double)(this->mBasePosition).x + dVar3),
					  (double)(float)((double)(this->mBasePosition).y + dVar4), 0.0);
		mtx::MTXConcat(MStack136, MStack88, this->mMtx);
		mtx::MTXConcat(MStack184, this->mMtx, this->mMtx);
	}
}

void J2DPane::makePaneStream(J2DPane *pParentPane, JSURandomInputStream *pStream) {
	JSUPtrLink *pLink;
	undefined4 uVar1;
	double x2;
	double y;
	double x;
	char local_78;
	byte alpha;
	byte basePos;
	char local_75;
	ushort local_74;
	int local_68;

	short hs;
	short ws;
	short ys;
	short xs;
	short local_6a;
	undefined4 local_60;
	uint uStack92;
	undefined4 local_58;
	uint uStack84;
	undefined4 local_50;
	uint uStack76;
	undefined4 local_48;
	uint uStack68;
	undefined auStack40[16];
	undefined auStack24[16];
	undefined auStack8[8];

	uVar1 = 0;
	pStream->read(&local_75, 1);
	pStream->read(&this->mbDraw, 1);
	pStream->skip(2);
	pStream->read(&local_68, 4);
	this->mName = local_68;
	pStream->read(&xs, 2);
	x = xs;
	pStream->read(&ys, 2);
	y = ys;
	pStream->read(&ws, 2);
	x2 = x + ws;
	pStream->read(&hs, 2);
	(this->mPos.mTL)[0] = (float)x;
	(this->mPos.mTL)[1] = (float)y;
	(this->mPos.mBR)[0] = (float)x2;
	(this->mPos.mBR)[1] = y + hs;
	local_75 = local_75 + -6;
	this->mRotation = 0.0;
	if (local_75) {
		pStream->read(&local_74, 2);
		this->mRotation = (float)local_74;
		local_75 = local_75 + -1;
	}
	if (local_75 == '\0') {
		setBasePosition(0);
	} else {
		pStream->read(&basePos, 1);
		setBasePosition((uint)basePos);
		local_75 = local_75 + -1;
	}
	this->mAlpha = 0xff;
	if (local_75) {
		pStream->read(&alpha, 1);
		this->mAlpha = alpha;
		local_75 = local_75 + -1;
	}
	this->mBlendMode = 1;
	if (local_75) {
		pStream->read(&local_78, 1);
		this->mBlendMode = 1 - (local_78 == '\0');
		local_75 = local_75 + -1;
	}
	pStream->align(4);
	if (pParentPane) {
		pLink = (JSUPtrLink *)&this->mChildList;
		if (pLink) {
			pLink = &this->mParentLink;
		}
		pParentPane->mChildList.append(pLink);
	}
	this->mCullMode = 0;
	this->mDrawAlpha = 0xff;
	this->mConnectParent = 0;
	calcMtx();
}

void J2DPane::draw(float param_1, float param_2, struct J2DGrafContext *pCtx, bool bClip) {
	float *pfVar1;
	float fVar2;
	bool bVar3;
	float fVar4;
	JSUPtrList *pJVar5;
	float *pfVar6;
	float *pfVar7;
	JSUPtrLink *pJVar8;
	J2DPane *pParentPane;
	int iVar9;
	undefined4 uVar10;
	double dVar11;
	double dVar12;
	undefined8 in_f30;
	undefined8 in_f31;
	TBox2<float> local_108;
	undefined auStack24[16];
	undefined auStack8[8];

	dVar12 = (double)param_2;
	dVar11 = (double)param_1;
	uVar10 = 0;
	struct J2DGrafContext ctx = *pCtx;

	iVar9 = pCtx->getGrafType();
	if (iVar9 != 1) {
		bClip = false;
	}
	pJVar5 = (this->mParentLink).mpList;
	pParentPane = nullptr;
	if (pJVar5) {
		pParentPane = (J2DPane *)pJVar5[1].mpHead;
	}
	if (this->mbDraw) {
		bVar3 = false;
		if (((this->mPos.mTL)[0] <= (this->mPos.mBR)[0]) && ((this->mPos.mTL)[1] <= (this->mPos.mBR)[1])) {
			bVar3 = true;
		}
		if (bVar3) {
			mScreenPos = mPos;
			mBox = mPos;
			if (!pParentPane) {
				this->mScreenPos.mTL[0] += dVar11;
				this->mScreenPos.mTL[1] += dVar12;
				this->mScreenPos.mBR[0] += dVar11;
				this->mScreenPos.mBR[1] += dVar12;
				makeMatrix((this->mPos.mTL[0] + dVar11),
						   (this->mPos.mTL[1] + dVar12));
				mtx::MTXCopy(this->mMtx, this->mDrawMtx);
				mBox = mScreenPos;
				this->mDrawAlpha = this->mAlpha;
			} else {
				this->mScreenPos.mTL[0] += pParentPane->mScreenPos.mTL[0];
				this->mScreenPos.mTL[1] += pParentPane->mScreenPos.mTL[1];
				this->mScreenPos.mBR[0] += pParentPane->mScreenPos.mTL[0];
				this->mScreenPos.mBR[1] += pParentPane->mScreenPos.mTL[1];
				mtx::MTXConcat(pParentPane->mDrawMtx, this->mMtx, this->mDrawMtx);
				if (bClip) {
					fVar4 = pParentPane->mScreenPos.mTL[0];
					fVar2 = pParentPane->mScreenPos.mTL[1];
					this->mBox.mTL[0] += fVar4;
					this->mBox.mTL[1] += fVar2;
					this->mBox.mBR[0] += fVar4;
					this->mBox.mBR[1] += fVar2;
					fVar4 = pParentPane->mBox.mTL[0];
					if ((this->mBox).mTL[0] <= fVar4) {
						(this->mBox).mTL[0] = fVar4;
					}
					fVar4 = (pParentPane->mBox).mTL[1];
					if ((this->mBox).mTL[1] <= fVar4) {
						(this->mBox).mTL[1] = fVar4;
					}
					fVar4 = (pParentPane->mBox).mBR[0];
					if (fVar4 <= (this->mBox).mBR[0]) {
						(this->mBox).mBR[0] = fVar4;
					}
					fVar4 = (pParentPane->mBox).mBR[1];
					if (fVar4 <= (this->mBox).mBR[1]) {
						(this->mBox).mBR[1] = fVar4;
					}
				}
				this->mDrawAlpha = this->mAlpha;
				if (this->mBlendMode) {
					this->mDrawAlpha = (byte)(((uint)this->mAlpha * (uint)pParentPane->mDrawAlpha) / 0xff);
				}
			}
			local_108.mTL[0] = 0.0;
			local_108.mTL[1] = 0.0;
			local_108.mBR[0] = 0.0;
			local_108.mBR[1] = 0.0;
			if (bClip) {
				((struct J2DOrthoGraph *)pCtx)->scissorBounds(&local_108, &this->mBox);
			}
			bVar3 = false;
			if (((this->mBox).mTL[0] <= (this->mBox).mBR[0]) && ((this->mBox).mTL[1] <= (this->mBox).mBR[1])) {
				bVar3 = true;
			}
			if ((bVar3) || (bClip == false)) {
				ctx.place(&this->mScreenPos);
				if (bClip) {
					ctx.scissor(&local_108);
					ctx.setScissor();
				}
#ifdef DOLPHIN
				gx::GXSetCullMode((gx::GXCullMode)this->mCullMode);
#else
// not sure why a 2D ui library care about culling mode...
#endif
				drawSelf(ctx.mMtx, dVar11, dVar12);
				auto abbab = this->mChildList.mpHead;  // points to a mParentLink
				J2DPane *clist;
				// TODO: probably incorrect
				if (abbab) {
					clist = my_container_of(abbab, J2DPane, mParentLink);
				}
				while (abbab) {
					clist->draw(0.0, 0.0, pCtx, bClip);
					abbab = abbab->mpNext;
					if (abbab) {
						clist = my_container_of(abbab, J2DPane, mParentLink);
					}
				}
			}
		}
	}
}
