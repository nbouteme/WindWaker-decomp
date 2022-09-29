#pragma once

#include <JFramework/JKernel/JKernel.h>
#include <JFramework/JUtility/JUTGamePad.h>
#include <doltypes.h>

#include "main.h"
#include "rst.h"

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
	JUTGamePad *g_mDoCPd_gamePad[4];
	interface_of_controller_pad g_mDoCPd_cpadInfo[4];

	undefined4 mDoCPd_Create(void) {
		JUTGamePad *pJVar1;
		int *self;
		int iVar2;
		int iVar3;

		JUTGamePad::mSuppressPadReset = 1;
		pJVar1 = new JUTGamePad(0);

		g_mDoCPd_gamePad[1] = nullptr;
		g_mDoCPd_gamePad[0] = pJVar1;
		if (mDoMain::developmentMode == '\0') {
			g_mDoCPd_gamePad[2] = nullptr;
			g_mDoCPd_gamePad[3] = nullptr;
			pJVar1 = g_mDoCPd_gamePad[3];
		} else {
			g_mDoCPd_gamePad[2] = new JUTGamePad(2);
			pJVar1 = new JUTGamePad(3);
		}
		g_mDoCPd_gamePad[3] = pJVar1;
		JUTGamePad::sAnalogMode = 3;
		pad::PADSetAnalogMode(3);
		self = mDoRst::mResetData;
		if (*mDoRst::mResetData == 0) {
			JUTGamePad::C3ButtonReset::sResetOccurred = 0;
			JUTGamePad::C3ButtonReset::sCallback = m_Do_Reset::mDoRst_resetCallBack;
			JUTGamePad::C3ButtonReset::sCallbackArg = 0;
		}
		//JUTGba::create();
		//mDoGaC_agbCom_c::mDoGaC_Initial((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,
		//								(mDoGaC_DataManag_c *)&m_Do_ext::m_Do_gba_com::TestDataManager, '\x10');
		iVar2 = 0;
		iVar3 = 4;
		do {
			(g_mDoCPd_cpadInfo[iVar2].mTriggerLeftEdge) = 0;
			(g_mDoCPd_cpadInfo[iVar2].mTriggerLeftLevel) = 0;
			(g_mDoCPd_cpadInfo[iVar2].mTriggerRightEdge) = 0;
			(g_mDoCPd_cpadInfo[iVar2].mTriggerRightLevel) = 0;
			iVar2++;
			iVar3 = iVar3 + -1;
		} while (iVar3 != 0);
		return 1;
	}

	void mDoCPd_Read() {
		
	}

}
