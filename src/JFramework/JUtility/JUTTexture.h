#pragma once

#include <dolphin/gx.h>

struct JUTPalette;
struct ResTIMG;

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

	int field13_0x3b = 0;

	void load(gx::GXTexMapID param_1);

	void attachPalette(JUTPalette *param_1);

	void initTexObj();

	void initTexObj(gx::GXTlut param_1);

	void storeTIMG(ResTIMG *param_1, uchar param_2);
};
