#pragma once

#include <JFramework/J2DGraph/J2DGrafContext.h>
#include <JFramework/J2DGraph/J2DOrthoGraph.h>
#include <dolphin/gx.h>

enum JUTFaderState {
	Ended,
	Skip,
	In,
	Out
};

struct JUTFader {
	JUTFaderState state;
	short duration;
	short currentFrame;
	gx::GXColor color;
	TBox2<float> boundingbox;
	uint field6_0x20;
	JUTFaderState field7_0x24;

	virtual void draw();

	JUTFader(int x, int y, int w, int h, TColor param_5);
	uint startFadeIn(int param_1);
	uint startFadeOut(int param_1);
	void control();
};