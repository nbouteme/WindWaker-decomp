#include "JUTFont.h"

#include <machine/dolphin/printf.h>

#include <bit>
#include <cstdio>

#include "JUTAssert.h"
#include "JUtility.h"

static uint byteswap(uint value) {
	return __builtin_bswap32(value);
}

static int byteswap(int value) {
	return __builtin_bswap32(value);
}

static ushort byteswap(ushort value) {
	return __builtin_bswap16(value);
}

static short byteswap(short value) {
	return __builtin_bswap16(value);
}

void JUTFont::setCharColor(gx::GXColor *pColor) {
	this->somecolor2 = this->somecolor3 = this->somecolor4 = this->somecolor = *pColor;
}

void JUTFont::initialize_state() {
	gx::GXColor local_14{0xff, 0xff, 0xff, 0xff};
	setCharColor(&local_14);
	this->ignoreKerning = 0;
	this->mWidth = 0;
	this->mValid = 0;
}

JUTFont::~JUTFont() {}

void JUTFont::setGX(TColor, TColor){};
uint JUTFont::getCellWidth() {
	return 0;
};

uint JUTFont::getCellHeight() {
	return 0;
};

float JUTFont::drawString_size_scale(float xpos, float ypos, float xscale, float yscale, char *stringtoprint,
									 ulong length, bool param_7) {
	float currx = xpos;
	for (auto remaining = length; remaining; --remaining) {
		const char c = *stringtoprint;
		int codepoint = c;
		if (isLeadByte(codepoint)) {
			codepoint <<= 8;
			codepoint |= *stringtoprint++;
		}
		currx += drawChar_scale(currx, ypos, xscale, yscale, codepoint, param_7);
		stringtoprint++;
	}
	return currx - xpos;
}

EncodingFunction *JUTResFont::saoAboutEncoding_[3] = {
	JUTResFont::isLeadByte_1Byte,
	JUTResFont::isLeadByte_2Byte,
	JUTResFont::isLeadByte_ShiftJIS};

JUTResFont::~JUTResFont() {
	if (mValid) {
		deleteMemBlocks_ResFont();
		initialize_state();
		initialize_state();
	}
}

int JUTResFont::isLeadByte_1Byte(int param_1) {
	return 0;
}

int JUTResFont::isLeadByte_2Byte(int param_1) {
	return 1;
}

int JUTResFont::isLeadByte_ShiftJIS(int param_1) {
	return (((0x80 < param_1) && (param_1 < 0xa0)) || ((0xdf < param_1 && (param_1 < 0xfd))));
}

int JUTResFont::getHeight() {
	return getDescent() + getAscent();
}

