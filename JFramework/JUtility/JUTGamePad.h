#pragma once

#include <doltypes.h>

#include <cmath>

#define PAD_USESPEC

#include "../../dolphin/os.h"
#include "../../dolphin/pad.h"
#include "../JKernel/JKRDisposer.h"
#include "../JSupport/JSUPtrList.h"
#include "./JUtility.h"

using EStickMode = int;
using EWhichStick = int;
using ERumble = int;
using EPadPort = int;

struct JUTGamePad : public JKRDisposer {
	struct CStick {
		float mPosX;
		float mPosY;
		float mValue;
		short mAngle;
		byte mPosXRaw, mPosYRaw;

		void clear() {
			this->mPosX = 0.0;
			this->mPosY = 0.0;
			this->mValue = 0.0;
			this->mAngle = 0;
		}

		CStick() {
			clear();
		}

		uint getButton() {
			float fVar1;
			uint uVar2;

			uVar2 = 0;
			fVar1 = this->mPosX;
			if ((fVar1 <= -0.25) || (0.25 <= fVar1)) {
				if (-0.5 < fVar1) {
					if (0.5 <= fVar1) {
						uVar2 = 2;
					}
				} else {
					uVar2 = 1;
				}
			} else {
				uVar2 = 0;
			}
			fVar1 = this->mPosY;
			if ((fVar1 <= -0.25) || (0.25 <= fVar1)) {
				if (-0.5 < fVar1) {
					if (0.5 <= fVar1) {
						uVar2 = uVar2 | 8;
					}
				} else {
					uVar2 = uVar2 | 4;
				}
			}
			return uVar2;
		}

		uint update(char param_1, char param_2, EStickMode param_3, EWhichStick param_4) {
			float fVar1;
			float fVar2;
			uint uVar3;
			double dVar4;
			double local_18;

			uVar3 = 0x2a;
			if (param_4 == 0) {
				uVar3 = 0x36;
			}
			this->mPosXRaw = param_1;
			this->mPosYRaw = param_2;
			this->mPosX = ((float)param_1 / uVar3);
			local_18 = uVar3;
			this->mPosY = (float)param_2 / local_18;
			fVar1 = this->mPosX * this->mPosX + this->mPosY * this->mPosY;
			if (0.0 < fVar1) {
				fVar2 = 1.0 / sqrtf(fVar1);
				fVar2 = fVar2 * 0.5 * (3.0 - fVar1 * fVar2 * fVar2);
				fVar2 = fVar2 * 0.5 * (3.0 - fVar1 * fVar2 * fVar2);
				fVar1 = fVar1 * fVar2 * 0.5 * (3.0 - fVar1 * fVar2 * fVar2);
			}
			this->mValue = fVar1;
			if (1.0 < this->mValue) {
				if (param_3 == 1) {
					this->mPosX = this->mPosX / this->mValue;
					this->mPosY = this->mPosY / this->mValue;
				}
				this->mValue = 1.0;
			}
			if (this->mValue < 0.0) {
				if ((double)this->mPosY == 0.0) {
					if (this->mPosX <= 0.0) {
						this->mAngle = -0x4000;
					} else {
						this->mAngle = 0x4000;
					}
				} else {
					dVar4 = atan2((double)this->mPosX, -(double)this->mPosY);
					this->mAngle = (short)(int)((float)dVar4 * 10430.38);
				}
			}
			return getButton();
		}
	};

	struct CButton {
		CButton() {
			clear();
		}

		uint mButtonDown, mButtonReleased, mButtonPressed;
		byte mAnalogARaw, mAnalogBRaw;
		byte mTriggerLeftRaw, mTriggerRightRaw;
		float mTriggerLeft, mTriggerRight;
		uint field9_0x18, field10_0x1c, field11_0x20, field12_0x24, field13_0x28, field14_0x2c;

		void setRepeat(ulong param_1, ulong param_2, ulong param_3) {
			this->field11_0x20 = 0;
			this->field10_0x1c = 0;
			this->field12_0x24 = param_1;
			this->field13_0x28 = param_2;
			this->field14_0x2c = param_3;
		}

		void clear() {
			this->mButtonDown = 0;
			this->mButtonReleased = 0;
			this->mButtonPressed = 0;
			this->field9_0x18 = 0;
			this->mAnalogARaw = 0;
			this->mAnalogBRaw = 0;
			this->mTriggerLeftRaw = 0;
			this->mTriggerRightRaw = 0;
			this->field10_0x1c = 0;
			this->field11_0x20 = 0;
			this->field12_0x24 = 0;
			this->field13_0x28 = 0;
			this->field14_0x2c = 0;
		}

