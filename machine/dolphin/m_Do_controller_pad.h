#pragma once

#include <JFramework/JUtility/JUTGamePad.h>
#include <doltypes.h>

struct interface_of_controller_pad {
	float mStickMainPosX;
	float mStickMainPosY;
	float mStickMainValue;
	short mStickMainAngle;
	float mStickCPosX;
	float mStickCPosY;
	float mStickCValue;
	short mStickCAngle;
	float mAnalogA;
	float mAnalogB;
	float mTriggerLeft;
	float mTriggerRight;
	byte mButton0;
	byte mButton1;
	byte mButton2;
	byte mButton3;
	byte mTriggerLeftLevel;
	byte mTriggerLeftEdge;
	byte mTriggerRightLevel;
	byte mTriggerRightEdge;
};

namespace m_Do_controller_pad {
	extern JUTGamePad *g_mDoCPd_gamePad[4];
	extern interface_of_controller_pad g_mDoCPd_cpadInfo[4];

	undefined4 mDoCPd_Create(void);
	void mDoCPd_Read();
}
