#pragma once

#include <JFramework/JKernel/JKRArchive.h>
#include <JFramework/JSupport/JSUIosBase.h>
#include <JFramework/JSupport/JSUPtrLink.h>
#include <JFramework/JSupport/JSUPtrList.h>
#include <machine/dolphin/graphic.h>

#include "../J2DGraph/J2DGrafContext.h"

struct JUTResReference {
	byte rtype;
	byte typelen;
	char type[4];

	void *getResource(JSUInputStream *param_1, ulong param_2, JKRArchive *param_3) {
		byte bVar1;

		param_1->read(&this->rtype, 1);
		param_1->read(&this->typelen, 1);
		param_1->read(this->type, (uint)(byte)this->typelen);
		bVar1 = this->rtype;
		if (((bVar1 == 2) || (bVar1 == 3)) || (bVar1 == 4)) {
			this->type[(byte)this->typelen] = '\0';
		}
		getResource(param_2, param_3);
	}

	void *getResource(ulong param_1, JKRArchive *param_2) {
		byte bVar1;
		void *iVar2;

		iVar2 = 0;
		bVar1 = this->rtype;
		if (bVar1 == 3) {
			iVar2 = JKRFileLoader::getGlbResource(this->type, param_2);
		} else if (bVar1 < 3) {
			if ((bVar1 != 1) && (bVar1 != 0)) {
				iVar2 = JKRArchive::getGlbResource(param_1, this->type, param_2);
			}
		} else if (bVar1 < 5) {
			iVar2 = JKRFileLoader::getGlbResource(this->type);
		}
		return iVar2;
	}
};

struct J2DPane {
	using J2DBasePosition = int;

	int mMagic;
	int mName;
	TBox2<float> mPos;
	TBox2<float> mScreenPos, mBox;
	MTX34 mMtx, mDrawMtx;
	cXy mBasePosition;
	float mRotation;
	char mRotationAxis;
	byte m2DBasePosition, mbDraw, mCullMode, mAlpha, mDrawAlpha, mBlendMode, mConnectParent;
	JSUPtrList mChildList;
	JSUPtrLink mParentLink;

	virtual void update() {}
	virtual void drawSelf(float, float) {}
	virtual void drawSelf(MTX34, float, float) {}
	virtual int getTypeID() { return 0x10; }
	virtual void setConnectParent(bool) {
		mConnectParent = 0;
	}
	virtual void resize(float xd, float yd) {
		this->mPos.mBR[0] = this->mPos.mTL[0] + xd;
		this->mPos.mBR[1] = this->mPos.mTL[1] + yd;
	}

	virtual void add(float a, float b) {
		move(mPos.mTL[0] + a, mPos.mTL[1] + b);
	}

	virtual void calcMtx() {
		if (!mParentLink.mpList)
			return;
		makeMatrix(mPos.mTL[0], mPos.mTL[1]);
	}