float JUTResFont::drawChar_scale(float param_1, float param_2, float param_3, float param_4, int param_5, bool param_6) {
	using namespace gx;
	ushort uVar1;
	ushort uVar2;
	ushort uVar3;
	ushort uVar4;
	ulong uVar5;
	uint uVar6;
	int iVar7;
	int vertattr2;
	int vertattr;
	undefined2 uVar8;
	undefined2 uVar9;
	undefined2 uVar10;
	undefined4 uVar11;
	double dVar12;
	double dVar13;
	undefined8 in_f26;
	double dVar14;
	undefined8 in_f27;
	double dVar15;
	undefined8 in_f28;
	double dVar16;
	undefined8 in_f29;
	double dVar17;
	undefined8 in_f30;
	double dVar18;
	undefined8 in_f31;
	double dVar19;
	TWidth local_a8;
	undefined auStack88[16];
	undefined auStack72[16];
	undefined auStack56[16];
	undefined auStack40[16];
	undefined auStack24[16];
	undefined auStack8[8];

	dVar16 = (double)param_4;
	dVar14 = (double)param_3;
	dVar15 = (double)param_2;
	dVar19 = (double)param_1;
	uVar11 = 0;
	if (mValid == 0) {
		JUTAssertion::getSDevice()->showAssert("JUTResFont.cpp", 0x179, "mValid");
		m_Do_printf::OSPanic("JUTResFont.cpp", 0x179, "Halt");
	}
	loadFont(param_5, gx::GXTexMapID::GX_TEXMAP0, &local_a8);
	if ((ignoreKerning == 0) && (param_6 != false)) {
		uVar6 = getCellWidth();
		dVar19 = (dVar19 - local_a8.field0_0x0 * (float)(dVar14) / uVar6);
	}
	uVar6 = getCellWidth();
	dVar13 = 4503601774854144.0;
	dVar12 = dVar14 / uVar6;
	dVar17 = mWidth * dVar12;
	if (ignoreKerning == 0) {
		if (param_6 == false) {
			uVar6 = getCellWidth();
			dVar13 = 4503601774854144.0;
			dVar12 = (dVar14 / uVar6);
			dVar17 = local_a8.mAdvance + local_a8.field0_0x0 * dVar12;
		} else {
			uVar6 = getCellWidth();
			dVar13 = (dVar14 / uVar6);
			dVar12 = 4503599627370496.0;
			dVar17 = local_a8.mAdvance * dVar13;
		}
	}
	dVar18 = (dVar19 + dVar14);
	uVar6 = getHeight();
	dVar14 = (dVar16 / uVar6);
	uVar6 = getAscent();
	dVar14 = (dVar15 - (uVar6 * dVar14));
	uVar6 = getHeight();
	dVar16 = (dVar16 / uVar6);
	uVar6 = getDescent();
	dVar15 = (dVar15 + (((double)uVar6 * dVar16)));
	vertattr = this->somevert;
	iVar7 = *(int *)(this->mpGlyph + (uint)this->glyphidx * 4);
	uVar1 = *(ushort *)(iVar7 + 0x1a);
	vertattr2 = this->somevert2;
	uVar2 = *(ushort *)(iVar7 + 0x1c);
	uVar3 = *(ushort *)(iVar7 + 0xc);
	uVar4 = *(ushort *)(iVar7 + 0xe);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_F32, 0);
	gx::GXBegin(gx::GXPrimitive::GX_QUADS, gx::GXVtxFmt::GX_VTXFMT0, 4);

	void write_volatile_1(uint, ...);
	void write_volatile_2(uint, ...);
	void write_volatile_4(uint, ...);
	write_volatile_4(0xcc008000, (float)dVar19);
	write_volatile_4(0xcc008000, (float)dVar14);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, somecolor);
	uVar10 = (undefined2)((vertattr << 0xf) / (int)(uint)uVar1);
	write_volatile_2(0xcc008000, uVar10);
	uVar9 = (undefined2)((vertattr2 << 0xf) / (int)(uint)uVar2);
	write_volatile_2(0xcc008000, uVar9);
	write_volatile_4(0xcc008000, (float)dVar18);
	write_volatile_4(0xcc008000, (float)dVar14);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, somecolor2);
	uVar8 = (undefined2)((int)((vertattr + (uint)uVar3) * 0x8000) / (int)(uint)uVar1);
	write_volatile_2(0xcc008000, uVar8);
	write_volatile_2(0xcc008000, uVar9);
	write_volatile_4(0xcc008000, (float)dVar18);
	write_volatile_4(0xcc008000, (float)dVar15);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, somecolor3);
	write_volatile_2(0xcc008000, uVar8);
	uVar8 = (undefined2)((int)((vertattr2 + (uint)uVar4) * 0x8000) / (int)(uint)uVar2);
	write_volatile_2(0xcc008000, uVar8);
	write_volatile_4(0xcc008000, (float)dVar19);
	write_volatile_4(0xcc008000, (float)dVar15);
	write_volatile_4(0xcc008000, 0.0);
	write_volatile_4(0xcc008000, somecolor4);
	write_volatile_2(0xcc008000, uVar10);
	write_volatile_2(0xcc008000, uVar8);
	gx::GXSetVtxAttrFmt(gx::GX_VTXFMT0, gx::GX_VA_POS, gx::GX_CLR_RGBA, gx::GX_RGBA4, 0);
	return dVar17;
}