		void update(pad::PADStatus *pPadStatus, ulong param_2) {
			uint uVar1;
			uint uVar2;
			uint uVar3;
			uint uVar4;

			if (pPadStatus == nullptr) {
				uVar1 = 0;
			} else {
				uVar1 = (uint)pPadStatus->button;
			}
			uVar1 = param_2 | uVar1;
			this->field9_0x18 = 0;
			if (this->field13_0x28 != 0) {
				if (this->field12_0x24 != 0) {
					uVar4 = uVar1 & this->field12_0x24;
					this->field9_0x18 = 0;
					if (uVar4 == 0) {
						this->field11_0x20 = 0;
						this->field10_0x1c = 0;
					} else if (this->field11_0x20 == uVar4) {
						this->field10_0x1c = this->field10_0x1c + 1;
						uVar3 = this->field10_0x1c;
						uVar2 = this->field13_0x28;
						if ((uVar3 == uVar2) ||
							((uVar2 < uVar3 &&
							  (uVar3 - uVar2 == ((uVar3 - uVar2) / this->field14_0x2c) * this->field14_0x2c)))) {
							this->field9_0x18 = uVar4;
						}
					} else {
						this->field9_0x18 = uVar4 & (this->field11_0x20 ^ 0xffffffff);
						this->field11_0x20 = uVar4;
						this->field10_0x1c = 0;
					}
				}
			}
			this->mButtonReleased = uVar1 & (uVar1 ^ this->mButtonDown);
			this->mButtonPressed = this->mButtonDown & (uVar1 ^ this->mButtonDown);
			this->mButtonDown = uVar1;
			this->field9_0x18 = this->field9_0x18 | (this->field12_0x24 ^ 0xffffffff) & this->mButtonReleased;
			if (!pPadStatus) {
				this->mAnalogARaw = 0;
				this->mAnalogBRaw = 0;
				this->mTriggerLeftRaw = 0;
				this->mTriggerRightRaw = 0;
			} else {
				this->mAnalogARaw = pPadStatus->analogA;
				this->mAnalogBRaw = pPadStatus->analogB;
				this->mTriggerLeftRaw = pPadStatus->triggerLeft;
				this->mTriggerRightRaw = pPadStatus->triggerRight;
			}
			this->mTriggerLeft = (double)this->mTriggerLeftRaw / 150.0;
			this->mTriggerRight = (double)this->mTriggerRightRaw / 150.0;
		}
	};

#define CONCAT22(a, b) b

	struct CRumble {
		static uint mEnabled;
		static byte *mStatus;

		void clear() {
			this->field0_0x0 = 0;
			this->field1_0x4 = 0;
			this->field2_0x8 = (byte *)0x0;
			this->field3_0xc = 0;
			mEnabled = -0x10000000;
		}

		void stopPatternedRumbleAtThePeriod() {
			uint uVar1;
			uint uVar2;

			uVar2 = this->field3_0xc;
			uVar1 = this->field0_0x0 + (uVar2 - 1);
			this->field1_0x4 = uVar1 - (uVar1 / uVar2) * uVar2;
		}
		void triggerPatternedRumble(ulong param_1) {
			if (this->field2_0x8 == (byte *)0x0) {
			}
			if (this->field3_0xc == 0) {
			}
			this->field1_0x4 = param_1;
			this->field0_0x0 = 0;
		}

		void stopPatternedRumble(short param_1) {
			this->field1_0x4 = 0;
			stopMotorHard((int)param_1);
		}

		void clear(JUTGamePad *param_1) {
			int iVar1;

			iVar1 = (int)param_1->mPortIdx;
			if ((-1 < iVar1) && (iVar1 < 4)) {
				mStatus[iVar1] = 0;
				stopMotorHard((int)param_1->mPortIdx);
			}
			clear();
		}

		void startMotor(int param_1) {
			//if ((mEnabled & JUtility::channel_mask[(int)this]) != 0) {
			//	pad::PADControlMotor(1);
			//	mStatus = 1;
			//}
		}

		void stopMotor(int param_1) {
			//if ((mEnabled & JUtility::channel_mask[(int)this]) != 0) {
			//	pad::PADControlMotor(0);
			//	*(undefined *)&this[-0x7fc0879].field3_0xc = 0;
			//}
		}