	void initiate() {
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

	void move(float param_1, float param_2) {
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

	void clip(TBox2<float> *param_1) {
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

	J2DPane() : mParentLink(this) {
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

	J2DPane(ulong param_1, TBox2<float> *param_2) : mParentLink(this) {
		this->mChildList.initiate();
		this->mMagic = 0x50414e31;
		this->mbDraw = 1;
		this->mName = param_1;
		this->mPos = *param_2;
		initiate();
	}

	uint insertChild(J2DPane *param_1, J2DPane *param_2) {
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

	J2DPane(J2DPane *pParentPane, JSURandomInputStream *pStream) : mParentLink(this) {
		int iVar1;
		int local_18[2];

		this->mChildList.initiate();
		iVar1 = pStream->getPosition();
		pStream->read(local_18, 8);
		this->mMagic = local_18[0];
		makePaneStream(pParentPane, pStream);
		pStream->seekPos(iVar1 + local_18[1], 0);
	}

	J2DPane(J2DPane *param_1, bool param_2, ulong param_3, TBox2<float> *param_4) : mParentLink(this) {
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

	void setBasePosition(J2DBasePosition param_1) {
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

	~J2DPane() {
		// TODO: delete children?
	}

	void makeMatrix(float x, float y) {
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
			mtx::PSMTXTrans(dVar3, dVar4, 0.0, &this->mMtx);
		} else {
			mtx::PSMTXTrans(-(double)(this->mBasePosition).x, -(double)(this->mBasePosition).y, 0.0, &MStack88);
			if (this->mRotationAxis == 'z') {
				fVar1 = -this->mRotation;
			} else {
				fVar1 = this->mRotation;
			}
			mtx::PSMTXRotRad(&MStack136, this->mRotationAxis, fVar1 * 0.01745329);
			mtx::PSMTXTrans((double)(float)((double)(this->mBasePosition).x + dVar3),
							(double)(float)((double)(this->mBasePosition).y + dVar4), 0.0, &MStack184);
			mtx::PSMTXConcat(&MStack136, &MStack88, &this->mMtx);
			mtx::PSMTXConcat(&MStack184, &this->mMtx, &this->mMtx);
		}
	}

	void makePaneStream(J2DPane *pParentPane, JSURandomInputStream *pStream) {
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

	void draw(float param_1, float param_2, struct J2DGrafContext *pCtx, bool bClip) {
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
					mtx::PSMTXCopy(&this->mMtx, &this->mDrawMtx);
					mBox = mScreenPos;
					this->mDrawAlpha = this->mAlpha;
				} else {
					this->mScreenPos.mTL[0] += pParentPane->mScreenPos.mTL[0];
					this->mScreenPos.mTL[1] += pParentPane->mScreenPos.mTL[1];
					this->mScreenPos.mBR[0] += pParentPane->mScreenPos.mTL[0];
					this->mScreenPos.mBR[1] += pParentPane->mScreenPos.mTL[1];
					mtx::PSMTXConcat(&pParentPane->mDrawMtx, &this->mMtx, &this->mDrawMtx);
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
					gx::GXSetCullMode((gx::GXCullMode)this->mCullMode);
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
};

struct ResTLUT {
	gx::GXTlutFmt mTlutFmt;
	byte mTransparency;
	short mSize;
	byte unk[28];
};

using JUTTransparency = int;
struct JUTPalette : gx::GXTlutObj {
	gx::GXTlut mTlut;
	gx::GXTlutFmt mTlutFmt;
	void *mpData;
	short mSize;
	byte mTransparency;

	bool load() {
		bool bVar1;

		bVar1 = this->mSize != 0;
		if (bVar1) {
			gx::GXLoadTlut(this, this->mTlut);
		}
		return bVar1;
	}

	void storeTLUT(gx::GXTlut param_1, gx::GXTlutFmt param_2, JUTTransparency param_3, ushort param_4, void *param_5) {
		this->mTlut = param_1;
		this->mTlutFmt = param_2;
		this->mTransparency = param_3;
		this->mSize = param_4;
		this->mpData = param_5;
		gx::GXInitTlutObj(this, this->mpData, this->mTlutFmt, this->mSize);
	}

	void storeTLUT(gx::GXTlut param_1, ResTLUT *param_2) {
		if (!param_2) {
			m_Do_printf::OSPanic("JUTPalette.cpp", 0x23, "JUTTexture: TLUT is NULL\n");
		}
		this->mTlut = param_1;
		this->mTlutFmt = param_2->mTlutFmt;
		this->mTransparency = param_2->mTransparency;
		this->mSize = param_2->mSize;
		this->mpData = param_2 + 1;
		gx::GXInitTlutObj(this, this->mpData, this->mTlutFmt, this->mSize);
		return;
	}
};

struct JUTTexture : gx::GXTexObj {
	ResTIMG *mpTIMG;
	void *mpData;
	JUTPalette *mpPalette;
	JUTPalette *mpAttachedPalette;
	gx::GXTexWrapMode mWrapS;
	gx::GXTexWrapMode mWrapT;
	gx::GXTexFilter mMinFilter;
	gx::GXTexFilter mMagFilter;
	short mMinLOD;
	short mMaxLOD;
	short mLODBias;
	byte mTlut;

	int field13_0x3b;

	void load(gx::GXTexMapID param_1) {
		if (this->mpAttachedPalette) {
			this->mpAttachedPalette->load();
		}
		gx::GXLoadTexObj(this, param_1);
	}

	void attachPalette(JUTPalette *param_1) {
		if (this->mpTIMG->mbHasTlut) {
			if ((!param_1) && (this->mpPalette)) {
				this->mpAttachedPalette = this->mpPalette;
			} else {
				this->mpAttachedPalette = param_1;
			}
			initTexObj(this->mpAttachedPalette->mTlut);
		}
	}

	void initTexObj() {
		int iVar1;
		ResTIMG *pRVar2;

		pRVar2 = this->mpTIMG;
		iVar1 = 0x20;
		if (pRVar2->mTexDataOffs != 0) {
			iVar1 = pRVar2->mTexDataOffs;
		}
		gx::GXInitTexObj(this, &pRVar2->mTexFmt + iVar1,
						 pRVar2->mWidth,
						 pRVar2->mHeight,
						 pRVar2->mTexFmt,
						 this->mWrapS,
						 this->mWrapT,
						 pRVar2->mbMipmapEnabled);
		pRVar2 = this->mpTIMG;
		gx::GXInitTexObjLOD(this, this->mMinFilter, this->mMagFilter, this->mMinLOD * 0.125,
							this->mMaxLOD * 0.125, this->mLODBias / 100.0, pRVar2->mbBiasClamp,
							pRVar2->mbDoEdgeLOD, pRVar2->mMaxAniso);

		return;
	}

	void initTexObj(gx::GXTlut param_1) {
		byte bVar1;
		int iVar2;
		ResTIMG *pRVar3;

		bVar1 = this->mpTIMG->mbMipmapEnabled;
		this->mTlut = (byte)param_1;
		pRVar3 = this->mpTIMG;
		iVar2 = 0x20;
		if (pRVar3->mTexDataOffs != 0) {
			iVar2 = pRVar3->mTexDataOffs;
		}
		gx::GXInitTexObjCI(this, &pRVar3->mTexFmt + iVar2, pRVar3->mWidth, pRVar3->mHeight, (gx::GXCITexFmt)pRVar3->mTexFmt,
						   this->mWrapS, this->mWrapT, bVar1 != 0, param_1);
		pRVar3 = this->mpTIMG;
		gx::GXInitTexObjLOD(this, this->mMinFilter, this->mMagFilter, this->mMinLOD * 0.125,
							this->mMaxLOD * 0.125, this->mLODBias / 100.0, pRVar3->mbBiasClamp,
							pRVar3->mbDoEdgeLOD, pRVar3->mMaxAniso);
	}

	void storeTIMG(ResTIMG *param_1, uchar param_2) {
		ushort uVar1;
		JUTPalette *this_00;
		ResTIMG *pRVar2;
		uint uVar3;

		if ((param_1 != nullptr) && (param_2 < 0x10)) {
			this->mpTIMG = param_1;
			this->mpData = (char *)&this->mpTIMG + this->mpTIMG->mTexDataOffs;
			if (this->mpTIMG->mTexDataOffs == 0) {	// why
				this->mpData = &this->mpTIMG[1];
			}
			if ((this->field13_0x3b & 2) != 0) {
				delete this->mpPalette;
			}
			this->mpPalette = nullptr;
			this->mpAttachedPalette = nullptr;
			this->mTlut = 0;
			this->mWrapS = this->mpTIMG->mWrapS;
			this->mWrapT = this->mpTIMG->mWrapT;
			this->mMinFilter = this->mpTIMG->mMinFilter;
			this->mMagFilter = this->mpTIMG->mMagFilter;
			this->mMinLOD = (short)(char)this->mpTIMG->mbMinLOD;
			this->mMaxLOD = (short)(char)this->mpTIMG->mbMaxLOD;
			this->mLODBias = this->mpTIMG->mLODBias;
			uVar1 = this->mpTIMG->mTlutCount;
			if (uVar1 == 0) {
				initTexObj();
			} else {
				if (uVar1 < 0x101) {
					uVar3 = (uint)param_2;
				} else {
					uVar3 = (param_2 & 3) + 0x10;
				}
				this_00 = new JUTPalette();
				if (this_00 != nullptr) {
					pRVar2 = this->mpTIMG;
					this_00->storeTLUT((gx::GXTlut)uVar3, pRVar2->mTlutFmt, pRVar2->mTranslucency,
									   pRVar2->mTlutCount, &pRVar2->mTexFmt + pRVar2->mTlutDataOffs);
				}
				this->mpPalette = this_00;
				this->field13_0x3b = this->field13_0x3b & 1 | 2;
				attachPalette(this->mpPalette);
			}
		}
	}
};

struct J2DPicture : J2DPane {
	JUTTexture *mpTexture[2];
	byte mNumTexture;
	float mBlendKonstColorF[4];
	float mBlendKonstAlphaF[4];
	JUTPalette *mpPalette;
	gx::GXColor mColorBase, mBgColor, mNewColor[4], mBlendKonstColor, mBlendKonstAlpha;

	virtual int getTypeID() override {
		return 0x12;
	}

	void swap(float *param_1, float *param_2) {
		float fVar1;

		fVar1 = *param_1;
		*param_1 = *param_2;
		*param_2 = fVar1;
	}

	void changeTexture(char *param_1, byte param_2) {
		ResTIMG *pRVar1;

		pRVar1 = (ResTIMG *)JKRFileLoader::getGlbResource(param_1, 0);
		changeTexture(pRVar1, param_2);
	}

	ResTIMG *changeTexture(ResTIMG *param_1, uchar param_2) {
		byte bVar1;
		JUTTexture *pJVar2;
		ResTIMG *pRVar3;

		bVar1 = this->mNumTexture;
		if (param_2 < bVar1) {
			if (param_2 < bVar1) {
				pJVar2 = this->mpTexture[param_2];
			} else {
				pJVar2 = nullptr;
			}
			if ((pJVar2 == nullptr) || (param_1 == nullptr)) {
				pRVar3 = nullptr;
			} else {
				if (param_2 < bVar1) {
					pJVar2 = this->mpTexture[param_2];
				} else {
					pJVar2 = nullptr;
				}
				pRVar3 = pJVar2->mpTIMG;
				if (param_2 < bVar1) {
					pJVar2 = this->mpTexture[param_2];
				} else {
					pJVar2 = nullptr;
				}
				pJVar2->storeTIMG(param_1, '\0');
			}
		} else {
			pRVar3 = nullptr;
		}
		return pRVar3;
	}

	void drawOut(float param_1, float param_2, float param_3, float param_4,
				 float param_5, float param_6, float param_7, float param_8) {
		TBox2<float> local_28;
		TBox2<float> local_18;

		local_28.mBR[0] = param_5 + param_7;
		local_28.mBR[1] = param_6 + param_8;
		local_18.mBR[0] = param_1 + param_3;
		local_18.mBR[1] = param_2 + param_4;
		local_28.mTL[0] = param_5;
		local_28.mTL[1] = param_6;
		local_18.mTL[0] = param_1;
		local_18.mTL[1] = param_2;
		drawOut(&local_18, &local_28);
	}

	void drawOut(TBox2<float> *param_1, TBox2<float> *param_2) {
		using namespace gx;
		float fVar1;
		uint uVar2;
		uint uVar3;
		undefined4 uVar4;
		undefined8 in_f28;
		double dVar5;
		undefined8 in_f29;
		double dVar6;
		undefined8 in_f30;
		double dVar7;
		undefined8 in_f31;
		double dVar8;
		gx::GXColor local_e8;
		undefined4 local_e4;
		undefined4 local_e0;
		undefined4 local_dc;
		long long local_d8;
		undefined4 local_d0;
		uint uStack204;
		long long local_c8;
		undefined4 local_c0;
		uint uStack188;
		long long local_b8;
		undefined4 local_b0;
		uint uStack172;
		long long local_a8;
		undefined4 local_a0;
		uint uStack156;
		long long local_98;
		undefined4 local_90;
		uint uStack140;
		long long local_88;
		undefined4 local_80;
		uint uStack124;
		long long local_78;
		undefined4 local_70;
		uint uStack108;
		long long local_68;
		undefined4 local_60;
		uint uStack92;
		undefined auStack56[16];
		undefined auStack40[16];
		undefined auStack24[16];
		undefined auStack8[8];

		uVar4 = 0;
		if (mbDraw != 0) {
			for (uVar3 = 0; uVar2 = (uint)this->mNumTexture, (uVar3 & 0xff) < uVar2; uVar3 = uVar3 + 1) {
				if ((uVar3 & 0xff) < uVar2) {
					this->mpTexture[uVar3 & 0xff]->load((GXTexMapID)uVar3 & 0xff);
				}
			}
			gx::GXSetNumTexGens(uVar2);
			fVar1 = param_2->mBR[0] - param_2->mTL[0];
			dVar8 = (double)((param_1->mTL[0] - param_2->mTL[0]) / fVar1);
			dVar7 = (double)((param_1->mBR[0] - param_2->mBR[0]) / fVar1 + 1.0);
			fVar1 = param_2->mBR[1] - param_2->mTL[1];
			dVar6 = (double)((param_1->mTL[1] - param_2->mTL[1]) / fVar1);
			dVar5 = (double)((param_1->mBR[1] - param_2->mBR[1]) / fVar1 + 1.0);
			mDrawAlpha = mAlpha;
			local_e8 = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
			local_e4 = 0xffffffff;
			local_e0 = 0xffffffff;
			local_dc = 0xffffffff;
			getNewColor(&local_e8);
			setTevMode();
			gx::GXClearVtxDesc();
			gx::GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
			gx::GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
			gx::GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
			gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_CLR_RGBA, GX_F32, 0);
			gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_F32, 0);
			gx::GXBegin(GX_QUADS, GX_VTXFMT0, 4);

			void write_volatile_4(uint, ...);

			write_volatile_4(0xcc008000, param_1->mTL[0]);
			write_volatile_4(0xcc008000, param_1->mTL[1]);
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, local_e8);
			write_volatile_4(0xcc008000, (float)dVar8);
			write_volatile_4(0xcc008000, (float)dVar6);

			write_volatile_4(0xcc008000, param_1->mBR[0]);
			write_volatile_4(0xcc008000, param_1->mTL[1]);
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, local_e4);
			write_volatile_4(0xcc008000, (float)dVar7);
			write_volatile_4(0xcc008000, (float)dVar6);

			write_volatile_4(0xcc008000, param_1->mBR[0]);
			write_volatile_4(0xcc008000, param_1->mBR[1]);
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, local_dc);
			write_volatile_4(0xcc008000, (float)dVar7);
			write_volatile_4(0xcc008000, (float)dVar5);

			write_volatile_4(0xcc008000, param_1->mTL[0]);
			write_volatile_4(0xcc008000, param_1->mBR[1]);
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, local_e0);
			write_volatile_4(0xcc008000, (float)dVar8);
			write_volatile_4(0xcc008000, (float)dVar5);

			gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_RGBA4, 0);
			gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_CLR_RGBA, GX_RGBX8, 0xf);
			gx::GXSetNumTexGens(0);
			gx::GXSetNumTevStages(1);
			gx::GXSetTevOp(GXTevStageID::GX_TEVSTAGE0, GX_PASSCLR);
			gx::GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
			gx::GXSetVtxDesc(GX_VA_TEX0, GX_NONE);
		}
	}

