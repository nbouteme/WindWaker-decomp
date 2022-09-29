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

	JUTFader(int x, int y, int w, int h, TColor param_5) {
		this->color = *(gx::GXColor *)param_5;
		this->boundingbox.mTL[0] = x;
		this->boundingbox.mTL[1] = y;
		this->boundingbox.mBR[0] = x + w;
		this->boundingbox.mBR[1] = y + h;
		this->state = JUTFaderState::Ended;
		this->duration = 0;
		this->currentFrame = 0;
		this->field7_0x24 = JUTFaderState::Ended;
		this->field6_0x20 = 0xffffffff;
	}

	uint startFadeIn(int param_1) {
		if (!this->state) {
			this->state = JUTFaderState::In;
			this->currentFrame = 0;
			this->duration = param_1;
		}
		return !!this->state;
	}

	uint startFadeOut(int param_1) {
		uint uVar1;

		if (this->state) {
			this->state = JUTFaderState::Out;
			this->currentFrame = 0;
			this->duration = param_1;
		}
		return !this->state;
	}

	virtual void draw() {
		Color local_f8;

		if (this->color.a) {
			struct J2DOrthoGraph local_e4;
			local_f8.r = color.r;
			local_f8.g = color.g;
			local_f8.b = color.b;
			local_f8.a = color.a;

			local_e4.setColor(&local_f8, &local_f8, &local_f8, &local_f8);
			local_e4.fillBox(&this->boundingbox);
		}
		return;
	}

	void control() {
		int state;
		ushort uVar1;

		state = this->field6_0x20;
		if ((-1 < state) && (this->field6_0x20 = state + -1, state == 0)) {
			this->state = this->field7_0x24;
		}
		state = this->state;
		if (state != 1) {
			if (state == 2) {
				uVar1 = this->currentFrame + 1;
				this->currentFrame = uVar1;
				this->color.a = -1 - (char)(((uint)uVar1 * 0xff) / (uint)(ushort)this->duration);
				if ((ushort)this->duration <= (ushort)this->currentFrame) {
					this->state = JUTFaderState::Skip;
				}
			} else if (state < 2) {
				if (state == 0) {
					this->color.a = 0xff;
				}
			} else if (state < 4) {
				uVar1 = this->currentFrame + 1;
				this->currentFrame = uVar1;
				this->color.a = (char)(((uint)uVar1 * 0xff) / (uint)(ushort)this->duration);
				if ((ushort)this->duration <= (ushort)this->currentFrame) {
					this->state = JUTFaderState::Ended;
				}
			}
			/* draw */
			this->draw();
		}
	}
};