#include "JUTTexture.h"

#include <machine/dolphin/graphic.h>

#include "JUTPalette.h"

void JUTTexture::load(gx::GXTexMapID param_1) {
#ifdef DOLPHIN
	if (this->mpAttachedPalette) {
		this->mpAttachedPalette->load();
	}
	gx::GXLoadTexObj(this, param_1);
#else
	// bind texture to texture unit?
#endif
}

void JUTTexture::attachPalette(JUTPalette *param_1) {
	if (!this->mpTIMG->mbHasTlut)
		return;
	if ((!param_1) && (this->mpPalette)) {
		this->mpAttachedPalette = this->mpPalette;
	} else {
		this->mpAttachedPalette = param_1;
	}

	initTexObj(this->mpAttachedPalette->mTlut);
}

void JUTTexture::initTexObj() {
	int iVar1;
	ResTIMG *pRVar2;

	pRVar2 = this->mpTIMG;
	iVar1 = sizeof(ResTIMG);
	if (pRVar2->mTexDataOffs != 0) {
		iVar1 = pRVar2->mTexDataOffs;
	}
#ifdef DOLPHIN
	gx::GXInitTexObj(this, ((char *)&pRVar2->mTexFmt) + iVar1,
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
#else
	// create texture object? (no palette)
#endif

	return;
}

void JUTTexture::initTexObj(gx::GXTlut param_1) {
	byte bVar1;
	int iVar2;
	ResTIMG *pRVar3;

#ifdef DOLPHIN
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
#else
	// create texture object? (with palette)
#endif
}

void JUTTexture::storeTIMG(ResTIMG *param_1, uchar param_2) {
	ushort uVar1;
	JUTPalette *this_00;
	ResTIMG *pRVar2;
	uint uVar3;

#ifdef DOLPHIN
	if ((param_1 == nullptr) || (param_2 >= 0x10))
		return;

	this->mpTIMG = param_1;
	this->mpData = ((char *)&this->mpTIMG) + this->mpTIMG->mTexDataOffs;
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
#else
	// this could be another place where to create a texture
	// palette textures could be either computed in place if the palettes are not changed
	// would be easier than writing them in a shader
#endif
}