void JUTResFont::countBlock() {
	int iVar1;
	uint blockIdx;
	ResFONT *pRVar2;

	this->mNumWidth = 0;
	this->mNumGlyph = 0;
	this->mNumMap = 0;
	pRVar2 = this->mpResFONT + 1;  // point to first block
	blockIdx = 0;
	do {
		if (byteswap(this->mpResFONT->mBlockNum) <= blockIdx) {
			return;
		}
		iVar1 = *(int *)pRVar2->mMagic;
		/* MAP1 */
		int a = byteswap(iVar1);
		switch (a) {
		case 0x4d415031:
			this->mNumMap = this->mNumMap + 1;
			break;
		case 0x57494431:
			this->mNumWidth = this->mNumWidth + 1;
			break;
		case 0x474c5931:
			this->mNumGlyph = this->mNumGlyph + 1;
			break;
		case 0x494e4630:
		case 0x494e4631:
			break;
		default:
			JUtility::JUTReportConsole("JUTResFont: Unknown data block\n");
		}
		pRVar2 = (ResFONT *)(pRVar2->mMagic + byteswap(*(int *)pRVar2->mVersion));
		blockIdx = blockIdx + 1;
	} while (true);
}

int JUTResFont::convertSjis(int param_1, ushort *param_2) {
	uint uVar1;
	int iVar2;

	iVar2 = (param_1 & 0xffU) - 0x40;
	if (0x3f < iVar2) {
		iVar2 = (param_1 & 0xffU) - 0x41;
	}
	uVar1 = 0x31c;
	if (param_2 != (ushort *)0x0) {
		uVar1 = (uint)*param_2;
	}
	return iVar2 + (((uint)param_1 >> 8 & 0xff) - 0x88) * 0xbc + -0x5e + uVar1;
}

void JUTResFont::deleteMemBlocks_ResFont() {
	delete[] this->mpMemBlock;
}

ushort JUTResFont::getAscent() {
	return this->mpINF1->mAscent;
}

uint JUTResFont::getCellHeight() {
	uint uVar1;
	int iVar2;

	/* WARNING: Load size is inaccurate */
	if (((int *)this->mpGlyph == (int *)0x0) || (iVar2 = *this->mpGlyph, iVar2 == 0)) {
		uVar1 = getHeight();
	} else {
		uVar1 = (uint) * (ushort *)(iVar2 + 0xe);
	}
	return uVar1;
}

uint JUTResFont::getCellWidth() {
	uint uVar1;
	int iVar2;

	/* WARNING: Load size is inaccurate */
	if (((int *)this->mpGlyph == (int *)0x0) || (iVar2 = *this->mpGlyph, iVar2 == 0)) {
		uVar1 = getWidth();
	} else {
		uVar1 = (uint) * (ushort *)(iVar2 + 0xc);
	}
	return uVar1;
}

ushort JUTResFont::getDescent() {
	return byteswap(this->mpINF1->mDescent);
}

short JUTResFont::getFontType() {
	return byteswap(this->mpINF1->mFontEncoding);
}

ushort JUTResFont::getLeading() {
	return byteswap(this->mpINF1->mFallbackLeading);
}

ResFONT *JUTResFont::getResFont() {
	return this->mpResFONT;
}

short JUTResFont::getWidth() {
	return byteswap(this->mpINF1->mFallbackWidth);
}

uint JUTResFont::getFontCode(int code) {
	ushort uVar1;
	uint max;
	int encoding;
	int idx;
	ResFONT__MAP1 *pMAP1;
	uint uVar2;
	char *pcVar3;
	int iVar4;
	int iVar5;
	uint uVar6;

	uVar6 = (uint)byteswap(this->mpINF1->mFallbackCode);
	encoding = getFontType();
	if ((((encoding == 2) && (0x7fff < (ushort)byteswap(this->mMaxGlyph))) && (0x1f < code)) &&
		((uint)code < 0x7f)) {
		code = (int)*(ushort *)("JUTTexture: TLUT is NULL\n" + code * 2 + 0x15);
	}
	idx = 0;
	max = (uint)this->mNumMap;
	while (true) {
		if (max == 0) {
			return uVar6;
		}
		pMAP1 = *(ResFONT__MAP1 **)(this->mpMAP1 + idx);
		uVar2 = (uint)byteswap(pMAP1->mMinGlyph);
		if (((int)uVar2 <= code) && (code <= (int)(uint)byteswap(pMAP1->mMaxGlyph)))
			break;
		idx = idx + 4;
		max = max - 1;
	}
	uVar1 = byteswap(pMAP1->mType);
	if (uVar1 == 0) {
		return code - uVar2;
	}
	if (uVar1 == 2) {
		return (uint) * (ushort *)(pMAP1 + (code - uVar2) * 2 + 0x10);
	}
	if (uVar1 != 3) {
		if (uVar1 != 1) {
			return uVar6;
		}
		pcVar3 = (char *)0x0;
		if (*(short *)pMAP1[1].mMagic == 1) {
			pcVar3 = pMAP1[1].mMagic + 2;
		}
		uVar6 = convertSjis(code, (ushort *)pcVar3);
		return uVar6;
	}
	iVar4 = 0;
	encoding = *(ushort *)pMAP1[1].mMagic - 1;
	while (true) {
		while (true) {
			if (encoding < iVar4) {
				return uVar6;
			}
			max = encoding + iVar4;
			iVar5 = ((int)max >> 1) + (uint)((int)max < 0 && (max & 1) != 0);
			if ((int)(uint) * (ushort *)(pMAP1[1].mMagic + iVar5 * 4 + 2) <= code)
				break;
			encoding = iVar5 + -1;
		}
		if (code <= (int)(uint) * (ushort *)(pMAP1[1].mMagic + iVar5 * 4 + 2))
			break;
		iVar4 = iVar5 + 1;
	}
	return (uint) * (ushort *)(pMAP1[1].mMagic + iVar5 * 4 + 4);
}