	void insert(char *param_1, uchar param_2, float param_3) {
		ResTIMG *pRVar1;
		double dVar2;

		dVar2 = (double)param_3;
		pRVar1 = (ResTIMG *)JKRFileLoader::getGlbResource(param_1, 0);
		insert(pRVar1, param_2, (float)dVar2);
	}

	int field4_0xdd;

	undefined4 insert(ResTIMG *param_1, uchar param_2, float param_3) {
		ushort uVar1;
		ushort uVar2;
		uint uVar3;
		undefined4 uVar4;
		JUTTexture *this_00;
		ResTIMG *pRVar5;
		uint uVar6;
		int iVar7;
		undefined4 uVar8;
		double dVar9;
		undefined8 in_f31;
		undefined auStack8[8];

		dVar9 = (double)param_3;
		uVar8 = 0;
		if ((((param_1 == (ResTIMG *)0x0) || (3 < this->mNumTexture)) || (3 < param_2)) ||
			(this->mNumTexture < param_2)) {
			uVar4 = 0;
		} else {
			this_00 = new JUTTexture;
			if (this_00 != (JUTTexture *)0x0) {
				this_00->mpPalette = (JUTPalette *)0x0;
				this_00->storeTIMG(param_1, '\0');
				this_00->field13_0x3b = this_00->field13_0x3b & 2;
			}
			for (uVar6 = 3; (uint)param_2 < (uVar6 & 0xff); uVar6 = uVar6 - 1) {
				uVar3 = uVar6 & 0xff;
				this->mpTexture[uVar3] = this->mpTexture[uVar3 - 1];
				this->mBlendKonstColorF[uVar3] = this->mBlendKonstColorF[uVar3 - 1];
				this->mBlendKonstAlphaF[uVar3] = this->mBlendKonstColorF[uVar3 + 3];
			}
			iVar7 = 1 << (uint)param_2;
			uVar6 = iVar7 - 1;
			this->field4_0xdd =
				this->field4_0xdd & (byte)uVar6 | (byte)(((uint)this->field4_0xdd & ~uVar6) << 1);
			this->mpTexture[param_2] = this_00;
			this->field4_0xdd = this->field4_0xdd | (byte)iVar7;
			this->mBlendKonstColorF[param_2] = (float)dVar9;
			this->mBlendKonstAlphaF[param_2] = (float)dVar9;
			if ((this->mNumTexture == 0) && (this->mpTexture[0] != (JUTTexture *)0x0)) {
				pRVar5 = this->mpTexture[0]->mpTIMG;
				uVar1 = pRVar5->mHeight;
				uVar2 = pRVar5->mWidth;
				mPos.mTL[0] = 0.0;
				mPos.mTL[1] = 0.0;
				mPos.mBR[0] = uVar2;
				mPos.mBR[1] = uVar1;
				calcMtx();
			}
			this->mNumTexture = this->mNumTexture + 1;
			setBlendKonstColor();
			setBlendKonstAlpha();
			uVar4 = 1;
		}
		return uVar4;
	}

