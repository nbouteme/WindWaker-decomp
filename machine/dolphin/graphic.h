#pragma once

#include <JFramework/JUtility/JUTGamePad.h>
#include <dDlst.h>
#include <dolphin/gx.h>
#include <doltypes.h>

#include "dComIfG_inf_c.h"
#include "machine.h"

namespace mDoGph_gInf_c {
	extern gx::GXColor mBackColor;
	extern gx::GXColor mFadeColor;

}

namespace m_Do_graphic {

	int mDoGph_Create();

	void mDoGph_BlankingON() {}
	void mDoGph_BlankingOFF() {}

	void mDoGph_Painter() {
		//TODO
	}

	void m_Do_graphic::dScnPly_BeforeOfPaint(void) {
		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.reset();
	}

	undefined4 m_Do_graphic::mDoGph_BeforeOfDraw(void) {
		m_Do_graphic::dScnPly_BeforeOfPaint();
		return 1;
	}

	undefined4 m_Do_graphic::mDoGph_AfterOfDraw(void);
}