		void stopMotorHard(int index) {
			//if ((mEnabled & JUtility::channel_mask[index]) != 0) {
			//	pad::PADControlMotor(index, 2);
			//	mStatus[index] = 0;
			//}
		}

		void startPatternedRumble(byte *param_1, ERumble param_2, ulong param_3) {
			this->field3_0xc = (uint)*param_1 * 0x100 + (uint)param_1[1];
			this->field2_0x8 = param_1 + 2;
			if (param_2 == 1) {
				triggerPatternedRumble(0xffffffff);
			} else if ((int)param_2 < 1) {
				if (-1 < (int)param_2) {
					triggerPatternedRumble(this->field3_0xc);
				}
			} else if ((int)param_2 < 3) {
				triggerPatternedRumble(param_3);
			}
		}

		void setEnabled(ulong param_1) {
			ulong extraout_r4;
			CRumble *this_00;
			int iVar1;
			byte *pbVar2;

			//this_00 = (CRumble *)0x0;
			//iVar1 = 0;
			//pbVar2 = mStatus;
			//do {
			//	if ((mEnabled & *(uint *)((int)JUtility::channel_mask + iVar1)) == 0) {
			//		if (*pbVar2 != 0) {
			//			stopMotor(param_1);
			//		}
			//		param_1 = getGamePad((int)this_00);
			//		if (param_1 != 0) {
			//			stopPatternedRumble((CRumble *)(param_1 + 0x68), *(short *)(param_1 + 0x78));
			//			param_1 = extraout_r4;
			//		}
			//	}
			//	this_00 = (CRumble *)((int)&this_00->field0_0x0 + 1);
			//	pbVar2 = pbVar2 + 1;
			//	iVar1 = iVar1 + 4;
			//} while ((int)this_00 < 4);
			//mEnabled = (uint)this & 0xf0000000;
		}

		uint field0_0x0, field1_0x4;
		byte *field2_0x8;
		uint field3_0xc;

		void update(short param_1) {
			uint uVar1;
			undefined2 in_register_00000010;
			uint uVar2;

			if ((mEnabled & JUtility::channel_mask[param_1]) == 0) {
				this->field0_0x0 = 0;
				this->field1_0x4 = 0;
				this->field2_0x8 = (byte *)0x0;
				this->field3_0xc = 0;
			}
			if (this->field1_0x4 != 0) {
				uVar2 = this->field0_0x0;
				if (uVar2 < this->field1_0x4) {
					uVar1 = this->field3_0xc;
					if (uVar1 == 0) {
						if (mStatus[param_1] != 0) {
						}
						((CRumble *)(int)param_1)->startMotor(CONCAT22(in_register_00000010, param_1));
					}
					uVar2 = uVar2 - (uVar2 / uVar1) * uVar1;
					uVar2 = 0x80 >> (uVar2 & 7) & (uint)this->field2_0x8[uVar2 >> 3];
					if ((uVar2 == 0) || (mStatus[param_1] != 0)) {
						if ((uVar2 == 0) && (mStatus[param_1] != 0)) {
							stopMotorHard((int)param_1);
						}
					} else {
						((CRumble *)(int)param_1)->startMotor(CONCAT22(in_register_00000010, param_1));
					}
				} else {
					stopMotorHard((int)param_1);
					this->field1_0x4 = 0;
				}
				this->field0_0x0 = this->field0_0x0 + 1;
			}
		}
	};

	CButton mButton;
	CStick mStickMain, mStickC;
	CRumble mRumble;
	short mPortIdx;
	byte unk;
	JSUPtrLink mLink;

	static byte mPadAssign[4];

	virtual ~JUTGamePad() {
		if (mPortIdx != -1) {
			mPadAssign[mPortIdx] -= 1;
			mPortIdx = -1;
		}
	}

	uint field_0x8c, field_0x90;
	byte field_0x98;

	static JSUPtrList mPadList;
	static byte mListInitialized;
	JUTGamePad *initList() {
		if (!mListInitialized) {
			mPadList.initiate();
			mListInitialized = 1;
		}
		return this;
	}

	struct C3ButtonReset {
		static const int sResetPattern = 0x1600;
		static const int sResetMaskPattern = 0xFFFF;
		static byte sResetSwitchPushing;
		static int sResetOccurredPort;
		static int sThreshold;
		static int sCallbackArg;
		static void *(*sCallback)(uint, uint);
		static int sResetOccurred;
	};

	static pad::PADStatus mPadStatus[4];
	static CButton mPadButton[4];
	static CStick mPadMStick[4], mPadSStick[4];
	byte field6_0x7a;
	long long field_0xa4;