	void drawSelf(float param_1, float param_2) {
		double dVar1;
		double dVar2;
		MTX34 MStack72;

		dVar2 = (double)param_2;
		dVar1 = (double)param_1;
		mtx::PSMTXIdentity(&MStack72);
		drawSelf(dVar1, dVar2, &MStack72);	// TODO: overload
	}

	int field5_0xde;
	int field6_0xdf;

	void J2DPicture::initinfo() {
		mMagic = 0x50494331;
		this->field5_0xde = 0xf;
		this->field6_0xdf = this->field6_0xdf & 4;
		this->field6_0xdf = this->field6_0xdf & 3;
		this->mBlendKonstColorF[0] = 1.0;
		this->mBlendKonstColorF[1] = 1.0;
		this->mBlendKonstColorF[2] = 1.0;
		this->mBlendKonstColorF[3] = 1.0;
		setBlendKonstColor();
		this->mBlendKonstAlphaF[0] = 1.0;
		this->mBlendKonstAlphaF[1] = 1.0;
		this->mBlendKonstAlphaF[2] = 1.0;
		this->mBlendKonstAlphaF[3] = 1.0;
		setBlendKonstAlpha();
		(this->mBgColor).r = 0;
		(this->mBgColor).g = 0;
		(this->mBgColor).b = 0;
		(this->mBgColor).a = 0;
		(this->mColorBase).r = 0xff;
		(this->mColorBase).g = 0xff;
		(this->mColorBase).b = 0xff;
		(this->mColorBase).a = 0xff;
		this->mNewColor[0].r = 0xff;
		this->mNewColor[0].g = 0xff;
		this->mNewColor[0].b = 0xff;
		this->mNewColor[0].a = 0xff;
		this->mNewColor[1].r = 0xff;
		this->mNewColor[1].g = 0xff;
		this->mNewColor[1].b = 0xff;
		this->mNewColor[1].a = 0xff;
		this->mNewColor[2].r = 0xff;
		this->mNewColor[2].g = 0xff;
		this->mNewColor[2].b = 0xff;
		this->mNewColor[2].a = 0xff;
		this->mNewColor[3].r = 0xff;
		this->mNewColor[3].g = 0xff;
		this->mNewColor[3].b = 0xff;
		this->mNewColor[3].a = 0xff;
	}