void JUTResFont::getWidthEntry(int code, TWidth *pWidth) {
	uint uVar1;
	uint uVar2;
	byte *pbVar3;
	int iVar4;
	int iVar5;

	uVar2 = getFontCode(code);
	iVar5 = 0;
	pWidth->field0_0x0 = 0;
	pWidth->mAdvance = (byte)byteswap(this->mpINF1->mFallbackWidth);
	uVar1 = (uint)this->mNumWidth;
	while (true) {
		if (uVar1 == 0) {
			return;
		}
		iVar4 = *(int *)(this->mpWidth + iVar5);
		if (((int)(uint) * (ushort *)(iVar4 + 8) <= (int)uVar2) &&
			((int)uVar2 <= (int)(uint) * (ushort *)(iVar4 + 10)))
			break;
		iVar5 = iVar5 + 4;
		uVar1 = uVar1 - 1;
	}
	pbVar3 = (byte *)(iVar4 + (uVar2 - *(ushort *)(iVar4 + 8)) * 2 + 0xc);
	pWidth->field0_0x0 = *pbVar3;
	pWidth->mAdvance = pbVar3[1];
}

void JUTResFont::initialize_state() {
	this->mpResFONT = (ResFONT *)0x0;
	this->mpMemBlock = nullptr;
	this->mpWidth = nullptr;
	this->mpGlyph = nullptr;
	this->mpMAP1 = (ResFONT__MAP1 **)0x0;
	this->somevert = 0;
	this->somevert2 = 0;
	this->glyphTexPtr = 0xffffffff;
}

bool JUTResFont::initiate(ResFONT *param_1, JKRHeap *param_2) {
	char cVar1;

	cVar1 = protected_initiate(param_1, param_2);
	if (cVar1 == '\0') {
		deleteMemBlocks_ResFont();
		initialize_state();
		JUTFont::initialize_state();
		mValid = 0;
	}
	return cVar1 != '\0';
}

int JUTResFont::isLeadByte(int param_1) {
	return this->mpEncodingFunc(param_1);
}

JUTResFont::JUTResFont() : JUTFont() {
	initialize_state();
	JUTFont::initialize_state();
}

JUTResFont::JUTResFont(ResFONT *param_1, JKRHeap *param_2) : JUTFont() {
	initialize_state();
	initiate(param_1, param_2);
}

void JUTResFont::loadFont(int code, gx::GXTexMapID texMapID, TWidth *pDstWidth) {
	uint uVar1;

	if (pDstWidth) {
		getWidthEntry(code, pDstWidth);
	}
	uVar1 = getFontCode(code);
	loadImage(uVar1, texMapID);
}