	void checkResetCallback(long long param_2)

	{
		if (-1 < this->mPortIdx) {
			const int BUSCLOCKSPEED = 162000000;
			const int dat = ((BUSCLOCKSPEED >> 2) / 0x3c) * 0x1e;
			if (param_2 < dat + (JUTGamePad::C3ButtonReset::sThreshold ^ 0x80000000U) <= ((uint)(param_2 >> 0x20) ^ 0x80000000)) {
				JUTGamePad::C3ButtonReset::sResetOccurred = 1;
				JUTGamePad::C3ButtonReset::sResetOccurredPort = (int)this->mPortIdx;
				if (JUTGamePad::C3ButtonReset::sCallback) {
					(C3ButtonReset::sCallback)((int)this->mPortIdx, JUTGamePad::C3ButtonReset::sCallbackArg);
				}
			}
		}
		return;
	}

	void update() {
		short sVar1;
		int iVar2;
		long long lVar3;

		iVar2 = (int)this->mPortIdx;
		if (iVar2 != -1) {
			(this->mButton).mButtonDown = JUTGamePad::mPadButton[iVar2].mButtonDown;
			(this->mButton).mButtonReleased = JUTGamePad::mPadButton[iVar2].mButtonReleased;
			(this->mButton).mButtonPressed = JUTGamePad::mPadButton[iVar2].mButtonPressed;
			(this->mButton).mAnalogARaw = JUTGamePad::mPadButton[iVar2].mAnalogARaw;
			(this->mButton).mAnalogBRaw = JUTGamePad::mPadButton[iVar2].mAnalogBRaw;
			(this->mButton).mTriggerLeftRaw = JUTGamePad::mPadButton[iVar2].mTriggerLeftRaw;
			(this->mButton).mTriggerRightRaw = JUTGamePad::mPadButton[iVar2].mTriggerRightRaw;
			(this->mButton).mTriggerLeft = JUTGamePad::mPadButton[iVar2].mTriggerLeft;
			(this->mButton).mTriggerRight = JUTGamePad::mPadButton[iVar2].mTriggerRight;
			(this->mButton).field9_0x18 = JUTGamePad::mPadButton[iVar2].field9_0x18;
			(this->mButton).field10_0x1c = JUTGamePad::mPadButton[iVar2].field10_0x1c;
			(this->mButton).field11_0x20 = JUTGamePad::mPadButton[iVar2].field11_0x20;
			(this->mButton).field12_0x24 = JUTGamePad::mPadButton[iVar2].field12_0x24;
			(this->mButton).field13_0x28 = JUTGamePad::mPadButton[iVar2].field13_0x28;
			(this->mButton).field14_0x2c = JUTGamePad::mPadButton[iVar2].field14_0x2c;
			sVar1 = this->mPortIdx;
			(this->mStickMain).mPosX = JUTGamePad::mPadMStick[sVar1].mPosX;
			(this->mStickMain).mPosY = JUTGamePad::mPadMStick[sVar1].mPosY;
			(this->mStickMain).mValue = JUTGamePad::mPadMStick[sVar1].mValue;
			(this->mStickMain).mAngle = JUTGamePad::mPadMStick[sVar1].mAngle;
			(this->mStickMain).mPosXRaw = JUTGamePad::mPadMStick[sVar1].mPosXRaw;
			(this->mStickMain).mPosYRaw = JUTGamePad::mPadMStick[sVar1].mPosYRaw;
			sVar1 = this->mPortIdx;
			(this->mStickC).mPosX = JUTGamePad::mPadSStick[sVar1].mPosX;
			(this->mStickC).mPosY = JUTGamePad::mPadSStick[sVar1].mPosY;
			(this->mStickC).mValue = JUTGamePad::mPadSStick[sVar1].mValue;
			(this->mStickC).mAngle = JUTGamePad::mPadSStick[sVar1].mAngle;
			(this->mStickC).mPosXRaw = JUTGamePad::mPadSStick[sVar1].mPosXRaw;
			(this->mStickC).mPosYRaw = JUTGamePad::mPadSStick[sVar1].mPosYRaw;
			this->field6_0x7a = mPadStatus[this->mPortIdx].err;
			if (C3ButtonReset::sResetPattern == ((this->mButton).mButtonDown & C3ButtonReset::sResetMaskPattern)) {
				if (JUTGamePad::C3ButtonReset::sResetOccurred == '\0') {
					if (this->field_0x98 == '\x01') {
						lVar3 = os::OSGetTime();
						checkResetCallback(lVar3);
					} else {
						this->field_0x98 = 1;
						lVar3 = os::OSGetTime();
						this->field_0xa4 = lVar3;
					}
				}
			} else {
				this->field_0x98 = 0;
			}
			this->mRumble.update(this->mPortIdx);
		}
	}