	J2DPicture() {
		this->mColorBase = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBgColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBlendKonstColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBlendKonstAlpha = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mpTexture[0] = (JUTTexture *)0x0;
		this->mNumTexture = 0;
		this->mpPalette = (JUTPalette *)0x0;
		initinfo();
	}

	void drawOut(float param_1, float param_2, float param_3, float param_4,
				 float param_5, float param_6) {
		ResTIMG *pRVar1;
		TBox2<float> local_38;
		TBox2<float> local_28;
		undefined4 local_18;
		uint uStack20;
		undefined4 local_10;
		uint uStack12;

		if (this->mpTexture[0]) {
			pRVar1 = this->mpTexture[0]->mpTIMG;
			local_38.mBR[0] = param_5 + pRVar1->mWidth;
			local_38.mBR[1] = param_6 + pRVar1->mHeight;
			local_28.mBR[0] = param_1 + param_3;
			local_28.mBR[1] = param_2 + param_4;
			local_38.mTL[0] = param_5;
			local_38.mTL[1] = param_6;
			local_28.mTL[0] = param_1;
			local_28.mTL[1] = param_2;
			drawOut(&local_28, &local_38);
		}
	}

	void private_initiate(ResTIMG *param_1, ResTLUT *param_2) {
		JUTTexture *this_00;
		JUTPalette *this_01;

		this->mpTexture[0] = (JUTTexture *)0x0;
		this->field4_0xdd = 1;
		this->mNumTexture = 0;
		if (param_1) {
			this_00 = new JUTTexture;
			if (this_00 != (JUTTexture *)0x0) {
				this_00->mpPalette = (JUTPalette *)0x0;
				this_00->storeTIMG(param_1, '\0');
				this_00->field13_0x3b = this_00->field13_0x3b & 2;
			}
			this->mpTexture[0] = this_00;
			this->mNumTexture = this->mNumTexture + 1;
		}
		this->mpPalette = (JUTPalette *)0x0;
		if (param_2 != (ResTLUT *)0x0) {
			this_01 = new JUTPalette;
			this_01->storeTLUT(gx::GXTlut::GX_TLUT0, param_2);
			this->mpPalette = this_01;
			this->mpTexture[0]->attachPalette(this->mpPalette);
		}
	}

	J2DPicture(ulong param_1, TBox2<float> *param_2, ResTIMG *param_3, ResTLUT *param_4) {
		this->mpPalette = (JUTPalette *)0x0;
		this->mColorBase = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBgColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBlendKonstColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBlendKonstAlpha = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		private_initiate(param_3, param_4);
		initinfo();
	}

	~J2DPicture() {
		int iVar1;
		int iVar2;

		iVar1 = 0;
		iVar2 = 0;
		while (true) {
			if ((int)(uint)this->mNumTexture <= iVar1)
				break;
			if (((uint)this->field4_0xdd & 1 << iVar1) != 0) {
				delete this->mpTexture[iVar2];
			}
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 4;
		}
		delete this->mpPalette;
	}

	J2DPicture(ResTIMG *param_1) {
		this->mColorBase = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBgColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBlendKonstColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBlendKonstAlpha = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mpTexture[0] = (JUTTexture *)0x0;
		this->mNumTexture = 0;
		if (param_1 != (ResTIMG *)0x0) {
			insert(param_1, this->mNumTexture, 1.0);
		}
		this->mpPalette = (JUTPalette *)0x0;
		initinfo();
	}

	J2DPicture(char *param_1) {
		this->mColorBase = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBgColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBlendKonstColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBlendKonstAlpha = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mpTexture[0] = (JUTTexture *)0x0;
		this->mNumTexture = 0;
		if (param_1 != (char *)0x0) {
			insert(param_1, this->mNumTexture, 1.0);
		}
		this->mpPalette = (JUTPalette *)0x0;
		initinfo();
	}

	void initiate(ResTIMG *param_1, ResTLUT *param_2) {
		ushort uVar1;
		ushort uVar2;
		ResTIMG *pRVar3;

		private_initiate(param_1, param_2);
		if (this->mpTexture[0]) {
			pRVar3 = this->mpTexture[0]->mpTIMG;
			uVar1 = pRVar3->mHeight;
			uVar2 = pRVar3->mWidth;
			mPos.mTL[0] = 0.0;
			mPos.mTL[1] = 0.0;
			mPos.mBR[0] = uVar2;
			mPos.mBR[1] = uVar1;

			calcMtx();
		}
	}

	void setBlendKonstColor() {
		float fVar1;
		float fVar2;
		uint uVar3;
		byte bVar4;
		uint uVar5;
		u8 local_18;
		u8 uStack23;
		u8 uStack22;
		u8 uStack21;

		uVar3 = 0;
		for (bVar4 = 1; bVar4 < this->mNumTexture; bVar4 = bVar4 + 1) {
			fVar1 = 0.0;
			for (uVar5 = 0; (uVar5 & 0xff) < (uint)bVar4; uVar5 = uVar5 + 1) {
				fVar1 = fVar1 + this->mBlendKonstColorF[uVar5 & 0xff];
			}
			fVar2 = fVar1 + this->mBlendKonstColorF[bVar4];
			if (fVar2 != 0.0) {
				uVar3 = uVar3 | ((int)((1.0 - fVar1 / fVar2) * 255.0) & 0xffU) << (bVar4 - 1) * 8;
			}
		}
		local_18 = (u8)(uVar3 >> 0x18);
		(this->mBlendKonstColor).r = local_18;
		uStack23 = (u8)(uVar3 >> 0x10);
		(this->mBlendKonstColor).g = uStack23;
		uStack22 = (u8)(uVar3 >> 8);
		(this->mBlendKonstColor).b = uStack22;
		uStack21 = (u8)uVar3;
		(this->mBlendKonstColor).a = uStack21;
		return;
	}