void JUTResFont::loadImage(int param_1, gx::GXTexMapID param_2) {
	int iVar1;
	uint uVar2;
	int iVar3;
	int iVar4;
	uint uVar5;
	int iVar6;
	uint uVar7;

	uVar7 = 0;
	iVar1 = 0;
	uVar2 = (uint)this->mNumGlyph;
	do {
		if (uVar2 == 0) {
		LAB_802c314c:
			if (uVar7 != this->mNumGlyph) {
				iVar1 = uVar7 * 4;
				iVar4 = *(int *)(this->mpGlyph + iVar1);
				uVar2 = (uint) * (ushort *)(iVar4 + 0x16);
				iVar3 = uVar2 * *(ushort *)(iVar4 + 0x18);
				uVar5 = param_1 / iVar3;
				iVar3 = param_1 - uVar5 * iVar3;
				iVar6 = iVar3 / (int)uVar2;
				this->somevert = (iVar3 - iVar6 * uVar2) * (uint) * (ushort *)(iVar4 + 0xc);
				this->somevert2 = iVar6 * (uint) * (ushort *)(*(int *)(this->mpGlyph + iVar1) + 0xe);
				if ((uVar5 != this->glyphTexPtr) || (uVar7 != this->glyphidx)) {
					iVar1 = *(int *)(this->mpGlyph + iVar1);
					gx::GXInitTexObj(&this->mTexObj, (void *)(iVar1 + uVar5 * *(int *)(iVar1 + 0x10) + 0x20),
									 (uint) * (ushort *)(iVar1 + 0x1a), (uint) * (ushort *)(iVar1 + 0x1c),
									 (gx::GXTexFmt) * (undefined2 *)(iVar1 + 0x14), gx::GX_CLAMP, gx::GX_CLAMP, false);
					gx::GXInitTexObjLOD(&mTexObj, gx::GXTexFilter::GX_LINEAR,
										gx::GXTexFilter::GX_LINEAR,
										0.0, 0.0, 0.0, 0, '\0',
										gx::GXAnisotropy::GX_ANISO_1);
					this->glyphTexPtr = uVar5;
					this->glyphidx = (ushort)uVar7;
				}
				gx::GXLoadTexObj(&this->mTexObj, param_2);
			}
			return;
		}
		iVar3 = *(int *)(this->mpGlyph + iVar1);
		uVar5 = (uint) * (ushort *)(iVar3 + 8);
		if (((int)uVar5 <= param_1) && (param_1 <= (int)(uint) * (ushort *)(iVar3 + 10))) {
			param_1 = param_1 - uVar5;
			goto LAB_802c314c;
		}
		uVar7 = uVar7 + 1;
		iVar1 = iVar1 + 4;
		uVar2 = uVar2 - 1;
	} while (true);
}

undefined4 JUTResFont::protected_initiate(ResFONT *param_1, JKRHeap *param_2) {
	undefined4 uVar1;
	void *pvVar2;
	ResFONT__MAP1 **ppRVar3;

	deleteMemBlocks_ResFont();
	initialize_state();
	initialize_state();
	if (param_1 == (ResFONT *)0x0) {
		uVar1 = 0;
	} else {
		this->mpResFONT = param_1;
		mValid = 1;
		countBlock();
		//pvVar2 = (void *)JKernel::operator_new[](((uint)this->mNumWidth + (uint)this->mNumGlyph + (uint)this->mNumMap) * 4, param_2, 0);
		pvVar2 = new (param_2, 0) char[((uint)this->mNumWidth + (uint)this->mNumGlyph + (uint)this->mNumMap) * 4];
		this->mpMemBlock = pvVar2;
		ppRVar3 = (ResFONT__MAP1 **)this->mpMemBlock;
		if (ppRVar3 == (ResFONT__MAP1 **)0x0) {
			uVar1 = 0;
		} else {
			if (this->mNumWidth != 0) {
				this->mpWidth = ppRVar3;
				ppRVar3 = ppRVar3 + this->mNumWidth;
			}
			if (this->mNumGlyph != 0) {
				this->mpGlyph = (byte *)ppRVar3;
				ppRVar3 = ppRVar3 + this->mNumGlyph;
			}
			if (this->mNumMap != 0) {
				this->mpMAP1 = ppRVar3;
			}
			setBlock();
			uVar1 = 1;
		}
	}
	return uVar1;
}

