#pragma once

#include <dolphin/gx.h>
#include <machine/dolphin/printf.h>

struct ResTLUT { // Most likely belongs in machine/dolphin/graphics
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

	bool load();

	void storeTLUT(gx::GXTlut param_1, gx::GXTlutFmt param_2, JUTTransparency param_3, ushort param_4, void *param_5);

	void storeTLUT(gx::GXTlut param_1, ResTLUT *param_2);
};