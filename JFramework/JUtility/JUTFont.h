#pragma once

#include "../J2DGraph/J2DGrafContext.h"
#include "../JKernel/JKernel.h"

struct ResFONT {
	char mMagic[4], mVersion[4];
	uint mTotalSize;
	uint mBlockNum;
	byte mPadding[16];
};

struct ResFONT__INF1 {
	char mMagic[4];
	int mSize;
	short mFontEncoding;
	short mAscent;
	short mDescent;
	ushort mFallbackWidth;
	ushort mFallbackLeading;
	ushort mFallbackCode;
};

struct ResFONT__MAP1 {
	char mMagic[4];
	int mSize;
	ushort mType, mMinGlyph, mMaxGlyph;
};

struct JUTFont {
	struct TWidth {
		byte field0_0x0, mAdvance;
	};
	//using TWidth = uint;

	byte mValid, ignoreKerning;
	int mWidth;
	gx::GXColor somecolor, somecolor2, somecolor4, somecolor3;

	void setCharColor(gx::GXColor *pColor);

	void initialize_state();

	virtual ~JUTFont();

	virtual void setGX(TColor, TColor);
	virtual void setGX() = 0;

	virtual float drawChar_scale(float, float, float, float, int, bool) = 0;
	virtual ushort getLeading() = 0;
	virtual ushort getAscent() = 0;
	virtual ushort getDescent() = 0;
	virtual int getHeight() = 0;
	virtual short getWidth() = 0;
	virtual void getWidthEntry(int, TWidth *) = 0;
	virtual uint getCellWidth();

	virtual uint getCellHeight();
	virtual short getFontType() = 0;
	virtual ResFONT *getResFont() = 0;
	virtual int isLeadByte(int) = 0;
	virtual void loadImage(int, gx::GXTexMapID) = 0;
	virtual void setBlock() = 0;

	float drawString_size_scale(float param_1, float param_2, float param_3, float param_4, char *param_5, ulong param_6, bool param_7);
};

using EncodingFunction = int(int);

struct JUTResFont : public JUTFont {
	int somevert, somevert2;
	gx::GXTexObj mTexObj;
	uint glyphTexPtr;
	ResFONT *mpResFONT;
	ResFONT__INF1 *mpINF1;
	void *mpMemBlock;
	void *mpWidth;
	byte *mpGlyph;
	ResFONT__MAP1 **mpMAP1;
	ushort mNumWidth, mNumGlyph, mNumMap, glyphidx;
	short mMaxGlyph;
	EncodingFunction *mpEncodingFunc;

	virtual ~JUTResFont();

	static int isLeadByte_1Byte(int param_1);

	static int isLeadByte_2Byte(int param_1);

	static int isLeadByte_ShiftJIS(int param_1);

	static EncodingFunction *saoAboutEncoding_[3];

	int getHeight();

	virtual float drawChar_scale(float param_1, float param_2, float param_3, float param_4, int param_5, bool param_6) override;

	void countBlock();

	int convertSjis(int param_1, ushort *param_2);

	void deleteMemBlocks_ResFont();

	ushort getAscent();

	uint getCellHeight();

	uint getCellWidth();

	ushort getDescent();

	short getFontType();

	ushort getLeading();

	ResFONT *getResFont();

	short getWidth();

	uint getFontCode(int code);

	void getWidthEntry(int code, TWidth *pWidth);

	void initialize_state();

	bool initiate(ResFONT *param_1, JKRHeap *param_2);

	int isLeadByte(int param_1);

	JUTResFont();

	JUTResFont(ResFONT *param_1, JKRHeap *param_2);

	void loadFont(int code, gx::GXTexMapID texMapID, TWidth *pDstWidth);

	void loadImage(int param_1, gx::GXTexMapID param_2);

	undefined4 protected_initiate(ResFONT *param_1, JKRHeap *param_2);

	void setBlock();

	virtual void setGX(TColor param_1, TColor param_2);
	virtual void setGX();
};