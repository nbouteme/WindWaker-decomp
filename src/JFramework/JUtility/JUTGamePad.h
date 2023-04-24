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

		void clear();

		CStick();

		uint getButton();

		uint update(char param_1, char param_2, EStickMode param_3, EWhichStick param_4);
	};

	struct CButton {
		CButton();

		uint mButtonDown, mButtonReleased, mButtonPressed;
		byte mAnalogARaw, mAnalogBRaw;
		byte mTriggerLeftRaw, mTriggerRightRaw;
		float mTriggerLeft, mTriggerRight;
		uint field9_0x18, field10_0x1c, field11_0x20, field12_0x24, field13_0x28, field14_0x2c;

		void setRepeat(ulong param_1, ulong param_2, ulong param_3);

		void clear();

		void update(pad::PADStatus *pPadStatus, ulong param_2);
	};

#define CONCAT22(a, b) b

	struct CRumble {
		static uint mEnabled;
		static byte *mStatus;

		void clear();

		void stopPatternedRumbleAtThePeriod();
		void triggerPatternedRumble(ulong param_1);

		void stopPatternedRumble(short param_1);

		void clear(JUTGamePad *param_1);

		void startMotor(int param_1);

		static void stopMotor(int param_1);

		void stopMotorHard(int index);

		void startPatternedRumble(byte *param_1, ERumble param_2, ulong param_3);

		static void setEnabled(ulong param_1);

		uint field0_0x0, field1_0x4;
		byte *field2_0x8;
		uint field3_0xc;

		void update(short param_1);
	};

	CButton mButton;
	CStick mStickMain, mStickC;
	CRumble mRumble;
	short mPortIdx;
	byte unk;
	JSUPtrLink mLink;

	static byte mPadAssign[4];

	virtual ~JUTGamePad();

	uint field_0x8c, field_0x90;
	byte field_0x98;

	static JSUPtrList mPadList;
	static byte mListInitialized;
	JUTGamePad *initList();

	struct C3ButtonReset {
		static const int sResetPattern;
		static const int sResetMaskPattern;
		static byte sResetSwitchPushing;
		static int sResetOccurredPort;
		static int sThreshold;
		static int sCallbackArg;
		static void (*sCallback)(int, uint);
		static int sResetOccurred;
	};

	static pad::PADStatus mPadStatus[4];
	static CButton mPadButton[4];
	static CStick mPadMStick[4], mPadSStick[4];
	byte field6_0x7a;
	long long field_0xa4;

	void checkResetCallback(long long param_2);

	void update();

	static int sAnalogMode;
	static int mSuppressPadReset;

	void assign();

	static void checkResetSwitch(void);

	static bool clearForReset(void);
	static JUTGamePad *getGamePad(int param_1);
	static bool recalibrate(long param_1);
	static void init(void);

	JUTGamePad(EPadPort param_1);
};