	static int sAnalogMode;
	static int mSuppressPadReset;

	void assign()

	{
		int iVar1;
		byte *pbVar2;
		int iVar3;
		int iVar4;

		iVar3 = 0;
		iVar1 = 0;
		pbVar2 = JUTGamePad::mPadAssign;
		iVar4 = 4;
		while (((&JUTGamePad::mPadStatus[0].err)[iVar1] != 0 || (*pbVar2 != 0))) {
			iVar3 = iVar3 + 1;
			pbVar2 = pbVar2 + 1;
			iVar1 = iVar1 + 0xc;
			iVar4 = iVar4 + -1;
			if (iVar4 == 0) {
				return;
			}
		}
		this->mPortIdx = (short)iVar3;
		JUTGamePad::mPadAssign[iVar3] = 1;
		JUTGamePad::mPadButton[mPortIdx].setRepeat((this->mButton).field12_0x24,
												   (this->mButton).field13_0x28, (this->mButton).field14_0x2c);
		this->mRumble.clear(this);
	}

	static JUTGamePad *checkResetSwitch(void) {
		JUTGamePad *in_r3;

		if (C3ButtonReset::sResetOccurred == '\0') {
			if (!os::OSGetResetSwitchState()) {
				if (C3ButtonReset::sResetSwitchPushing == '\x01') {
					C3ButtonReset::sResetOccurred = '\x01';
					C3ButtonReset::sResetOccurredPort = -1;
					if (C3ButtonReset::sCallback) {
						in_r3 = (JUTGamePad *)C3ButtonReset::sCallback(0xffffffff, JUTGamePad::C3ButtonReset::sCallbackArg);
					}
				}
				C3ButtonReset::sResetSwitchPushing = '\0';
			} else {
				C3ButtonReset::sResetSwitchPushing = '\x01';
			}
		}
		return in_r3;
	}

	static bool clearForReset(void)

	{
		bool bVar1;
		ulong in_r4;

		((CRumble *)0x0)->setEnabled(0);
		bVar1 = JUTGamePad::recalibrate(0xf0000000);
		return bVar1;
	}

	static int getGamePad(int param_1)

	{
		JSUPtrLink *pJVar1;

		pJVar1 = JUTGamePad::mPadList.mpHead;
		while (true) {
			if (pJVar1 == (JSUPtrLink *)0x0) {
				return 0;
			}
			if (param_1 == *(short *)(pJVar1->mpData + 0x78))
				break;
			pJVar1 = pJVar1->mpNext;
		}
		return (int)pJVar1->mpData;
	}

	static bool JUTGamePad::recalibrate(long param_1) {
		int iVar1;
		int iVar2;
		undefined1 *local_18[6];

		local_18[0] = (undefined1 *)0x80000000;
		local_18[1] = (undefined1 *)0x40000000;
		local_18[2] = (undefined1 *)0x20000000;
		local_18[3] = (undefined1 *)0x10000000;
		iVar1 = 0;
		iVar2 = 4;
		do {
			if ((mSuppressPadReset & *(uint *)((int)local_18 + iVar1)) != 0) {
				param_1 = param_1 & (*(uint *)((int)local_18 + iVar1) ^ 0xffffffff);
			}
			iVar1 = iVar1 + 4;
			iVar2 = iVar2 + -1;
		} while (iVar2 != 0);
		iVar1 = pad::PADRecalibrate(param_1);
		return iVar1 != 0;
	}

	static void init(void)

	{
		pad::PADSetSpec(5);
		JUTGamePad::sAnalogMode = 3;
		pad::PADSetAnalogMode(3);
		pad::PADInit();
		return;
	}

	JUTGamePad(EPadPort param_1) : JKRDisposer(), mLink(this) {
		mButton.clear();
		mStickMain.clear();
		mStickC.clear();
		mRumble.clear(this);
		this->field_0x98 = 0;
		this->mPortIdx = (short)param_1;
		mPadAssign[param_1] = mPadAssign[param_1] + 1;
		initList();
		mPadList.append(&this->mLink);
		update();
		this->field_0x8c = 0;
		this->field_0x90 = 0;
	}

};