	void setBlendKonstAlpha() {
		float fVar1;
		float fVar2;
		uint uVar3;
		byte bVar4;
		uint uVar5;
		u8 local_18;
		u8 uStack23;
		u8 uStack22;
		u8 uStack21;

		uVar3 = 0;
		for (bVar4 = 1; bVar4 < this->mNumTexture; bVar4 = bVar4 + 1) {
			fVar1 = 0.0;
			for (uVar5 = 0; (uVar5 & 0xff) < (uint)bVar4; uVar5 = uVar5 + 1) {
				fVar1 = fVar1 + this->mBlendKonstAlphaF[uVar5 & 0xff];
			}
			fVar2 = fVar1 + this->mBlendKonstAlphaF[bVar4];
			if (fVar2 != 0.0) {
				uVar3 = uVar3 | ((int)((1.0 - fVar1 / fVar2) * 255.0) & 0xffU) << (bVar4 - 1) * 8;
			}
		}
		local_18 = (u8)(uVar3 >> 0x18);
		(this->mBlendKonstAlpha).r = local_18;
		uStack23 = (u8)(uVar3 >> 0x10);
		(this->mBlendKonstAlpha).g = uStack23;
		uStack22 = (u8)(uVar3 >> 8);
		(this->mBlendKonstAlpha).b = uStack22;
		uStack21 = (u8)uVar3;
		(this->mBlendKonstAlpha).a = uStack21;
		return;
	}

	void getNewColor(gx::GXColor *param_1) {
		uint uVar1;

		param_1->r = this->mNewColor[0].r;
		param_1->g = this->mNewColor[0].g;
		param_1->b = this->mNewColor[0].b;
		param_1->a = this->mNewColor[0].a;
		param_1[1].r = this->mNewColor[1].r;
		param_1[1].g = this->mNewColor[1].g;
		param_1[1].b = this->mNewColor[1].b;
		param_1[1].a = this->mNewColor[1].a;
		param_1[2].r = this->mNewColor[2].r;
		param_1[2].g = this->mNewColor[2].g;
		param_1[2].b = this->mNewColor[2].b;
		param_1[2].a = this->mNewColor[2].a;
		param_1[3].r = this->mNewColor[3].r;
		param_1[3].g = this->mNewColor[3].g;
		param_1[3].b = this->mNewColor[3].b;
		param_1[3].a = this->mNewColor[3].a;
		uVar1 = (uint)mDrawAlpha;
		if (uVar1 == 0xff) {
			return;
		}
		param_1->a = (u8)((param_1->a * uVar1) / 0xff);
		param_1[1].a = (u8)(((uint)param_1[1].a * (uint)mDrawAlpha) / 0xff);
		param_1[2].a = (u8)(((uint)param_1[2].a * (uint)mDrawAlpha) / 0xff);
		param_1[3].a = (u8)(((uint)param_1[3].a * (uint)mDrawAlpha) / 0xff);
		return;
	}

	int remove(uchar param_1) {
		uint uVar1;
		uint uVar2;
		uint uVar3;
		int iVar4;
		uint uVar5;

		uVar5 = (uint)param_1;
		uVar1 = (uint)param_1;
		if ((uVar1 < this->mNumTexture) && (this->mNumTexture != 1)) {
			if (((uint)this->field4_0xdd & 1 << uVar1) != 0) {
				delete this->mpTexture[param_1];
			}
			for (; uVar2 = uVar5 & 0xff, (int)uVar2 < (int)(this->mNumTexture - 1); uVar5 = uVar5 + 1) {
				uVar3 = uVar5 & 0xff;
				this->mpTexture[uVar3] = this->mpTexture[uVar2 + 1];
				this->mBlendKonstColorF[uVar3] = this->mBlendKonstColorF[uVar2 + 1];
				this->mBlendKonstAlphaF[uVar3] = this->mBlendKonstAlphaF[uVar2 + 1];
			}
			this->field4_0xdd =
				this->field4_0xdd & (char)(1 << uVar1) - 1U |
				(byte)((int)((uint)this->field4_0xdd & ~((1 << uVar1 + 1) - 1U)) >> 1);
			this->mNumTexture = this->mNumTexture - 1;
			setBlendKonstColor();
			setBlendKonstAlpha();
			iVar4 = 1;
		} else {
			iVar4 = 0;
		}
		return iVar4;
	}