void JUTResFont::setBlock() {
	ushort uVar1;
	ulong uVar2;
	int iVar3;
	uint uVar4;
	int iVar5;
	int iVar6;
	int iVar7;
	uint uVar8;
	ResFONT *pRVar9;

	iVar7 = 0;
	iVar6 = 0;
	iVar5 = 0;
	this->mMaxGlyph = byteswap(-1);
	pRVar9 = this->mpResFONT + 1;
	uVar8 = 0;
	do {
		if (byteswap(this->mpResFONT->mBlockNum) <= uVar8) {
			return;
		}
		iVar3 = *(int *)pRVar9->mMagic;
		
		int a = byteswap(iVar3);
		switch (a) {
		case 0x4d415031:
			this->mpMAP1[iVar5] = (ResFONT__MAP1 *)pRVar9;
			uVar1 = byteswap(*(ushort *)((int *)this->mpMAP1[iVar5] + 10));
			if (uVar1 < (ushort)byteswap(this->mMaxGlyph)) {
				this->mMaxGlyph = byteswap(uVar1);
			}
			iVar5++;
			break;
		case 0x494e4631:
			this->mpINF1 = (ResFONT__INF1 *)pRVar9;
			uVar4 = (uint)(ushort)byteswap(this->mpINF1->mFontEncoding);
			if (2 < uVar4) {
				JUTAssertion::getSDevice()->showAssert("JUTResFont.cpp", 0xf3, "u < suAboutEncoding_");
				m_Do_printf::OSPanic("JUTResFont.cpp", 0xf3, "Halt");
			}
			this->mpEncodingFunc = saoAboutEncoding_[uVar4];
			break;
		case 0x57494431:
			*(ResFONT **)(this->mpWidth + iVar7) = pRVar9;
			iVar7 = iVar7 + 4;
			break;
		case 0x474c5931:
			*(ResFONT **)(this->mpGlyph + iVar6) = pRVar9;
			iVar6 = iVar6 + 4;
			break;
		default:
			JUtility::JUTReportConsole("Unknown data block\n");
		}
		// TODO: check this
		pRVar9 = (ResFONT *)(pRVar9->mMagic + byteswap(*(int *)pRVar9->mVersion));
		uVar8 = uVar8 + 1;
	} while (true);
}

void JUTResFont::setGX(TColor param_1, TColor param_2) {
	using namespace gx;
	gx::GXColor local_18;
	gx::GXColor local_14[3];

	if ((param_1->rgba == 0) && (param_2->rgba == ~0)) {
		setGX();
	} else {
		gx::GXSetNumChans(1);
		gx::GXSetNumTevStages(2);
		gx::GXSetNumTexGens(1);
		gx::GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
		gx::GXSetChanCtrl(GX_COLOR0A0, false, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);
		local_14[0] = *(gx::GXColor *)param_1;
		gx::GXSetTevColor(GX_TEVREG0, *local_14);
		local_18 = *(gx::GXColor *)param_2;
		gx::GXSetTevColor(GX_TEVREG1, local_18);
		gx::GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_C0, GX_CC_C1, GX_CC_TEXC, GX_CC_ZERO);
		gx::GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_A0, GX_CA_A1, GX_CA_TEXA, GX_CA_ZERO);
		gx::GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
		gx::GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_CPREV, GX_CC_RASC, GX_CC_ZERO);
		gx::GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_APREV, GX_CA_RASA, GX_CA_ZERO);
		gx::GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
		gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_RGBA4, 0);
		gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
		gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_CLR_RGBA, GX_RGBX8, 0xf);
		gx::GXClearVtxDesc();
		gx::GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		gx::GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
		gx::GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
	}
};
void JUTResFont::setGX() {
	using namespace gx;
	gx::GXSetNumChans(1);
	gx::GXSetNumTevStages(1);
	gx::GXSetNumTexGens(1);
	gx::GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
	gx::GXSetChanCtrl(GX_COLOR0A0, false, GX_SRC_REG, GX_SRC_VTX, 0, GX_DF_NONE, GX_AF_NONE);
	gx::GXSetTevOp(GXTevStageID::GX_TEVSTAGE0, GXTevMode::GX_MODULATE);
	gx::GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_CLR_RGBA, GX_RGBA4, 0);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
	gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_CLR_RGBA, GX_RGBX8, 0xf);
	gx::GXClearVtxDesc();
	gx::GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
	gx::GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
	gx::GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
}