	void setTevMode() {
		using namespace gx;
		GXTevStageID GVar1;
		uint uVar2;
		byte bVar3;
		gx::GXColor local_28;
		gx::GXColor local_24;
		gx::GXColor local_20;
		gx::GXColor local_1c;
		undefined4 local_18;
		gx::GXColor local_14;

		for (bVar3 = 0; bVar3 < this->mNumTexture; bVar3 = bVar3 + 1) {
			GVar1 = (GXTevStageID)bVar3;
			gx::GXSetTevOrder(GVar1, (GXTexCoordID)GVar1, (GXTexMapID)GVar1, GX_COLOR_NULL);
		}
		local_18 = 0xffffffff;
		local_14 = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		gx::GXSetTevColor(GX_TEVREG2, local_14);
		gx::GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_TEXC, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
		if (this->mpTexture[0]->mpTIMG->mTranslucency == 0) {
			gx::GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A2, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
		} else {
			gx::GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_TEXA, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
		}
		gx::GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		local_1c = this->mBlendKonstColor;
		gx::GXSetTevKColor(GXTevKColorID::GX_KCOLOR0, local_1c);
		local_20 = this->mBlendKonstAlpha;
		gx::GXSetTevKColor(GXTevKColorID::GX_KCOLOR2, local_20);
		for (bVar3 = 1; bVar3 < this->mNumTexture; bVar3 = bVar3 + 1) {
			GVar1 = (GXTevStageID)bVar3;
			uVar2 = (uint)bVar3;
			gx::GXSetTevKColorSel(GVar1, (GXTevKColorSel)(uVar2 * -4 + 0x20));
			gx::GXSetTevKAlphaSel(GVar1, (GXTevKAlphaSel)(uVar2 * -4 + 0x22));
			gx::GXSetTevColorIn(GVar1, GX_CC_CPREV, GX_CC_TEXC, GX_CC_KONST, GX_CC_ZERO);
			if (this->mpTexture[uVar2]->mpTIMG->mTranslucency == 0) {
				gx::GXSetTevAlphaIn(GVar1, GX_CA_APREV, GX_CA_A2, GX_CA_KONST, GX_CA_ZERO);
			} else {
				gx::GXSetTevAlphaIn(GVar1, GX_CA_APREV, GX_CA_TEXA, GX_CA_KONST, GX_CA_ZERO);
			}
			gx::GXSetTevColorOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
			gx::GXSetTevAlphaOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		}
		if ((&this->mBgColor) || (*(uint *)&this->mColorBase != 0xffffffff)) {
			GVar1 = (GXTevStageID)bVar3;
			gx::GXSetTevOrder(GVar1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
			local_24 = this->mBgColor;
			gx::GXSetTevColor(GX_TEVREG0, local_24);
			local_28 = this->mColorBase;
			gx::GXSetTevColor(GX_TEVREG1, local_28);
			gx::GXSetTevColorIn(GVar1, GX_CC_C0, GX_CC_C1, GX_CC_CPREV, GX_CC_ZERO);
			gx::GXSetTevAlphaIn(GVar1, GX_CA_A0, GX_CA_A1, GX_CA_APREV, GX_CA_ZERO);
			gx::GXSetTevColorOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
			gx::GXSetTevAlphaOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
			bVar3 = bVar3 + 1;
		}
		if ((((mDrawAlpha != 0xff) || (*(int *)&this->mNewColor[0] != 0xffffffff)) ||
			 (*(int *)&this->mNewColor[1] != 0xffffffff)) ||
			((*(int *)&this->mNewColor[2] != 0xffffffff || (*(int *)&this->mNewColor[3] != 0xffffffff)))) {
			GVar1 = (GXTevStageID)bVar3;
			gx::GXSetTevOrder(GVar1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
			gx::GXSetTevColorIn(GVar1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_RASC, GX_CC_ZERO);
			gx::GXSetTevAlphaIn(GVar1, GX_CA_ZERO, GX_CA_APREV, GX_CA_RASA, GX_CA_ZERO);
			gx::GXSetTevColorOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
			gx::GXSetTevAlphaOp(GVar1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
			bVar3 = bVar3 + 1;
		}
		gx::GXSetNumTevStages(bVar3);
		gx::GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
		for (bVar3 = 0; bVar3 < this->mNumTexture; bVar3 = bVar3 + 1) {
			gx::GXSetTexCoordGen2((GXTexCoordID)bVar3, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, false, GX_PTIDENTITY);
		}
		gx::GXSetNumChans(1);
		return;
	}

	void J2DPicture::drawSelf(float param_1, float param_2, float *param_3) {
		if (this->mpTexture[0]) {
			// TODO: wtf
		}
	}

	void draw(float param_1, float param_2, float param_3, float param_4,
			  bool param_5, bool param_6, bool param_7)

	{
		using namespace gx;
		uint uVar1;
		uint uVar2;
		undefined4 uVar3;
		double dVar4;
		double dVar5;
		double dVar6;
		double dVar7;
		undefined8 in_f28;
		undefined8 in_f29;
		undefined8 in_f30;
		undefined8 in_f31;
		GXColor local_98[4];
		undefined4 local_94;
		undefined4 local_90;
		undefined4 local_8c;
		MTX34 MStack136;
		undefined auStack56[16];
		undefined auStack40[16];
		undefined auStack24[16];
		undefined auStack8[8];

		dVar7 = (double)param_4;
		dVar5 = (double)param_2;
		dVar6 = (double)param_3;
		dVar4 = (double)param_1;
		uVar3 = 0;
		if (mbDraw != 0) {
			for (uVar2 = 0; uVar1 = (uint)this->mNumTexture, (uVar2 & 0xff) < uVar1; uVar2 = uVar2 + 1) {
				if ((uVar2 & 0xff) < uVar1) {
					this->mpTexture[uVar2 & 0xff]->load((GXTexMapID)(uVar2 & 0xff));
				}
			}
			gx::GXSetNumTexGens(uVar1);
			mDrawAlpha = mAlpha;
			memset(&local_98, ~0, sizeof(local_98));
			J2DPicture::getNewColor(local_98);
			J2DPicture::setTevMode();
			makeMatrix(dVar4, dVar5);
			gx::GXLoadPosMtxImm(mMtx, 0);
			gx::GXSetCurrentMtx(0);
			gx::GXClearVtxDesc();
			gx::GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
			gx::GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
			gx::GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
			gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_F32, 0);
			gx::GXBegin(GX_QUADS, GXVtxFmt::GX_VTXFMT0, 4);
			void write_volatile_4(uint, ...);
			void write_volatile_2(uint, ...);
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, local_98);
			if (param_7 == false) {
				write_volatile_2(0xcc008000, -(ushort)(param_5 != false) & 0x8000);
				write_volatile_2(0xcc008000, -(ushort)(param_6 != false) & 0x8000);
			} else {
				write_volatile_2(0xcc008000, -(ushort)(param_5 != false) & 0x8000);
				write_volatile_2(0xcc008000, ~-(ushort)(param_6 != false) & 0x8000);
			}
			write_volatile_4(0xcc008000, (float)dVar6);
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, local_94);
			if (param_7 == false) {
				write_volatile_2(0xcc008000, ~-(ushort)(param_5 != false) & 0x8000);
				write_volatile_2(0xcc008000, -(ushort)(param_6 != false) & 0x8000);
			} else {
				write_volatile_2(0xcc008000, -(ushort)(param_5 != false) & 0x8000);
				write_volatile_2(0xcc008000, -(ushort)(param_6 != false) & 0x8000);
			}
			write_volatile_4(0xcc008000, (float)dVar6);
			write_volatile_4(0xcc008000, (float)dVar7);
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, local_8c);
			if (param_7 == false) {
				write_volatile_2(0xcc008000, ~-(ushort)(param_5 != false) & 0x8000);
				write_volatile_2(0xcc008000, ~-(ushort)(param_6 != false) & 0x8000);
			} else {
				write_volatile_2(0xcc008000, ~-(ushort)(param_5 != false) & 0x8000);
				write_volatile_2(0xcc008000, -(ushort)(param_6 != false) & 0x8000);
			}
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, (float)dVar7);
			write_volatile_4(0xcc008000, 0.0);
			write_volatile_4(0xcc008000, local_90);
			if (param_7 == false) {
				write_volatile_2(0xcc008000, -(ushort)(param_5 != false) & 0x8000);
				write_volatile_2(0xcc008000, ~-(ushort)(param_6 != false) & 0x8000);
			} else {
				write_volatile_2(0xcc008000, ~-(ushort)(param_5 != false) & 0x8000);
				write_volatile_2(0xcc008000, ~-(ushort)(param_6 != false) & 0x8000);
			}
			gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_RGBX8, 0xf);
			gx::GXSetNumTexGens(0);
			gx::GXSetNumTevStages(1);
			gx::GXSetTevOp(GXTevStageID::GX_TEVSTAGE0, GXTevMode::GX_PASSCLR);
			gx::GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
			mtx::PSMTXIdentity(&MStack136);
			gx::GXLoadPosMtxImm(MStack136, 0);
			gx::GXSetVtxDesc(GX_VA_TEX0, GX_NONE);
		}
	}

	J2DPicture(J2DPane *param_1, JSURandomInputStream *param_2) {
		int iVar1;
		ResTIMG *pRVar2;
		ResTLUT *pRVar3;
		JUTTexture *this_00;
		JUTPalette *this_01;
		int iVar4;
		int iVar5;
		char cVar6;
		undefined uStack376;
		byte local_177;
		byte local_176;
		char local_175;
		undefined4 local_174;
		undefined4 local_170;
		undefined4 local_16c;
		undefined4 local_168;
		undefined4 local_164;
		undefined4 local_160;
		undefined4 local_15c;
		undefined4 local_158;
		undefined4 local_154;
		undefined4 local_150;
		undefined4 local_14c;
		undefined4 local_148;
		undefined4 local_144;
		undefined4 local_140;
		undefined4 local_13c;
		undefined4 local_138;
		char local_134[8];
		int local_130;
		JUTResReference local_12c;

		this->mpPalette = (JUTPalette *)0x0;
		this->mColorBase = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBgColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBlendKonstColor = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		this->mBlendKonstAlpha = (gx::GXColor){0xff, 0xff, 0xff, 0xff};
		iVar1 = param_2->getPosition();
		param_2->read(&local_134, 8);
		mMagic = *(uint *)&local_134;
		makePaneStream(param_1, param_2);
		local_12c.rtype = 0;
		param_2->read(&local_175, 1);
		pRVar2 = (ResTIMG *)local_12c.getResource((JSUInputStream *)param_2, 0x54494d47, (JKRArchive *)0x0);
		pRVar3 = (ResTLUT *)local_12c.getResource((JSUInputStream *)param_2, 0x544c5554, (JKRArchive *)0x0);
		param_2->read(&local_176, 1);
		this->field5_0xde = local_176;
		cVar6 = local_175 + -3;
		if (local_175 == '\x03') {
			this->field6_0xdf = 0;
		} else {
			param_2->read(&local_177, 1);
			this->field6_0xdf = local_177;
			cVar6 = local_175 + -4;
		}
		if (cVar6 != '\0') {
			param_2->read(&uStack376, 1);
			cVar6 = cVar6 + -1;
		}
		local_138 = 0;
		(this->mBgColor).r = 0;
		(this->mBgColor).g = 0;
		(this->mBgColor).b = 0;
		(this->mBgColor).a = 0;
		local_13c = 0xffffffff;
		(this->mColorBase).r = 0xff;
		(this->mColorBase).g = 0xff;
		(this->mColorBase).b = 0xff;
		(this->mColorBase).a = 0xff;
		if (cVar6 != '\0') {
			param_2->read(&this->mBgColor, 4);
			cVar6 = cVar6 + -1;
		}
		if (cVar6 != '\0') {
			param_2->read(&mColorBase, 4);
			cVar6 = cVar6 + -1;
		}
		local_164 = 0xffffffff;
		local_160 = 0xffffffff;
		local_15c = 0xffffffff;
		local_158 = 0xffffffff;
		local_154 = 0xffffffff;
		local_150 = 0xffffffff;
		local_14c = 0xffffffff;
		local_148 = 0xffffffff;
		this->mNewColor[0].r = 0xff;
		this->mNewColor[0].g = 0xff;
		this->mNewColor[0].b = 0xff;
		this->mNewColor[0].a = 0xff;
		this->mNewColor[1].r = 0xff;
		this->mNewColor[1].g = 0xff;
		this->mNewColor[1].b = 0xff;
		this->mNewColor[1].a = 0xff;
		this->mNewColor[2].r = 0xff;
		this->mNewColor[2].g = 0xff;
		this->mNewColor[2].b = 0xff;
		this->mNewColor[2].a = 0xff;
		this->mNewColor[3].r = 0xff;
		this->mNewColor[3].g = 0xff;
		this->mNewColor[3].b = 0xff;
		this->mNewColor[3].a = 0xff;
		iVar4 = 0;
		for (iVar5 = 0; (cVar6 != '\0' && (iVar5 < 4)); iVar5 = iVar5 + 1) {
			param_2->read(&mNewColor[iVar4], 4);
			cVar6 = cVar6 + -1;
			iVar4 = iVar4 + 1;
		}
		param_2->seekPos(iVar1 + *(int *)(local_134 + 4), 0);
		this->mpTexture[0] = (JUTTexture *)0x0;
		this->mNumTexture = 0;
		this->field4_0xdd = 1;
		if (pRVar2 != (ResTIMG *)0x0) {
			this_00 = (JUTTexture *)new JUTTexture;
			this_00->mpPalette = (JUTPalette *)0x0;
			this_00->storeTIMG(pRVar2, '\0');
			this_00->field13_0x3b = this_00->field13_0x3b & 2;
			this->mpTexture[0] = this_00;
			this->mNumTexture = this->mNumTexture + 1;
		}
		if (pRVar3 != (ResTLUT *)0x0) {
			this_01 = new JUTPalette;
			if (this_01 != (JUTPalette *)0x0) {
				this_01->storeTLUT(gx::GXTlut::GX_TLUT0, pRVar3);
			}
			this->mpPalette = this_01;
			this->mpTexture[0]->attachPalette(this->mpPalette);
		}
		this->mBlendKonstColorF[0] = 1.0;
		this->mBlendKonstColorF[1] = 1.0;
		this->mBlendKonstColorF[2] = 1.0;
		this->mBlendKonstColorF[3] = 1.0;
		setBlendKonstColor();
		this->mBlendKonstAlphaF[0] = 1.0;
		this->mBlendKonstAlphaF[1] = 1.0;
		this->mBlendKonstAlphaF[2] = 1.0;
		this->mBlendKonstAlphaF[3] = 1.0;
		setBlendKonstAlpha();
	}
};